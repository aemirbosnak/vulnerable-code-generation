//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 20

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);
        char *lineCopy = malloc(len + 1);
        strcpy(lineCopy, line);
        lineCopy[len] = '\0';

        word = strtok(lineCopy, ",.?!;:");
        while (word!= NULL) {
            int wordLen = strlen(word);
            if (wordLen > WORD_LENGTH) {
                printf("Warning: Word \"%s\" is too long and will be truncated.\n", word);
                word[WORD_LENGTH - 1] = '\0';
            }

            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords == MAX_WORDS) {
                    printf("Error: Too many unique words.\n");
                    return 1;
                }
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, ",.?!;:");
        }

        free(lineCopy);
    }

    fclose(file);

    printf("Total words: %d\n", numWords);

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}