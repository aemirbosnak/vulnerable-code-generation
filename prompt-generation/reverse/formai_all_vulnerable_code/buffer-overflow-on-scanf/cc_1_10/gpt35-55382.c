//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100

void removeSpecial(char* s) {
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char fileName[50], word[MAX_WORD_SIZE], line[MAX_WORD_SIZE];
    int count = 0, state = 0, i, j;

    FILE *file;
    printf("Enter the file name: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not found!");
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {
        removeSpecial(line);
        for (i = 0; line[i] != '\0'; i++) {
            if (line[i] == ' ') {
                state = 0;
                count++;
            } else if (state == 0) {
                state = 1;
                for (j = 0; j < MAX_WORD_SIZE; j++) {
                    word[j] = '\0';
                }
                strcpy(word, &line[i]);
            } else {
                count++;
            }
        }
    }

    if (state == 1) {
        count++;
    }

    printf("There are %d words in the file.", count);

    fclose(file);
    return 0;
}