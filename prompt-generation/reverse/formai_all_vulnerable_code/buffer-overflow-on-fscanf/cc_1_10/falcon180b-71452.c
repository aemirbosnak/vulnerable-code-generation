//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    struct word dictionary[MAX_WORDS];
    int num_words = 0;
    char input[MAX_WORD_LENGTH];
    char *token;
    FILE *dict_file;

    // Open dictionary file
    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    // Read dictionary words
    while (fscanf(dict_file, "%s %s", input, input)!= EOF) {
        strcpy(dictionary[num_words].english, input);
        strcpy(dictionary[num_words].alien, input);
        num_words++;
    }

    // Close dictionary file
    fclose(dict_file);

    // Get user input
    printf("Enter a phrase to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Tokenize user input
    token = strtok(input, " ");
    while (token!= NULL) {
        // Look up word in dictionary
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(dictionary[i].english, token) == 0) {
                printf("%s -> %s\n", token, dictionary[i].alien);
                break;
            }
        }
        if (i == num_words) {
            // Word not found in dictionary
            printf("%s -> %s\n", token, "UNKNOWN");
        }
        token = strtok(NULL, " ");
    }

    return 0;
}