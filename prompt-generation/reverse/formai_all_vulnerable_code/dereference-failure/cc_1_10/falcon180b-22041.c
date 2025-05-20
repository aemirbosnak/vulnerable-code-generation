//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

struct word {
    char *english;
    char *alien;
};

int main(void) {
    FILE *dict_file;
    char line[MAX_WORD_LENGTH];
    char *word;
    struct word *dict = malloc(MAX_WORDS * sizeof(struct word));
    int num_words = 0;

    dict_file = fopen("dictionary.txt", "r");

    if (dict_file == NULL) {
        printf("Error: dictionary file not found.\n");
        exit(1);
    }

    // Read in the dictionary file
    while (fgets(line, MAX_WORD_LENGTH, dict_file)!= NULL) {
        word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: dictionary too large.\n");
                exit(1);
            }
            dict[num_words].english = strdup(word);
            dict[num_words].alien = ""; // Initialize to empty string
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(dict_file);

    // Get input from user
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence or phrase to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Convert input to lowercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // Split input into words
    char *token = strtok(input, " ");
    while (token!= NULL) {
        int word_index = -1;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(dict[i].english, token) == 0) {
                word_index = i;
                break;
            }
        }

        // If word not found in dictionary, prompt user to add it
        if (word_index == -1) {
            printf("Word not found in dictionary: %s\n", token);
            printf("Enter alien language translation (or press enter to skip):\n");
            char alien_word[MAX_WORD_LENGTH];
            fgets(alien_word, MAX_WORD_LENGTH, stdin);
            dict[num_words].english = strdup(token);
            dict[num_words].alien = strdup(alien_word);
            num_words++;
        } else {
            printf("%s -> %s\n", token, dict[word_index].alien);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}