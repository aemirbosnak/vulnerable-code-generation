//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct CharCount {
    char c;
    int count;
} CharCount;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    size_t fileSize = 0;
    char *buffer = malloc(1024 * sizeof(char));
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    while (fread(buffer, sizeof(char), 1024, file) > 0) {
        fileSize += 1024;
        rewind(file);
    }
    rewind(file);

    CharCount *charCounts = malloc((unsigned int) (sizeof(CharCount) * 128));
    if (!charCounts) {
        perror("Error allocating memory");
        free(buffer);
        fclose(file);
        return 1;
    }

    memset(charCounts, 0, sizeof(CharCount) * 128);

    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, sizeof(char), 1024, file)) > 0) {
        for (int i = 0; i < bytesRead; ++i) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = tolower(c);
                int index = c - 'a';
                charCounts[index].count++;
            } else if (c == '\\' && i < bytesRead - 1 && isalnum(buffer[i + 1])) {
                int index = buffer[i + 1] - 'a';
                charCounts[index].count++;
                i++;
            } else {
                charCounts['?'].count++;
            }
        }
    }
    fclose(file);
    free(buffer);

    printf("Character frequencies:\n");
    for (int i = 0; i < 128; ++i) {
        if (charCounts[i].c == '\0') continue;
        printf("%c : %d\n", charCounts[i].c, charCounts[i].count);
    }

    free(charCounts);
    return 0;
}