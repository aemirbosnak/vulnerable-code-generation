//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
struct alien_word {
    char *alien;
    char *english;
};

struct alien_word dictionary[] = {
    {"akla", "hello"},
    {"aksha", "goodbye"},
    {"akshay", "thank you"},
    {"akshey", "please"},
    {"akram", "yes"},
    {"akbar", "no"},
    {"akash", "I"},
    {"akhila", "you"},
    {"akanksha", "we"},
    {"akashdeep", "they"},
    {"akashic", "he"},
    {"akashi", "she"},
};

// Function to translate an alien word to English
char *translate_to_english(char *alien_word) {
    int i;

    // Loop through the dictionary to find the matching alien word
    for (i = 0; i < sizeof(dictionary) / sizeof(struct alien_word); i++) {
        if (strcmp(alien_word, dictionary[i].alien) == 0) {
            return dictionary[i].english;
        }
    }

    // If the alien word is not found in the dictionary, return an error message
    return "Error: Alien word not found in dictionary";
}

// Function to translate a sentence from alien language to English
char *translate_sentence(char *alien_sentence) {
    char *english_sentence;
    char *alien_word;
    char *english_word;

    // Allocate memory for the English sentence
    english_sentence = malloc(strlen(alien_sentence) + 1);

    // Loop through the alien sentence and translate each word
    alien_word = strtok(alien_sentence, " ");
    while (alien_word != NULL) {
        english_word = translate_to_english(alien_word);
        strcat(english_sentence, english_word);
        strcat(english_sentence, " ");
        alien_word = strtok(NULL, " ");
    }

    // Return the English sentence
    return english_sentence;
}

int main() {
    char *alien_sentence;
    char *english_sentence;

    // Get the alien sentence from the user
    printf("Enter an alien sentence: ");
    scanf("%s", alien_sentence);

    // Translate the alien sentence to English
    english_sentence = translate_sentence(alien_sentence);

    // Print the English sentence
    printf("English sentence: %s\n", english_sentence);

    return 0;
}