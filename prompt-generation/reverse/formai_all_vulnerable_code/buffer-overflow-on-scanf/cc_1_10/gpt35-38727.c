//FormAI DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// Module to read a word from stdin
void read_word(char *word) {
    printf("Enter a word: ");
    scanf("%s", word);
}

// Module to validate if the character is an alphabet
int is_alpha(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// Module to convert uppercase characters to lowercase
char to_lowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Module to remove non-alphabetic characters from the word
void remove_non_alpha(char *word) {
    char *src = word;
    char *dst = word;
    while (*src) {
        if (is_alpha(*src)) {
            *dst = to_lowercase(*src);
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

// Module to load the dictionary from file
int load_dictionary(char dictionary[][MAX_WORD_LENGTH], const char* path) {
    int count = 0;
    FILE* file_ptr = fopen(path, "r");
    if (file_ptr == NULL) {
        printf("Error loading dictionary file %s\n", path);
        return count;
    }
    while (fgets(dictionary[count], MAX_WORD_LENGTH, file_ptr)) {
        // Remove newline character
        dictionary[count][strcspn(dictionary[count], "\n")] = '\0';

        count++;
    }
    fclose(file_ptr);
    printf("Dictionary loaded with %d words.\n", count);
    return count;
}

// Module to check if the word exists in dictionary
int spell_check(char dictionary[][MAX_WORD_LENGTH], int dictionary_count, const char* word) {
    for (int i = 0; i < dictionary_count; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char word[MAX_WORD_LENGTH];
    char dictionary[10000][MAX_WORD_LENGTH];
    int dictionary_count = load_dictionary(dictionary, "dictionary.txt");

    read_word(word);
    remove_non_alpha(word);
    if (spell_check(dictionary, dictionary_count, word)) {
        printf("%s is spelled correctly.\n", word);
    } else {
        printf("%s is misspelled.\n", word);
    }

    return 0;
}