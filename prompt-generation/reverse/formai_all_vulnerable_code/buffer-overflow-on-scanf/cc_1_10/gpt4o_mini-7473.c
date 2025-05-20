//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_LENGTH 256
#define MAX_WORDS 50

void addSweetMessage(char *message, const char *addition) {
    strncat(message, " ", MAX_MSG_LENGTH - strlen(message) - 1);
    strncat(message, addition, MAX_MSG_LENGTH - strlen(message) - 1);
}

void createLoveLetter(char *addressed_to, char *sender) {
    char love_message[MAX_MSG_LENGTH] = "My dearest ";
    strcat(love_message, addressed_to);
    
    addSweetMessage(love_message, "Every moment without you feels like a lifetime.");
    addSweetMessage(love_message, "Your smile brightens my darkest days.");
    addSweetMessage(love_message, "With every heartbeat, I fall deeper in love with you.");
    addSweetMessage(love_message, "You are my sunshine on a cloudy day.");
    addSweetMessage(love_message, "I cherish every moment we spend together.");
    addSweetMessage(love_message, "You complete me in every way possible.");
    addSweetMessage(love_message, "With all my love,");
    addSweetMessage(love_message, sender);
    
    printf("\nDear %s,\n\n%s\n", addressed_to, love_message);
}

void displayMenu() {
    printf("---------- Love Letter Generator ----------\n");
    printf("1. Create a love letter\n");
    printf("2. Exit\n");
    printf("------------------------------------------\n");
}

int main() {
    char addressed_to[50];
    char sender[50];
    int choice;
    
    printf("Welcome to the Love Letter Generator!\n");
    printf("Please enter the name of your beloved: ");
    fgets(addressed_to, sizeof(addressed_to), stdin);
    addressed_to[strcspn(addressed_to, "\n")] = 0; // Remove newline character

    printf("Please enter your name: ");
    fgets(sender, sizeof(sender), stdin);
    sender[strcspn(sender, "\n")] = 0; // Remove newline character

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createLoveLetter(addressed_to, sender);
                break;
            case 2:
                printf("Thank you for using the Love Letter Generator. Spread the love!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);
    
    return 0;
}