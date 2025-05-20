//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PHRASE_LENGTH 50
#define NUM_PHRASES 5

typedef struct {
    char english[MAX_PHRASE_LENGTH];
    char alien[MAX_PHRASE_LENGTH];
} Phrase;

Phrase phrases[NUM_PHRASES] = {
    {"hello", "kla-gorn"},
    {"how are you", "kla-von hreig-thar"},
    {"I love you", "grom-grom vok-kla"},
    {"goodbye", "zorg-zorg"},
    {"thank you", "zorg-kla zorg-kla"}
};

void translate(char input[MAX_PHRASE_LENGTH]) {
    int i;
    Phrase *phrase;

    for (i = 0; i < NUM_PHRASES; i++) {
        phrase = &phrases[i];
        if (strcmp(input, phrase->english) == 0) {
            strcpy(input, phrase->alien);
            return;
        }
    }

    printf("Unknown phrase: %s\n", input);
}

int main() {
    char input[MAX_PHRASE_LENGTH];

    while (1) {
        printf("Enter English phrase or type 'quit' to exit: ");
        fgets(input, MAX_PHRASE_LENGTH, stdin);
        input[strlen(input) - 1] = '\0'; // Remove newline character

        if (strcmp(input, "quit") == 0) {
            break;
        }

        translate(input);
        printf("Alien translation: %s\n", input);
    }

    return 0;
}