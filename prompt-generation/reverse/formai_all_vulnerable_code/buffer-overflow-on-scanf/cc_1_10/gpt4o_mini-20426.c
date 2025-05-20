//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGES 8

void displayGratitude(unsigned char messages);
void addGratitude(unsigned char *messages, int index);
void removeGratitude(unsigned char *messages, int index);
void toggleGratitude(unsigned char *messages, int index);
void displayMessage(unsigned char messages, int index);

int main() {
    unsigned char gratitudeMessages = 0; // Initialize gratitude tracker

    printf("Welcome to the Gratitude Tracker!\n\n");

    while (1) {
        printf("Choose an option:\n");
        printf("1. Add a gratitude message\n");
        printf("2. Remove a gratitude message\n");
        printf("3. Toggle a gratitude message\n");
        printf("4. Display all gratitude messages\n");
        printf("5. Exit\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                printf("Enter message index to add (0-%d): ", MAX_MESSAGES - 1);
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < MAX_MESSAGES) {
                    addGratitude(&gratitudeMessages, index);
                    printf("Message added successfully!\n\n");
                } else {
                    printf("Invalid index. Please try again.\n\n");
                }
                break;
            }
            case 2: {
                printf("Enter message index to remove (0-%d): ", MAX_MESSAGES - 1);
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < MAX_MESSAGES) {
                    removeGratitude(&gratitudeMessages, index);
                    printf("Message removed successfully!\n\n");
                } else {
                    printf("Invalid index. Please try again.\n\n");
                }
                break;
            }
            case 3: {
                printf("Enter message index to toggle (0-%d): ", MAX_MESSAGES - 1);
                int index;
                scanf("%d", &index);
                if (index >= 0 && index < MAX_MESSAGES) {
                    toggleGratitude(&gratitudeMessages, index);
                    printf("Message toggled successfully!\n\n");
                } else {
                    printf("Invalid index. Please try again.\n\n");
                }
                break;
            }
            case 4: {
                displayGratitude(gratitudeMessages);
                break;
            }
            case 5: {
                printf("Thank you for using the Gratitude Tracker! Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n\n");
                break;
            }
        }
    }
    
    return 0;
}

void displayGratitude(unsigned char messages) {
    printf("Current gratitude messages:\n");
    for (int i = 0; i < MAX_MESSAGES; i++) {
        displayMessage(messages, i);
    }
    printf("\n");
}

void addGratitude(unsigned char *messages, int index) {
    *messages |= (1 << index);
}

void removeGratitude(unsigned char *messages, int index) {
    *messages &= ~(1 << index);
}

void toggleGratitude(unsigned char *messages, int index) {
    *messages ^= (1 << index);
}

void displayMessage(unsigned char messages, int index) {
    if (messages & (1 << index)) {
        printf("  - Gratitude message %d is enabled\n", index);
    } else {
        printf("  - Gratitude message %d is disabled\n", index);
    }
}