//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a vowel
int is_vowel(char ch) {
    char lower = tolower(ch);
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}

// Function to translate a word from Cat Language to English
void translate_word(char *cat_word, char *english_word) {
    int len = strlen(cat_word);
    
    if (len >= 3 && cat_word[len - 2] == 'y' && cat_word[len - 1] == 'g') {
        strncpy(english_word, cat_word, len - 2); // Remove "gy"
        english_word[len - 2] = '\0';
        return;
    }

    // If it doesn't end with "gy", we will just copy it
    strcpy(english_word, cat_word);
}

// Function to translate a sentence from Cat Language to English
void translate_sentence(char *cat_sentence, char *english_sentence) {
    char *word = strtok(cat_sentence, " ");
    english_sentence[0] = '\0'; // Initialize the English sentence

    while (word != NULL) {
        char english_word[100];
        translate_word(word, english_word);
        strcat(english_sentence, english_word);
        strcat(english_sentence, " "); // Add a space
        word = strtok(NULL, " ");
    }

    // Cleanup: Remove the trailing space
    size_t len = strlen(english_sentence);
    if (len > 0) {
        english_sentence[len - 1] = '\0'; // Remove the last space
    }
}

// Main function
int main() {
    char cat_sentence[256];
    char english_sentence[256];

    printf("Enter a sentence in Cat Language (end with a dot '.'): ");
    fgets(cat_sentence, sizeof(cat_sentence), stdin);
    
    // Remove the newline character from fgets
    size_t len = strlen(cat_sentence);
    if (len > 0 && cat_sentence[len - 1] == '\n') {
        cat_sentence[len - 1] = '\0';
    }

    // Check if the sentence ends with a dot
    if (cat_sentence[len - 2] != '.') {
        printf("Sentence must end with a dot (.)!\n");
        return 1;
    }

    // Remove the dot before translation
    cat_sentence[len - 2] = '\0';

    // Translate the sentence
    translate_sentence(cat_sentence, english_sentence);

    // Output the translated sentence
    printf("Translated to English: %s.\n", english_sentence);
    
    return 0;
}