//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAGIC_NUMBER 1024

// Structure to store the spell check data
typedef struct {
    char word[20];  // Original word
    char correct[20];  // Corrected word
    int frequency;  // Frequency of the word in the text
} SpellData;

// Function to check the word for spelling errors
int check_spelling(char *word) {
    // Initialize the spell check data structure
    SpellData spell_data;
    spell_data.word[0] = '\0';
    spell_data.correct[0] = '\0';
    spell_data.frequency = 0;

    // Check for each character in the word
    for (int i = 0; word[i] != '\0'; i++) {
        // Check for common spelling errors
        if (word[i] == 'a' && i == 0) {
            // Check if the word starts with "an"
            if (word[1] == 'n') {
                spell_data.correct[0] = 'n';
                spell_data.word[0] = 'an';
            }
        } else if (word[i] == 'i' && i == 0) {
            // Check if the word starts with "in"
            if (word[1] == 'n') {
                spell_data.correct[0] = 'n';
                spell_data.word[0] = 'in';
            }
        } else if (word[i] == 'o' && i == 0) {
            // Check if the word starts with "on"
            if (word[1] == 'n') {
                spell_data.correct[0] = 'n';
                spell_data.word[0] = 'on';
            }
        } else if (word[i] == 'u' && i == 0) {
            // Check if the word starts with "un"
            if (word[1] == 'n') {
                spell_data.correct[0] = 'n';
                spell_data.word[0] = 'un';
            }
        } else if (word[i] == 'e' && i == 0) {
            // Check if the word starts with "en"
            if (word[1] == 'n') {
                spell_data.correct[0] = 'n';
                spell_data.word[0] = 'en';
            }
        }
        // Check for double letters
        else if (word[i] == word[i - 1]) {
            spell_data.correct[i] = word[i - 1];
            spell_data.word[i] = word[i - 1];
        }
        // Check for incorrect letters
        else {
            int j = i - 1;
            while (j >= 0 && word[j] == word[i]) {
                j--;
                spell_data.correct[i] = word[j];
                spell_data.word[i] = word[j];
            }
        }
    }

    // Check if the word is in the dictionary
    if (strcmp(word, spell_data.word) == 0) {
        return 1;  // Word is in the dictionary
    } else {
        return 0;  // Word is not in the dictionary
    }
}

int main() {
    // Initialize the spell check data structure
    SpellData spell_data;
    spell_data.word[0] = '\0';
    spell_data.correct[0] = '\0';
    spell_data.frequency = 0;

    // Read the text from the user
    char text[MAGIC_NUMBER];
    gets(text);

    // Check each word in the text for spelling errors
    char *word = strtok(text, " ");
    while (word != NULL) {
        int is_correct = check_spelling(word);
        if (!is_correct) {
            printf("%s is not a valid word\n", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}