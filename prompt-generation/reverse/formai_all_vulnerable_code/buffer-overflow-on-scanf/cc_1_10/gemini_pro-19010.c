//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: artistic
// Welcome to the Intergalactic Translation Bureau!
// Let's break down the cosmic barriers and bridge the gap between Earthlings and extraterrestrials.

// Our mission: To decode the enigmatic language of the cosmos, one character at a time.
// Buckle up, Earthling, as we embark on a linguistic adventure through the vast expanse of the cosmos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty alien alphabet, a celestial tapestry of symbols.
char *alienAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ?!.";

// A Rosetta stone of Earthly languages, ready to decipher the alien tongue.
char *earthLanguages[] = {
    "English",
    "Spanish",
    "French",
    "German",
    "Mandarin",
    "Hindi",
    "Arabic",
    "Russian",
    "Japanese",
    "Portuguese",
};

// The heart of our translator, a cosmic decoder ring.
int translate(char alienChar) {
    // Earthly wisdom dictates that uppercase letters are different beasts.
    if (alienChar >= 'A' && alienChar <= 'Z') {
        alienChar += 32; // Downsize it to its lowercase counterpart.
    }

    // Scan through the alien alphabet, searching for the matching Earthly symbol.
    for (int i = 0; i < strlen(alienAlphabet); i++) {
        if (alienChar == alienAlphabet[i]) {
            return i; // Eureka! We've found the earthly equivalent.
        }
    }

    // If the alien character remains an enigma, we'll return a cosmic question mark.
    return strlen(alienAlphabet);
}

// Our interactive portal to the cosmos, ready to receive alien transmissions.
int main() {
    // Welcome message, echoing through the celestial void.
    printf("Greetings, Earthling! Ready to crack the alien language code?\n");

    // Our cosmic canvas, where the alien message will be painted.
    char alienMessage[1024];

    // Receive the alien message from the ethereal void.
    printf("Transmit the alien message, Earthling:\n");
    scanf("%s", alienMessage);

    // Earthly languages, a diverse symphony of human expression.
    printf("Which Earthly language shall we translate to, Earthling?\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, earthLanguages[i]);
    }

    // Choice of language, a bridge between worlds.
    int languageChoice;
    scanf("%d", &languageChoice);

    // Time to unveil the secrets of the cosmos, one character at a time.
    for (int i = 0; i < strlen(alienMessage); i++) {
        int translatedChar = translate(alienMessage[i]);

        // Earthly language characters, a symphony of familiar sounds.
        if (translatedChar < strlen(alienAlphabet)) {
            printf("%c", earthLanguages[languageChoice - 1][translatedChar]);
        } else {
            printf("?"); // An unknown character, a cosmic enigma.
        }
    }

    // Farewell, Earthling! May your journey through the cosmos be filled with newfound understanding.
    printf("\nTranslation complete, Earthling! May the stars guide you on your linguistic adventures.\n");

    return 0;
}