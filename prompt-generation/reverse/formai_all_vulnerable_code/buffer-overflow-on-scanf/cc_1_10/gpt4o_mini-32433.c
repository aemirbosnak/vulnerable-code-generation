//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define DICTIONARY_SIZE 100

// A noble structure to hold our words of wisdom
typedef struct {
    char word[MAX_WORD_LENGTH];
} Word;

// The dictionary of fair words
Word dictionary[DICTIONARY_SIZE] = {
    {"Romeo"}, {"Juliet"}, {"love"}, {"night"}, {"heart"}, {"kiss"},
    {"fair"}, {"moon"}, {"gentle"}, {"sword"}, {"fate"}, {"dream"},
    {"tear"}, {"star"}, {"sweet"}, {"light"}, {"bane"}, {"world"},
    {"bliss"}, {"enemies"}, {"thou"}, {"dost"}, {"for"}, {"mine"},
    {"seek"}, {"find"}, {"death"}, {"wail"}, {"vow"}, {"rage"}, 
    {"life"}, {"star-crossed"}
};

// Function declarations
void initDictionary();
int checkSpelling(const char* word);
void fancyPrint(const char* word, int isMisspelled);

int main() {
    char input[MAX_WORD_LENGTH];
    
    // Initialize dictionary with fine words
    initDictionary();
    printf("O! Speak thy word, fair gentle soul, and we'll see if it doth shine bright!\n");
    
    // Get input from the user
    while (1) {
        printf("Enter a word (or type 'exit' to depart): ");
        scanf("%s", input);

        // Permit fair exits from the program
        if (strcmp(input, "exit") == 0) {
            printf("Parting is such sweet sorrow. Fare thee well!\n");
            break;
        }

        // Check the user's word against our cherished dictionary
        int result = checkSpelling(input);
        fancyPrint(input, result);
    }
    
    return 0;
}

// Function to initialize the dictionary with noble words
void initDictionary() {
    // The dictionary is already initialized with words
}

// Function to check the spelling against our cherished words
int checkSpelling(const char* word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 0; // Word is spelled correctly
        }
    }
    return 1; // Word is misspelled
}

// Function to print the result in a fanciful manner
void fancyPrint(const char* word, int isMisspelled) {
    if (isMisspelled) {
        printf("Alas! The word '%s' hath betrayed thee!\n", word);
        printf("Seek ye the wisdom of the parchment, for it is lost in the dark forest of ignorance.\n");
    } else {
        printf("Hark! The word '%s' doth bear no folly, pure and true it stands!\n", word);
        printf("Let joy fill the air as love doth bloom in the hearts of faithful lovers!\n");
    }
}