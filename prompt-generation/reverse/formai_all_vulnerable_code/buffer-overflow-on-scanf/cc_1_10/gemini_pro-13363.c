//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The enigmatic alien lexicon
char alien_dict[][20] = {
    "Zoq", "Glu", "Fra", "Thol", "Glip",
    "Yip", "Zil", "Brox", "Futz", "Klit"
};

// Human-to-alien translation table
char human_to_alien[][20] = {
    "Hello", "Goodbye", "Thank you", "Please", "Help",
    "Yes", "No", "Stop", "Go", "Come"
};

// Alien-to-human translation table
char alien_to_human[][20] = {
    "Nuq", "Zog", "Xip", "Dri", "Plo",
    "Zi", "Xoq", "Grif", "Snor", "Trox"
};

// The cosmic translator core
void translate(char *input, int direction) {
    int i;
    
    // Human-to-alien translation
    if (direction == 1) {
        for (i = 0; i < 10; i++) {
            if (strcmp(input, human_to_alien[i]) == 0) {
                printf("%s\n", alien_dict[i]);
                return;
            }
        }
    // Alien-to-human translation
    } else {
        for (i = 0; i < 10; i++) {
            if (strcmp(input, alien_dict[i]) == 0) {
                printf("%s\n", alien_to_human[i]);
                return;
            }
        }
    }
    
    // If no translation found, alert the intergalactic linguists
    printf("Translation not found! Alert the Galactic Language Academy!\n");
}

int main() {
    char input[20];
    int direction;
    
    printf("Greetings, brave explorer! Enter your Earthly words or Martian utterances:\n");
    scanf("%s", input);
    
    printf("Specify the translation direction:\n");
    printf("1. Human to Alien\n");
    printf("2. Alien to Human\n");
    scanf("%d", &direction);
    
    translate(input, direction);
    
    printf("May your cosmic conversations be filled with laughter and understanding!\n");
    
    return 0;
}