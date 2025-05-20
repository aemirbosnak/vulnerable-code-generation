//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove the punctuations from a word
void remove_punctuations(char *word) {
    int len = strlen(word);
    int i, j;
    for(i = 0; i < len; i++) {
        if(ispunct(word[i])) {
            for(j = i; j < len - 1; j++) {
                word[j] = word[j+1];
            }
            word[j] = '\0';
            len--;
            i--;
        }
    }   
}

// Function to convert the word to lowercase
void to_lower(char *word) {
    int len = strlen(word);
    int i;
    for(i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is spelled correctly or not
int is_spelled_correctly(char *word) {
    FILE *dictionary;

    dictionary = fopen("dictionary.txt", "r");

    if(dictionary == NULL) {
        printf("Error: couldn't open dictionary file.");
        exit(EXIT_FAILURE);
    }

    char dict_word[100];

    while(fscanf(dictionary, "%s", dict_word) != EOF) {
        remove_punctuations(dict_word);

        to_lower(dict_word);
        to_lower(word);

        if(strcmp(dict_word, word) == 0) {
            fclose(dictionary);
            return 1;
        }
    }

    fclose(dictionary);
    return 0;
}

int main() {
    char input_word[100];

    printf("Enter a word: ");
    scanf("%s", input_word);

    remove_punctuations(input_word);

    to_lower(input_word);

    if(is_spelled_correctly(input_word)) {
        printf("The word \"%s\" is spelled correctly.\n", input_word);
    }
    else {
        printf("The word \"%s\" is spelled incorrectly.\n", input_word);
    }

    return 0;
}