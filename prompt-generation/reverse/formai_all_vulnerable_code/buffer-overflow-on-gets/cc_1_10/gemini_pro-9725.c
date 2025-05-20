//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien language dictionary
const char *alien_dict[] = {
    "awawa", "ba", "ca", "da", "ea", "fa", "ga", "ha", "ia", "ja", "ka", "la", "ma", "na", "oa", "pa", "qa", "ra", "sa", "ta", "ua", "va", "wa", "xa", "ya", "za"
};

// Function to translate a string from English to Alien language
char *english_to_alien(char *english) {
    int len = strlen(english);
    char *alien = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = english[i];
        if (c >= 'a' && c <= 'z') {
            alien[i] = alien_dict[c - 'a'][0];
        } else if (c >= 'A' && c <= 'Z') {
            alien[i] = alien_dict[c - 'A'][0];
        } else {
            alien[i] = c;
        }
    }
    alien[len] = '\0';
    return alien;
}

// Function to translate a string from Alien language to English
char *alien_to_english(char *alien) {
    int len = strlen(alien);
    char *english = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        char c = alien[i];
        for (int j = 0; j < 26; j++) {
            if (c == alien_dict[j][0]) {
                english[i] = 'a' + j;
                break;
            }
        }
    }
    english[len] = '\0';
    return english;
}

int main() {
    // Get the English string from the user
    char english[100];
    printf("Enter an English string: ");
    gets(english);

    // Translate the string from English to Alien language
    char *alien = english_to_alien(english);

    // Print the Alien language string
    printf("Alien language string: %s\n", alien);

    // Translate the string from Alien language to English
    char *english2 = alien_to_english(alien);

    // Print the English string
    printf("English string: %s\n", english2);

    return 0;
}