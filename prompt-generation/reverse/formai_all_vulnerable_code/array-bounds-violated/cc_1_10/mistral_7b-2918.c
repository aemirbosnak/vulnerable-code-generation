//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_DICTIONARY 1000
#define WORD_LENGTH 50
#define DELIM " \t\n\r,"

// Function to convert string to lowercase
void to_lower(char *str) {
    int i;
    for (i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Function to check if a word is in the dictionary
int is_valid_word(char *word) {
    int i;
    FILE *fp;
    char dictionary[MAX_DICTIONARY][WORD_LENGTH];

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    i = 0;
    while (fgets(dictionary[i], WORD_LENGTH, fp) != NULL) {
        to_lower(dictionary[i]);
        if (strncmp(dictionary[i], word, strlen(word)) == 0) {
            fclose(fp);
            return 1;
        }
        i++;
    }

    fclose(fp);
    return 0;
}

// Function to check the spelling of a word
int check_spelling(char *word) {
    int i, j, is_valid = 1;
    char valid_word[WORD_LENGTH];

    if (is_valid_word(word)) {
        printf("%s is a valid word.\n", word);
        return 1;
    }

    for (i = 0; word[i]; i++) {
        for (j = 0; valid_word[j]; j++) {
            if (word[i] != valid_word[j] && toupper(word[i]) != toupper(valid_word[j])) {
                is_valid = 0;
                break;
            }
        }
        if (!is_valid) {
            printf("%s is not a valid word. Did you mean:\n", word);
            int misspelled_letter_index = i;
            for (j = 0; valid_word[j]; j++) {
                if (valid_word[j] != '\0') {
                    if (tolower(valid_word[j]) == tolower(word[misspelled_letter_index])) {
                        printf("%c\n", valid_word[j]);
                        break;
                    }
                }
            }
            return 0;
        }
        strcpy(valid_word, word);
    }

    printf("%s is a valid word.\n", word);
    return 1;
}

int main() {
    char user_word[WORD_LENGTH];

    printf("Welcome to the Magic Spell Checker!\n");
    printf("Enter a word to check its spelling:\n");
    fgets(user_word, WORD_LENGTH, stdin);
    to_lower(user_word);
    user_word[strlen(user_word) - 1] = '\0';

    check_spelling(user_word);

    return 0;
}