//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define DICTIONARY_SIZE 10

typedef struct {
    char *english_word;
    char *alien_word;
} DictionaryEntry;

DictionaryEntry dictionary[DICTIONARY_SIZE];

// Function to initialize the dictionary with some sample words
void initialize_dictionary() {
    dictionary[0].english_word = "hello";
    dictionary[0].alien_word = "ghorx";

    dictionary[1].english_word = "world";
    dictionary[1].alien_word = "xeut";
    
    dictionary[2].english_word = "friend";
    dictionary[2].alien_word = "birog";

    dictionary[3].english_word = "computer";
    dictionary[3].alien_word = "vhaqar";

    dictionary[4].english_word = "science";
    dictionary[4].alien_word = "qyetos";

    dictionary[5].english_word = "language";
    dictionary[5].alien_word = "zarkit";

    dictionary[6].english_word = "code";
    dictionary[6].alien_word = "brilz";

    dictionary[7].english_word = "program";
    dictionary[7].alien_word = "xunaf";

    dictionary[8].english_word = "translate";
    dictionary[8].alien_word = "vorcita";

    dictionary[9].english_word = "learn";
    dictionary[9].alien_word = "elsnar";
}

// Function to find an alien translation for an English word
char* translate_to_alien(const char* word) {
    for (int i = 0; i < DICTIONARY_SIZE; i++) {
        if (strcmp(dictionary[i].english_word, word) == 0) {
            return dictionary[i].alien_word;
        }
    }
    return NULL; // Return NULL if no translation is found
}

// Function to display the menu for translation
void display_menu() {
    printf("Welcome to the Alien Language Translator!\n");
    printf("1. Translate English to Alien\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

// Function to clear the input buffer
void clear_input_buffer() {
    while (getchar() != '\n');
}

// Main function to run the translator
int main() {
    initialize_dictionary();
    
    int choice;
    char input[MAX_LENGTH];
    char* translation;

    do {
        display_menu();
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1:
                printf("Enter an English word to translate: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the newline character

                translation = translate_to_alien(input);
                if (translation) {
                    printf("The alien translation of '%s' is '%s'.\n", input, translation);
                } else {
                    printf("Sorry, no translation found for '%s'.\n", input);
                }
                break;
            
            case 2:
                printf("Exiting the translator. Peace out, explorer!\n");
                break;

            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");

    } while (choice != 2);

    return 0;
}