//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int i, j, k, numWords;
    WordCount words[MAX_WORDS];

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    numWords = 0;
    while (fgets(line, sizeof(line), file)!= NULL) {
        i = 0;
        while (i < strlen(line)) {
            if (isspace(line[i])) {
                line[i] = '\0';
                word[k] = '\0';
                if (k > 0) {
                    for (j = 0; j < numWords; j++) {
                        if (strcmp(words[j].word, word) == 0) {
                            words[j].count++;
                            break;
                        }
                    }
                    if (j == numWords) {
                        if (numWords >= MAX_WORDS) {
                            printf("Too many words.\n");
                            return 1;
                        }
                        strcpy(words[numWords].word, word);
                        words[numWords].count = 1;
                        numWords++;
                    }
                }
                k = 0;
            } else {
                word[k++] = tolower(line[i]);
            }
            i++;
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}