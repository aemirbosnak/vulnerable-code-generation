//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} WordPair;

void loadWords(WordPair words[]) {
    FILE* file = fopen("words.txt", "r");
    if (!file) {
        printf("Error loading words file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", words[count].english, words[count].alien) == 2) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Too many words in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    WordPair words[MAX_WORDS];
    loadWords(words);

    char input[MAX_WORD_LENGTH];
    while (1) {
        printf("Enter an English word: ");
        scanf("%s", input);

        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(input, words[i].english) == 0) {
                printf("%s\n", words[i].alien);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Word not found.\n");
        }
    }

    return 0;
}