//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_SIZE 50

typedef struct Word {
    char word[WORD_SIZE];
    int count;
} Word;

void toLowerCase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

int isDuplicate(Word words[], int size, char *word) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file;
    char filename[100], line[1024], word[WORD_SIZE];
    Word words[MAX_WORDS];
    int i, count = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        toLowerCase(line);
        sscanf(line, "%s%s", word, word + strlen(word) + 1);
        if (strlen(word) > 0 && strlen(word) < WORD_SIZE - 1) {
            if (isDuplicate(words, count, word)) continue;
            strcpy(words[count].word, word);
            words[count].count = 1;
            count++;
        }
    }

    fclose(file);

    printf("\nWord count:\n");
    for (i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}