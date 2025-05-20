//Falcon-180B DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wc1 = (WordCount *)a;
    WordCount *wc2 = (WordCount *)b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *file;
    char filename[100];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    char *token;
    int i, j, k, wordCount = 0;
    WordCount words[MAX_WORDS];

    srand(time(NULL));

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                line[i] = '\0';
            }
        }

        token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);

            for (j = 0; j < strlen(word); j++) {
                word[j] = toupper(word[j]);
            }

            for (k = 0; k < wordCount; k++) {
                if (strcmp(words[k].word, word) == 0) {
                    words[k].count++;
                    break;
                }
            }

            if (k == wordCount) {
                if (wordCount >= MAX_WORDS) {
                    printf("Error: maximum number of words reached.\n");
                    exit(1);
                }

                strcpy(words[wordCount].word, word);
                words[wordCount].count = 1;
                wordCount++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    qsort(words, wordCount, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}