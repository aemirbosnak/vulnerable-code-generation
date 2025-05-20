//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

typedef struct {
    char message[MAX_LENGTH];
} Message;

typedef struct {
    Message messages[MAX_MESSAGES];
    int count;
} MessageList;

// Function to initialize the message list
void initializeMessageList(MessageList *list) {
    list->count = 0;
}

// Function to add a message to the list
bool addMessage(MessageList *list, const char *msg) {
    if (list->count >= MAX_MESSAGES) {
        printf("Message list is full. Cannot add more messages.\n");
        return false;
    }
    strncpy(list->messages[list->count].message, msg, MAX_LENGTH - 1);
    list->messages[list->count].message[MAX_LENGTH - 1] = '\0'; // Ensure null termination
    list->count++;
    return true;
}

// Function to check if a message is spam
bool isSpam(const char *msg) {
    // Define simple spam keywords
    const char *spamKeywords[] = {
        "free", "money", "click here", "visit now", "limited time offer",
        "buy now", "winner", "urgent", "exclusive deal", NULL
    };

    // Check for each spam keyword
    for (int i = 0; spamKeywords[i] != NULL; i++) {
        if (strstr(msg, spamKeywords[i]) != NULL) {
            return true;
        }
    }
    return false;
}

// Function to analyze the message list for spam
void analyzeMessages(MessageList *list) {
    printf("\nSpam Detection Results:\n");
    for (int i = 0; i < list->count; i++) {
        if (isSpam(list->messages[i].message)) {
            printf("SPAM: %s\n", list->messages[i].message);
        } else {
            printf("NOT SPAM: %s\n", list->messages[i].message);
        }
    }
}

// Function to display a menu and get the user's choice
int displayMenu() {
    int choice;
    printf("\n--- Spam Detection System ---\n");
    printf("1. Add Message\n");
    printf("2. Analyze Messages\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // To discard the newline character left by scanf
    return choice;
}

// Main function
int main() {
    MessageList list;
    initializeMessageList(&list);
    int choice;

    while (true) {
        choice = displayMenu();
        if (choice == 1) {
            char msg[MAX_LENGTH];
            printf("Enter message (max %d characters): ", MAX_LENGTH - 1);
            fgets(msg, sizeof(msg), stdin);
            msg[strcspn(msg, "\n")] = 0; // Remove the newline character
            if (addMessage(&list, msg)) {
                printf("Message added successfully!\n");
            }
        } else if (choice == 2) {
            if (list.count == 0) {
                printf("No messages to analyze. Add messages first.\n");
            } else {
                analyzeMessages(&list);
            }
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}