//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_SIZE 1000

bool is_in_dictionary(const char *word, const char *dictionary[]) {
    for (int i = 0; i < MAX_DICTIONARY_SIZE; ++i) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int num_words = 0;

    // Load dictionary from file
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return 1;
    }

    while (fscanf(fp, "%s", dictionary[num_words]) != EOF) {
        ++num_words;
    }

    fclose(fp);

    char word[MAX_WORD_LENGTH];
    bool correct_spelling;

    while (true) {
        printf("Enter a word to check (or type 'quit' to exit): ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        correct_spelling = is_in_dictionary(word, dictionary);

        if (correct_spelling) {
            printf("Correct spelling.\n");
        } else {
            printf("Incorrect spelling.\n");
        }
    }

    return 0;
}