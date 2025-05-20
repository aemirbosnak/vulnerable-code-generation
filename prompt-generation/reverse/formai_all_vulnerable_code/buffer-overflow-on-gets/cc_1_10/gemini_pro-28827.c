//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alien language dictionary
char *alienDictionary[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z", " "
};

// Function to translate a string from English to Alien
char *translateToAlien(char *englishString) {
    int englishStringLength = strlen(englishString);
    char *alienString = malloc(englishStringLength + 1);
    int i;

    for (i = 0; i < englishStringLength; i++) {
        char englishCharacter = englishString[i];
        int index = 0;

        // Find the index of the English character in the dictionary
        while (strcmp(alienDictionary[index], &englishCharacter) != 0) {
            index++;
        }

        // Convert the index to an Alien character
        char alienCharacter = alienDictionary[(26 - index) % 26];

        // Append the Alien character to the Alien string
        strncat(alienString, &alienCharacter, 1);
    }

    // Null-terminate the Alien string
    alienString[englishStringLength] = '\0';

    return alienString;
}

// Function to translate a string from Alien to English
char *translateFromAlien(char *alienString) {
    int alienStringLength = strlen(alienString);
    char *englishString = malloc(alienStringLength + 1);
    int i;

    for (i = 0; i < alienStringLength; i++) {
        char alienCharacter = alienString[i];
        int index = 0;

        // Find the index of the Alien character in the dictionary
        while (strcmp(alienDictionary[index], &alienCharacter) != 0) {
            index++;
        }

        // Convert the index to an English character
        char englishCharacter = alienDictionary[(26 - index) % 26];

        // Append the English character to the English string
        strncat(englishString, &englishCharacter, 1);
    }

    // Null-terminate the English string
    englishString[alienStringLength] = '\0';

    return englishString;
}

int main() {
    // Get the English string from the user
    char englishString[100];
    printf("Enter the English string: ");
    gets(englishString);

    // Translate the English string to Alien
    char *alienString = translateToAlien(englishString);

    // Print the Alien string
    printf("The Alien string is: %s\n", alienString);

    // Translate the Alien string back to English
    char *englishString2 = translateFromAlien(alienString);

    // Print the English string
    printf("The English string is: %s\n", englishString2);

    // Free the memory allocated for the Alien string
    free(alienString);

    // Free the memory allocated for the English string
    free(englishString2);

    return 0;
}