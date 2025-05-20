//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: puzzling
#include <stdio.h>
#include <string.h>

// Welcome to the puzzling C Cat Language Translator!
// This program will translate your sentences into meows and purrs 
// and leave those who understand feline language puzzled.

// The translation table for the C Cat Language
const char *cat_vocabs[] = {
    "meow",     // 0
    "purr",     // 1
    "hiss",     // 2
    "scratch",  // 3
    "lick",     // 4
    "yawn",     // 5
    "stretch",  // 6
    "sniff",    // 7
    "pounce",   // 8
    "play",     // 9
    "sleep",    // 10
    "eat",      // 11
    "hunt",     // 12
    "climb",    // 13
    "groom",    // 14
};

// Function to translate English into C Cat Language
void translate_to_cat(char *sentence) {
    printf("Translation to C Cat Language: ");
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        int len = strlen(word);
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += word[i];
        }
        int cat_vocab_index = sum % 15;
        printf("%s ", cat_vocabs[cat_vocab_index]);
        word = strtok(NULL, " ");
    }
    printf("\n");
}

int main() {
    // Welcome message
    printf("Welcome to the puzzling C Cat Language Translator!\n");
    printf("Enter your English sentence to translate: ");
    
    // Get user input
    char sentence[100];
    fgets(sentence, 100, stdin);
    
    // Remove newline character at the end of the sentence
    sentence[strcspn(sentence, "\n")] = 0;
    
    // Translate to C Cat Language
    translate_to_cat(sentence);
    
    // Exit message
    printf("Meow meow meow! Purr purr purr!\n");
    return 0;
}