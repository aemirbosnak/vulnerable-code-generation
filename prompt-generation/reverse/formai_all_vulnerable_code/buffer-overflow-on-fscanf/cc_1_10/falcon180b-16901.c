//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20 // Maximum length of a word
#define NUM_WORDS 1000 // Maximum number of words in the dictionary

struct word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

struct word dictionary[NUM_WORDS]; // The dictionary of words
int num_words = 0; // The number of words in the dictionary

// Load the dictionary from a text file
void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= NUM_WORDS) {
            printf("Error: Dictionary is full.\n");
            exit(1);
        }

        strcpy(dictionary[num_words].word, word);
        dictionary[num_words].frequency = 0;
        num_words++;
    }

    fclose(file);
}

// Recursive function to check if a word is in the dictionary
int is_word(char* word, int start_index, int* matched_word_index) {
    if (start_index >= strlen(word)) {
        // We have matched the entire word
        return 1;
    }

    int matched_index = -1;
    for (int i = 0; i < num_words; i++) {
        if (strncmp(word, dictionary[i].word, start_index) == 0) {
            // We have a match
            matched_index = i;
            break;
        }
    }

    if (matched_index == -1) {
        // The word is not in the dictionary
        return 0;
    }

    // Recursively check the rest of the word
    int next_index = start_index + strlen(dictionary[matched_index].word);
    return is_word(word, next_index, &matched_index);
}

// Recursive function to check the spelling of a sentence
void check_spelling(char* sentence, int start_index) {
    if (start_index >= strlen(sentence)) {
        // We have checked the entire sentence
        return;
    }

    if (isalpha(sentence[start_index])) {
        // We have a word
        int matched_word_index = -1;
        if (is_word(sentence, start_index, &matched_word_index)) {
            // The word is in the dictionary
            dictionary[matched_word_index].frequency++;
        } else {
            // The word is not in the dictionary
            printf("Misspelled word: %s\n", sentence + start_index);
        }
    } else {
        // We have a punctuation mark or whitespace
        check_spelling(sentence, start_index + 1);
    }
}

// Main function to load the dictionary, read a sentence, and check its spelling
int main() {
    load_dictionary("dictionary.txt");

    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    check_spelling(sentence, 0);

    return 0;
}