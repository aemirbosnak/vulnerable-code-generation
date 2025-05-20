//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

// Function to translate Cat language to English
char* translate(char* cat_language) {

    // Dictionary of Cat words to English translations
    char* dictionary[10][2] = {
        {"meow", "hello"},
        {"purr", "goodbye"},
        {"knead", "love"},
        {"claw", "angry"},
        {"mrow", "yes"},
        {"hiss", "no"},
        {"nip", "play"},
        {"yowl", "help"},
        {"lick", "affection"},
        {"scamper", "fun"}
    };

    static char translation[1000]; // Array to hold translated string
    char* word;
    word = strtok(cat_language, " "); // Get first word of input string

    while (word != NULL) { // Loop through all words in input string
        int i;
        int translated = 0;
        for (i = 0; i < 10; i++) { // Loop through dictionary to find match
            if (strcmp(word, dictionary[i][0]) == 0) {
                strcat(translation, dictionary[i][1]); // Append translation to output string
                strcat(translation, " "); // Add space between words
                translated = 1;
                break; // Exit loop once match is found
            }
        }
        if (!translated) { // If word is not in dictionary, add to output string unchanged
            strcat(translation, word);
            strcat(translation, " ");
        }
        word = strtok(NULL, " "); // Get next word of input string
    }

    return translation; // Return translated string
}

int main() {
    char cat_language[1000]; // Input string
    printf("Enter Cat language: ");
    gets(cat_language); // Get input string from user
    printf("English translation: %s\n", translate(cat_language)); // Display translated string
    return 0;
}