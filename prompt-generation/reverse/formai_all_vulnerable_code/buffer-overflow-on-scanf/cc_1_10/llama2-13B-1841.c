//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 25
#define MAX_PHONE_NUMBER_LENGTH 10

// Global variables
const char *const ROMANCE_MESSAGES[] = {
    "My love, you are the sunshine that brightens up my day.",
    "You are the star that guides me through the night.",
    "With you, every moment is a beautiful dream come true.",
    "Forever and always, my heart belongs to you.",
};

int main() {
    // Declare variables
    int choice;
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
    int i;

    // Print romantic messages
    for (i = 0; i < sizeof(ROMANCE_MESSAGES) / sizeof(ROMANCE_MESSAGES[0]); i++) {
        printf("%s\n", ROMANCE_MESSAGES[i]);
    }

    // Ask user for name and phone number
    printf("What is your name, my love? ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("And what is your phone number? ");
    fgets(phoneNumber, MAX_PHONE_NUMBER_LENGTH, stdin);

    // Print romantic message with name and phone number
    printf("My love, you are the %s who brings joy to my life. May I have the pleasure of calling you at %s?\n", name, phoneNumber);

    // Ask user for choice
    printf("Would you like to hear another message? (1 for yes, 2 for no)\n");
    scanf("%d", &choice);

    // Loop based on user's choice
    while (choice == 1) {
        // Print another romantic message
        for (i = 0; i < sizeof(ROMANCE_MESSAGES) / sizeof(ROMANCE_MESSAGES[0]); i++) {
            printf("%s\n", ROMANCE_MESSAGES[i]);
        }

        // Ask user for choice again
        printf("Would you like to hear another message? (1 for yes, 2 for no)\n");
        scanf("%d", &choice);
    }

    return 0;
}