//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(char *filename, WordCount *wordCounts) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (strlen(word) > MAX_WORD_LEN - 1) {
            printf("Warning: word '%s' exceeds maximum length of %d\n", word, MAX_WORD_LEN);
        } else {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                    break;
                }
            }
            if (i == strlen(word)) {
                printf("Error: word '%s' contains non-alphabetic characters\n", word);
            } else {
                int j;
                for (j = 0; j < MAX_WORDS; j++) {
                    if (strcmp(wordCounts[j].word, word) == 0) {
                        wordCounts[j].count++;
                        break;
                    } else if (strcmp(wordCounts[j].word, "") == 0) {
                        strcpy(wordCounts[j].word, word);
                        wordCounts[j].count = 1;
                        break;
                    }
                }
            }
        }
    }

    fclose(fp);
}

void printWordCounts(WordCount *wordCounts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(wordCounts[i].word, "")!= 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordCount wordCounts[MAX_WORDS];
    readWords(argv[1], wordCounts);
    printWordCounts(wordCounts);

    return 0;
}