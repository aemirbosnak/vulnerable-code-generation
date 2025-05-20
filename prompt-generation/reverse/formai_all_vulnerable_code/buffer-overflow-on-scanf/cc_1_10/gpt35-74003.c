//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is a Cat Language translator program that takes in a string of words spoken by a cat 
 * and translates it into human language. It uses a database of known cat sounds and their meanings
 * to translate the input.
 */

int main() {
    char cat_sound[20];
    char translation[1000] = "";
    int exit_flag = 0;

    printf("Welcome to the Cat Language Translator!\n");
    printf("Type 'quit' to exit the program.\n\n");

    while (!exit_flag) {
        printf("Enter a sound that the cat makes: ");
        scanf("%s", cat_sound);

        // Check if user wants to exit the program
        if (strcmp(cat_sound, "quit") == 0) {
            exit_flag = 1;
            continue;
        }

        // Start of translation
        if (strcmp(cat_sound, "meow") == 0) {
            strcat(translation, "Hello! ");
        }
        else if (strcmp(cat_sound, "purr") == 0) {
            strcat(translation, "I'm feeling content. ");
        }
        else if (strcmp(cat_sound, "hiss") == 0) {
            strcat(translation, "I'm feeling threatened. ");
        }
        else if (strcmp(cat_sound, "yowl") == 0) {
            strcat(translation, "I'm feeling distressed. ");
        }
        else if (strcmp(cat_sound, "chirp") == 0) {
            strcat(translation, "I want attention. ");
        }
        else {
            strcat(translation, "I don't know what that means. ");
        }

        // Print out translation
        printf("%s\n\n", translation);

        // Reset translation for next input
        strcpy(translation, "");
    }

    printf("Exiting Cat Language Translator.\n");

    return 0;
}