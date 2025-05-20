//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 20
#define ALIEN_ALPHABET_SIZE 26

typedef struct {
    char english[WORD_LENGTH];
    char alien[WORD_LENGTH];
} Dictionary;

void loadDictionary(Dictionary dictionary[], const char filename[]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open dictionary file.\n");
        exit(1);
    }

    int i = 0;
    char word[WORD_LENGTH];
    char alienWord[WORD_LENGTH];

    while (fgets(word, WORD_LENGTH, file) != NULL && i < MAX_WORDS) {
        sscanf(word, "%s%s", dictionary[i].english, alienWord);

        for (int j = 0; j < strlen(alienWord); j++) {
            dictionary[i].alien[j] = alienWord[j] + 'A' - 'A';
        }
        i++;
    }

    fclose(file);
}

int main() {
    Dictionary dictionary[MAX_WORDS];

    loadDictionary(dictionary, "dictionary.txt");

    char english[WORD_LENGTH];
    printf("Enter English sentence: ");
    fgets(english, WORD_LENGTH, stdin);

    char *token = strtok(english, " ");
    int i, j;

    while (token != NULL) {
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                for (j = 0; j < strlen(token); j++) {
                    putchar(dictionary[i].alien[j] + 'A' - 'A');
                }
                putchar(' ');
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    putchar('\n');

    return 0;
}