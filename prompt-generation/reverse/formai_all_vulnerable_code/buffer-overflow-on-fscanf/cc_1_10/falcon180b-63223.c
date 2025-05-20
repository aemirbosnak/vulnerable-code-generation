//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 0;
        i++;
    }
}

void countWords(char text[MAX_WORD_LENGTH], WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i, j, k;

    for (i = 0; text[i]!= '\0'; i++) {
        if (!isalpha(text[i])) {
            continue;
        }

        k = 0;
        while (isalpha(text[i + k]) && k < MAX_WORD_LENGTH) {
            word[k] = tolower(text[i + k]);
            k++;
        }
        word[k] = '\0';

        for (j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].frequency++;
                break;
            }
        }

        if (j == i) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
            i++;
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (words[i].frequency > 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    readWords(file, words);
    countWords("", words);
    printWords(words);

    fclose(file);

    return 0;
}