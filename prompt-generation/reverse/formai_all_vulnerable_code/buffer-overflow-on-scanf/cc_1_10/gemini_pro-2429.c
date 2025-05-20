//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
//Cosmic Antenna: Decipher Alien Transmissions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Galactic Alphabet and Translation Table
char galactic_alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
char terrestrial_translation[] = "VWXYZABCDEFGHIJKLMNOPQRSTUvwxyzabcdefghijklmnopqrstu";

// Function to Translate Alien Text
char* translateAlien(char* alien_text) {
    int length = strlen(alien_text);
    char* terrestrial_text = malloc(length + 1); // Allocate memory for translated text

    for (int i = 0; i < length; i++) {
        char alien_char = alien_text[i];
        int index = strchr(galactic_alphabet, alien_char) - galactic_alphabet;
        if (index >= 0) {
            terrestrial_text[i] = terrestrial_translation[index];
        } else {
            terrestrial_text[i] = alien_char; // Unrecognized characters remain unchanged
        }
    }

    terrestrial_text[length] = '\0'; // Null-terminate the translated text
    return terrestrial_text;
}

int main() {
    // Welcome Message from Commander Gamma
    printf("Welcome, Earthling! I am Commander Gamma, your cosmic linguistic guide.\n");
    printf("Let us decipher the enigmatic messages from our extraterrestrial neighbors.\n");

    // Input Alien Text from Earthling
    printf("Enter the alien text you wish to translate: ");
    char alien_text[100];
    scanf("%s", alien_text);

    // Translate the Alien Text
    char* terrestrial_text = translateAlien(alien_text);

    // Display the Terrestrial Translation
    printf("The terrestrial translation is: %s\n", terrestrial_text);
    printf("May this knowledge bridge the cosmic divide and foster interplanetary harmony.\n");
    printf("Beam me out, Scotty!"); // A nod to the legendary Star Trek phrase

    free(terrestrial_text); // Release the allocated memory for translated text

    return 0;
}