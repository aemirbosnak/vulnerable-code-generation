//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
const char *alien_dict[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j",
    "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
    "u", "v", "w", "x", "y", "z"
};

// Earth language dictionary
const char *earth_dict[] = {
    "Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet",
    "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango",
    "Uniform", "Victor", "Whiskey", "Xray", "Yankee", "Zulu"
};

// Function to translate from Alien to Earth language
char *alien_to_earth(const char *alien_str) {
    // Allocate memory for the Earth language translation
    char *earth_str = malloc(strlen(alien_str) * 6 + 1);
    if (!earth_str) {
        return NULL;
    }

    // Translate each character in the Alien string
    int i;
    for (i = 0; i < strlen(alien_str); i++) {
        int index = (int)(alien_str[i] - 'a');
        if (index >= 0 && index < 26) {
            strcpy(earth_str + i * 6, earth_dict[index]);
        } else {
            earth_str[i * 6] = '\0';
            break;
        }
    }

    // Add a null terminator to the end of the Earth language translation
    earth_str[i * 6] = '\0';

    // Return the Earth language translation
    return earth_str;
}

// Function to translate from Earth to Alien language
char *earth_to_alien(const char *earth_str) {
    // Allocate memory for the Alien language translation
    char *alien_str = malloc(strlen(earth_str) / 6 + 1);
    if (!alien_str) {
        return NULL;
    }

    // Translate each word in the Earth language string
    int i;
    for (i = 0; i < strlen(earth_str); i += 6) {
        int index = -1;
        int j;
        for (j = 0; j < 26; j++) {
            if (strcmp(earth_str + i, earth_dict[j]) == 0) {
                index = j;
                break;
            }
        }
        if (index >= 0) {
            alien_str[i / 6] = (char)('a' + index);
        } else {
            alien_str[i / 6] = '\0';
            break;
        }
    }

    // Add a null terminator to the end of the Alien language translation
    alien_str[i / 6] = '\0';

    // Return the Alien language translation
    return alien_str;
}

// Main function
int main() {
    // Get the input string from the user
    char input_str[100];
    printf("Enter the string to be translated: ");
    scanf("%s", input_str);

    // Translate the input string from Alien to Earth language
    char *earth_str = alien_to_earth(input_str);
    if (!earth_str) {
        printf("Error allocating memory for Earth language translation.\n");
        return EXIT_FAILURE;
    }

    // Print the Earth language translation
    printf("Earth language translation: %s\n", earth_str);

    // Translate the Earth language translation back to Alien language
    char *alien_str = earth_to_alien(earth_str);
    if (!alien_str) {
        printf("Error allocating memory for Alien language translation.\n");
        free(earth_str);
        return EXIT_FAILURE;
    }

    // Print the Alien language translation
    printf("Alien language translation: %s\n", alien_str);

    // Free the allocated memory
    free(earth_str);
    free(alien_str);

    return EXIT_SUCCESS;
}