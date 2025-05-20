//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to check spelling of a given word
int spell_check(char *word, char **dict, int dict_len) {
    // assuming all words in the dictionary are in lowercase
    for (int i = 0; i < dict_len; i++) {
        if (strcmp(word, dict[i]) == 0) {
            return 1; // word found in dictionary
        }
    }
    return 0; // word not found
}

int main() {
    // initializing the dictionary with some words
    char *dictionary[] = {"apple", "banana", "cherry", "durian", "eggplant", 
                          "fennel", "grape", "honeydew", "iceberg", "jicama",
                          "kale", "lemon", "mango", "nectarine", "orange",
                          "peach", "quince", "raspberry", "strawberry", "tangerine"};
    int dict_len = sizeof(dictionary) / sizeof(char *);

    // getting input word from user
    printf("Enter a word to check spelling: ");
    char input_word[20];
    scanf("%s", input_word);

    // converting input word to lowercase
    for (int i = 0; i < strlen(input_word); i++) {
        input_word[i] = tolower(input_word[i]);
    }

    // checking spelling of input word
    if (spell_check(input_word, dictionary, dict_len)) {
        printf("Congratulations! Your spelling is perfect!\n");
    } else {
        printf("Sorry, but your spelling is truly terrible. Here's how you fix it:\n");

        // generating all possible words by adding, removing, or replacing one character
        char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
        int alphabet_len = strlen(alphabet);
        char *possible_words[60];
        int num_possible_words = 0;

        // adding all words obtained by adding one character
        for (int i = 0; i <= strlen(input_word); i++) {
            for (int j = 0; j < alphabet_len; j++) {
                char *new_word = (char *) malloc(sizeof(char) * (strlen(input_word) + 2));
                strncpy(new_word, input_word, i);
                new_word[i] = alphabet[j];
                strcpy(new_word + i + 1, input_word + i);
                possible_words[num_possible_words++] = new_word;
            }
        }

        // adding all words obtained by removing one character
        for (int i = 0; i < strlen(input_word); i++) {
            char *new_word = (char *) malloc(sizeof(char) * strlen(input_word));
            strncpy(new_word, input_word, i);
            strcpy(new_word + i, input_word + i + 1);
            possible_words[num_possible_words++] = new_word;
        }

        // adding all words obtained by replacing one character
        for (int i = 0; i < strlen(input_word); i++) {
            for (int j = 0; j < alphabet_len; j++) {
                char *new_word = (char *) malloc(sizeof(char) * strlen(input_word));
                strncpy(new_word, input_word, i);
                new_word[i] = alphabet[j];
                strcpy(new_word + i + 1, input_word + i + 1);
                possible_words[num_possible_words++] = new_word;
            }
        }

        // checking each possible word for spelling
        for (int i = 0; i < num_possible_words; i++) {
            if (spell_check(possible_words[i], dictionary, dict_len)) {
                printf("%s\n", possible_words[i]); // suggesting the correct spelling
            }
            free(possible_words[i]); // freeing memory allocated for each possible word
        }
    }
    return 0;
}