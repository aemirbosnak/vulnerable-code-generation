//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 256
#define ALIEN_VOCAB_SIZE 10

typedef struct {
    char *earthWord;
    char *alienWord;
} AlienDictionary;

void initDictionary(AlienDictionary *dictionary) {
    dictionary[0].earthWord = "hello";
    dictionary[0].alienWord = "zargok";
    
    dictionary[1].earthWord = "friend";
    dictionary[1].alienWord = "blorpt";
    
    dictionary[2].earthWord = "home";
    dictionary[2].alienWord = "grom";
    
    dictionary[3].earthWord = "water";
    dictionary[3].alienWord = "flibb";
    
    dictionary[4].earthWord = "food";
    dictionary[4].alienWord = "grubbl";
    
    dictionary[5].earthWord = "yes";
    dictionary[5].alienWord = "yub";
    
    dictionary[6].earthWord = "no";
    dictionary[6].alienWord = "neb";
    
    dictionary[7].earthWord = "help";
    dictionary[7].alienWord = "zink";
    
    dictionary[8].earthWord = "peace";
    dictionary[8].alienWord = "trillok";
    
    dictionary[9].earthWord = "thank you";
    dictionary[9].alienWord = "zoobak";
}

void translateToAlien(char *input, AlienDictionary *dictionary) {
    char *token = strtok(input, " ");
    char translated[MAX_STRING_LENGTH] = "";

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ALIEN_VOCAB_SIZE; i++) {
            if (strcmp(token, dictionary[i].earthWord) == 0) {
                strcat(translated, dictionary[i].alienWord);
                strcat(translated, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translated, token);
            strcat(translated, " ");
        }
        token = strtok(NULL, " ");
    }

    printf("Translation: %s\n", translated);
}

void translateToEarth(char *input, AlienDictionary *dictionary) {
    char *token = strtok(input, " ");
    char translated[MAX_STRING_LENGTH] = "";

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < ALIEN_VOCAB_SIZE; i++) {
            if (strcmp(token, dictionary[i].alienWord) == 0) {
                strcat(translated, dictionary[i].earthWord);
                strcat(translated, " ");
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translated, token);
            strcat(translated, " ");
        }
        token = strtok(NULL, " ");
    }

    printf("Translation: %s\n", translated);
}

int main() {
    AlienDictionary dictionary[ALIEN_VOCAB_SIZE];
    initDictionary(dictionary);

    char input[MAX_STRING_LENGTH];
    int choice;

    printf("Welcome to the Alien Language Translator.\n");
    printf("1. Translate English to Alien\n");
    printf("2. Translate Alien to English\n");
    printf("Please select an option (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Clear the newline character from the input buffer

    if (choice == 1) {
        printf("Enter English text: ");
        fgets(input, MAX_STRING_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        translateToAlien(input, dictionary);
    } else if (choice == 2) {
        printf("Enter Alien text: ");
        fgets(input, MAX_STRING_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        translateToEarth(input, dictionary);
    } else {
        printf("Invalid option. Please restart the program.\n");
    }

    return 0;
}