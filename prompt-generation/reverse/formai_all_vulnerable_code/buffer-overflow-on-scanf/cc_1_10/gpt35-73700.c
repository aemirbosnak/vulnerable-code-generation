//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>

// Define the mapping of alien characters to English characters
const char* ALIEN_TO_ENGLISH[26] = {
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z"
};

// Define the mapping of English characters to alien characters
const char* ENGLISH_TO_ALIEN[26] = {
    "z",
    "y",
    "x",
    "w",
    "v",
    "u",
    "t",
    "s",
    "r",
    "q",
    "p",
    "o",
    "n",
    "m",
    "l",
    "k",
    "j",
    "i",
    "h",
    "g",
    "f",
    "e",
    "d",
    "c",
    "b",
    "a"
};

// Convert an alien character to its corresponding English character
char convert_alien_to_english(char c) {
    int index = c - 'A';
    if (index >= 0 && index < 26) {
        return ALIEN_TO_ENGLISH[index][0];
    }
    return c;
}

// Convert an English character to its corresponding alien character
char convert_english_to_alien(char c) {
    int index = c - 'a';
    if (index >= 0 && index < 26) {
        return ENGLISH_TO_ALIEN[index][0];
    }
    return c;
}

int main() {
    char message[100];
    int i;

    printf("Enter an alien message:\n");
    fgets(message, 100, stdin);

    // Configure the language to translate to
    printf("Enter the language to translate to (1 for English, 2 for Alien):\n");
    int language;
    scanf("%d", &language);

    // Convert the message to the desired language
    if (language == 1) {
        // Translate from alien to English
        for (i = 0; message[i] != '\0'; i++) {
            message[i] = convert_alien_to_english(message[i]);
        }
    } else if (language == 2) {
        // Translate from English to alien
        for (i = 0; message[i] != '\0'; i++) {
            message[i] = convert_english_to_alien(message[i]);
        }
    } else {
        printf("Invalid language selection.\n");
        return 1;
    }

    printf("Translated message: %s", message);

    return 0;
}