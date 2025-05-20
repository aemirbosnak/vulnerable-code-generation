//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define WORD_LENGTH 10

typedef struct {
    char word[WORD_LENGTH];
    int count;
} Word;

int main() {
    char line[1000];
    char *word;
    FILE *file;
    int i, j, k, count;
    Word wordList[MAX_WORDS];

    printf("Enter the filename: ");
    scanf("%s", line);
    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    // Read the file and store words in the wordList
    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            count = 0;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(wordList[i].word, word) == 0) {
                    wordList[i].count++;
                    count = 1;
                    break;
                }
            }
            if (count == 0) {
                for (j = 0; j < MAX_WORDS; j++) {
                    if (wordList[j].word[0] == '\0') {
                        strcpy(wordList[j].word, word);
                        wordList[j].count = 1;
                        count = 1;
                        break;
                    }
                }
            }
            word = strtok(NULL, ",.!?;:");
        }
    }

    // Check spelling and output results
    while (fgets(line, sizeof(line), file)!= NULL) {
        word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            count = 0;
            for (i = 0; i < MAX_WORDS; i++) {
                if (strcmp(wordList[i].word, word) == 0) {
                    if (wordList[i].count > 1) {
                        printf("%s (repeated %d times)\n", word, wordList[i].count);
                    } else {
                        printf("%s\n", word);
                    }
                    count = 1;
                    break;
                }
            }
            if (count == 0) {
                printf("%s (not in dictionary)\n", word);
            }
            word = strtok(NULL, ",.!?;:");
        }
        printf("\n");
    }

    return 0;
}