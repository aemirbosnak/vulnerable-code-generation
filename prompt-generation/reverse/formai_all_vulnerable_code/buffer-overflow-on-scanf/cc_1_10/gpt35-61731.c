//FormAI DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 256
#define MAX_DICTIONARY_ENTRIES 1000

int num_dict_entries = 0;
char dictionary[MAX_DICTIONARY_ENTRIES][MAX_WORD_LENGTH];

void initialize_dictionary() {
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error opening dictionary file!\n");
        return;
    }
    
    while(fscanf(dict_file, "%s", dictionary[num_dict_entries]) != EOF) {
        num_dict_entries++;
    }
    fclose(dict_file);
}

int is_valid_word(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isalpha(input[i])) {
            return 0;
        }
    }
    return 1;
}

int is_word_in_dictionary(char *input) {
    for (int i = 0; i < num_dict_entries; i++) {
        if (strcmp(input, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char *input) {
    // check if input is a valid word
    if (!is_valid_word(input)) {
        printf("%s is not a valid word!\n", input);
        return;
    }
    
    // check if input is in dictionary
    if (is_word_in_dictionary(input)) {
        printf("%s is spelled correctly.\n", input);
        return;
    }
    
    // check if input is one edit distance away from a word in the dictionary
    char possible_word[MAX_WORD_LENGTH];
    for (int i = 0; i < num_dict_entries; i++) {
        strcpy(possible_word, dictionary[i]);
        int len_diff = strlen(input) - strlen(possible_word);
        if (len_diff == 0) { // same length, check if one substitution needed
            int num_diff_chars = 0;
            for (int j = 0; j < strlen(input); j++) {
                if (input[j] != possible_word[j]) {
                    num_diff_chars++;
                }
            }
            if (num_diff_chars == 1) {
                printf("%s is spelled incorrectly. Perhaps you meant %s?\n", input, possible_word);
                return;
            }
        }
        else if (abs(len_diff) == 1) { // different length, check if one insertion or deletion needed
            char *shorter, *longer;
            if (len_diff < 0) {
                shorter = input;
                longer = possible_word;
            }
            else {
                shorter = possible_word;
                longer = input;
            }
            int i = 0, j = 0, num_diff_chars = 0;
            while (i < strlen(shorter) && j < strlen(longer)) {
                if (shorter[i] != longer[j]) {
                    num_diff_chars++;
                    j++;
                }
                else {
                    i++;
                    j++;
                }
            }
            if (num_diff_chars == 1) {
                printf("%s is spelled incorrectly. Perhaps you meant %s?\n", input, possible_word);
                return;
            }
        }
    }
    
    // word not in dictionary or within one edit distance
    printf("%s is spelled incorrectly. No suggestions found.\n", input);
}

int main() {
    initialize_dictionary();
    
    char input[MAX_WORD_LENGTH];
    while(1) {
        printf("Enter a word to spell check (or QUIT to exit): ");
        scanf("%s", input);
        if (strcmp(input, "QUIT") == 0) {
            break;
        }
        check_spelling(input);
    }
    
    return 0;
}