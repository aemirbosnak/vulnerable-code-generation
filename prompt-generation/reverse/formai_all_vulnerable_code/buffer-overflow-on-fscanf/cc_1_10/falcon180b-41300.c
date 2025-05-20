//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

struct word {
    char english[50];
    char cat[50];
};

int main() {
    FILE *dict;
    struct word dict_words[MAX_WORDS];
    int num_words = 0;
    char input[100];
    char *token;

    // Open the dictionary file
    dict = fopen("dict.txt", "r");

    if (dict == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    // Read in the dictionary words
    while (fscanf(dict, "%s %s\n", dict_words[num_words].english, dict_words[num_words].cat)!= EOF) {
        num_words++;
    }

    // Close the dictionary file
    fclose(dict);

    // Prompt the user for input
    printf("Enter a sentence or phrase to translate:\n");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input
    token = strtok(input, " ");

    while (token!= NULL) {
        // Look up the word in the dictionary
        int i = 0;
        while (i < num_words && strcmp(dict_words[i].english, token)!= 0) {
            i++;
        }

        if (i == num_words) {
            printf("Unknown word: %s\n", token);
        } else {
            printf("%s -> %s\n", token, dict_words[i].cat);
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return 0;
}