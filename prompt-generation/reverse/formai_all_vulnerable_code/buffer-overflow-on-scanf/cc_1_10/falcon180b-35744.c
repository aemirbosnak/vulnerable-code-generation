//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void word_frequency(char *filename) {
    FILE *fp;
    char word[MAX_WORD_LENGTH];
    char line[100];
    WordFrequency words[MAX_WORDS];
    int num_words = 0;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                word[0] = tolower(line[i]);
                int j = 1;
                while (isalpha(line[i + j])) {
                    word[j] = tolower(line[i + j]);
                    j++;
                }
                word[j] = '\0';

                for (int k = 0; k < num_words; k++) {
                    if (strcmp(words[k].word, word) == 0) {
                        words[k].count++;
                        break;
                    }
                }

                if (num_words < MAX_WORDS) {
                    strcpy(words[num_words].word, word);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    fclose(fp);

    printf("Word frequencies:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    word_frequency(filename);

    return 0;
}