//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Define the Alien language dictionary
char *alien_lang[] = {"zoxx", "bleeb", "frrr", "glix", "narp", "plax", "qoot", "skir", "zort", "tiv"};

// Define the English language dictionary
char *english_lang[] = {"hello", "world", "this", "is", "a", "sample", "program", "in", "alien", "language"};

// A function to translate Alien language to English
void alien_to_english(char *alien_message) {
    char *token, *ptr;
    int i;
    
    // Split the message into words
    token = strtok(alien_message, " ");
    
    while (token != NULL) {
        // Check if the word is in the Alien language dictionary
        ptr = strchr(*alien_lang, *token);
        if (ptr != NULL) {
            i = ptr - *alien_lang;
            // Print the corresponding English word
            printf("%s ", *(english_lang + i));
        } else {
            // If the word is not in the dictionary, print it as it is
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

// A function to translate English language to Alien
void english_to_alien(char *english_message) {
    char *token, *ptr;
    int i;
    
    // Split the message into words
    token = strtok(english_message, " ");
    
    while (token != NULL) {
        // Check if the word is in the English language dictionary
        ptr = strchr(*english_lang, *token);
        if (ptr != NULL) {
            i = ptr - *english_lang;
            // Print the corresponding Alien word
            printf("%s ", *(alien_lang + i));
        } else {
            // If the word is not in the dictionary, print it as it is
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}

// Main function
int main() {
    int choice;
    char message[100];
    
    printf("Enter the message: ");
    fgets(message, 100, stdin);
    
    printf("Enter the choice:\n1. Alien to English\n2. English to Alien\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Translating Alien to English...\n");
            alien_to_english(message);
            break;
        case 2:
            printf("Translating English to Alien...\n");
            english_to_alien(message);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}