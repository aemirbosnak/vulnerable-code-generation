//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    unsigned int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[]) {
    char word[MAX_WORD_LENGTH];
    unsigned int frequency = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        bool found = false;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = true;
                break;
            }
        }

        if (!found) {
            strcpy(words[frequency].word, word);
            words[frequency].frequency = 1;
            frequency++;

            if (frequency >= MAX_WORDS) {
                break;
            }
        }
    }
}

void sortWords(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS - 1; i++) {
        for (int j = i + 1; j < MAX_WORDS; j++) {
            if (words[j].frequency > words[i].frequency) {
                WordFrequency temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordFrequency words[]) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE *file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readWords(file, words);
    sortWords(words);
    printWords(words);

    fclose(file);
    return 0;
}