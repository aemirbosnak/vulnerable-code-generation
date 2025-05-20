//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: modular
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20 // Maximum length of words in the alien language
#define MAX_NUM_WORDS 50 // Maximum number of words in the dictionary

// Struct definition for the dictionary
struct Dictionary {
    char alien_word[MAX_WORD_LENGTH];
    char english_word[MAX_WORD_LENGTH];
};

// Function to populate the dictionary with alien and english words
void populate_dictionary(struct Dictionary *dictionary, int num_words) {
    
    printf("Enter %d alien words and their corresponding english translations:\n", num_words);
    
    for (int i = 0; i < num_words; i++) {
        printf("Alien word %d: ", i+1);
        scanf("%s", dictionary[i].alien_word);
        printf("English translation for %s: ", dictionary[i].alien_word);
        scanf("%s", dictionary[i].english_word);
    }
}

// Function to translate a sentence from the alien language to english
void translate_sentence(struct Dictionary *dictionary, int num_words, char *sentence) {
    
    char delimiters[] = " "; // Delimiters for splitting the sentence into words
    char *word = strtok(sentence, delimiters); // Get first word
    
    while (word != NULL) {
        int found = 0; // Flag to indicate if the word was found in the dictionary
        
        // Search the dictionary for a match
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, dictionary[i].alien_word) == 0) {
                printf("%s ", dictionary[i].english_word);
                found = 1;
                break;
            }
        }
        
        // If the word was not found, print an error message
        if (!found) {
            printf("(Unknown word '%s') ", word);
        }
        
        word = strtok(NULL, delimiters); // Get next word
    }
}

int main() {
    struct Dictionary dictionary[MAX_NUM_WORDS]; // Create a dictionary
    int num_words; // Number of words in the dictionary
    char sentence[100]; // Sentence to translate
    
    printf("Welcome to the Alien Language translator!\n");
    
    // Get the number of words in the dictionary from the user
    printf("Enter the number of alien words in the dictionary (max %d): ", MAX_NUM_WORDS);
    scanf("%d", &num_words);
    
    // Populate the dictionary
    populate_dictionary(dictionary, num_words);
    
    // Get the sentence to translate from the user
    printf("Enter a sentence in the alien language: ");
    scanf(" %[^\n]s", sentence);
    
    // Translate the sentence
    printf("\nEnglish translation: ");
    translate_sentence(dictionary, num_words, sentence);
    
    return 0;
}