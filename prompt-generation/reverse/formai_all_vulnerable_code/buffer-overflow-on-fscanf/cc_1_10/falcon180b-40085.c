//Falcon-180B DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void read_words(char* filename, WordCount* words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        bool found = false;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = true;
                break;
            }
        }

        if (!found) {
            strcpy(words[0].word, word);
            words[0].count = 1;
        }
    }

    fclose(file);
}

void print_word_counts(WordCount* words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    char filename[MAX_WORD_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    read_words(filename, words);

    printf("\nWord counts:\n");
    print_word_counts(words);

    return 0;
}