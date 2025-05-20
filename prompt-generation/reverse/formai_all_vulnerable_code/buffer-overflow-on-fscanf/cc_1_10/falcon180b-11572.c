//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *dictionary;
    char line[MAX_WORD_LENGTH];
    int num_words = 0;
    struct word *word_list = malloc(MAX_WORDS * sizeof(struct word));

    dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    // read dictionary into memory
    while (fscanf(dictionary, "%s", line)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Dictionary is too large.\n");
            exit(1);
        }
        strcpy(word_list[num_words].english, line);
        word_list[num_words].alien[0] = '\0';
        num_words++;
    }
    fclose(dictionary);

    // prompt user for input
    printf("Enter a sentence to translate:\n");
    fgets(line, MAX_WORD_LENGTH, stdin);

    // remove newline character
    line[strcspn(line, "\n")] = '\0';

    // tokenize input sentence
    char *token = strtok(line, ",.?!;:");
    while (token!= NULL) {
        // check if word is in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, word_list[i].english) == 0) {
                // word found, translate to alien language
                strcpy(word_list[i].alien, "glorp");
                break;
            }
        }

        // word not found, leave as is
        if (i == num_words) {
            strcpy(word_list[num_words].english, token);
            word_list[num_words].alien[0] = '\0';
            num_words++;
        }

        token = strtok(NULL, ",.?!;:");
    }

    // print translated sentence
    printf("Translated sentence:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s ", word_list[i].alien);
    }
    printf("\n");

    return 0;
}