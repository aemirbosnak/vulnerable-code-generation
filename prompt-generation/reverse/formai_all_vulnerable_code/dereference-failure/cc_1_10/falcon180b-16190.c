//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_entry {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    struct word_entry words[MAX_WORDS];
    int num_words = 0;

    file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Dictionary too large.\n");
            exit(1);
        }

        char *word = strtok(line, " ");
        strcpy(words[num_words].english, word);

        word = strtok(NULL, " ");
        strcpy(words[num_words].alien, word);

        num_words++;
    }

    fclose(file);

    char input[MAX_WORD_LENGTH];

    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];

    int i = 0;
    while (input[i]!= '\0') {
        char *word = strtok(input, " ");
        strcpy(output, word);

        for (int j = 0; j < num_words; j++) {
            if (strcmp(words[j].english, word) == 0) {
                strcpy(output, words[j].alien);
                break;
            }
        }

        strcat(output, " ");
        i += strlen(word) + 1;
    }

    printf("Translated sentence: %s\n", output);

    return 0;
}