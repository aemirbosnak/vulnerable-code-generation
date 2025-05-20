//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define NUM_WORDS 10

// Cat Language Dictionary
const char *englishWords[NUM_WORDS] = {
    "hello",
    "cat",
    "food",
    "play",
    "friend",
    "sleep",
    "mouse",
    "happy",
    "home",
    "meow"
};

const char *catWords[NUM_WORDS] = {
    "mewmew",
    "feline companion",
    "noms",
    "pounce",
    "fur buddy",
    "nap time",
    "squeaky snack",
    "purrfectly joyful",
    "kitten den",
    "purr"
};

// Function to convert a single word to Cat Language
const char *translateToCat(const char *word) {
    // Convert the word to lowercase for matching
    char lowerWord[MAX_INPUT_SIZE];
    for (int i = 0; word[i] != '\0'; i++) {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';

    // Search for the word in the dictionary
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(lowerWord, englishWords[i]) == 0) {
            return catWords[i];
        }
    }
    return word; // Return the original word if no translation is found
}

// Function to translate a sentence to Cat Language
void translateSentence(const char *sentence) {
    char translated[MAX_INPUT_SIZE] = "";
    char word[MAX_INPUT_SIZE];
    int pos = 0;

    // Tokenize the input sentence into words
    for (int i = 0; ; i++) {
        // Extract a word from the sentence
        sscanf(sentence + pos, "%s", word);
        if (strlen(word) == 0) break; // Break if no more words
        
        const char *catWord = translateToCat(word); // Translate the word
        strcat(translated, catWord); // Append to the translated sentence
        strcat(translated, " "); // Append space for next word
        pos += strlen(word) + 1; // Update the position for the next word
    }

    printf("Cat Language: %s\n", translated);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the Cat Language Translator!\n");
    printf("Enter a sentence in English to translate:\n");

    // Get user input
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character from the input
        input[strcspn(input, "\n")] = 0;
        translateSentence(input); // Translate the input sentence
    } else {
        printf("Error reading input.\n");
    }
    
    return 0;
}