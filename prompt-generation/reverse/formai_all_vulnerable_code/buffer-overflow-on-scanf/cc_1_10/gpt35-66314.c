//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *translate(char *sentence);

int main() {
    char *sentence;
    char *translated;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter a sentence for translation: ");

    // Read in the user's sentence
    sentence = (char *)malloc(1024);
    scanf("%[^\n]", sentence);

    // Translate the sentence
    translated = translate(sentence);

    // Print the translated sentence
    printf("Translated sentence: %s\n", translated);

    // Free memory
    free(sentence);
    free(translated);

    return 0;
}

char *translate(char *sentence) {
    char *translated;
    int length = strlen(sentence);

    // Allocate memory for translated sentence
    translated = (char *)malloc(length + 1);

    // Loop through each character in the sentence
    for (int i = 0; i < length; i++) {
        // If the character is a lower case letter
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            // Translate it to the Alien Language (add 3 to ASCII value)
            translated[i] = sentence[i] + 3;
        }
        // If the character is an upper case letter
        else if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
            // Translate it to the Alien Language (add 3 to ASCII value)
            translated[i] = sentence[i] + 3;
        }
        // Otherwise, leave the character as is
        else {
            translated[i] = sentence[i];
        }
    }

    // Add null terminator to the end of translated sentence
    translated[length] = '\0';

    return translated;
}