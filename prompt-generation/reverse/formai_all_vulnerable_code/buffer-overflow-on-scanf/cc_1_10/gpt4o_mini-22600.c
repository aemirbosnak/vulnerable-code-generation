//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constants
#define MAX_MESSAGES 100
#define MAX_LENGTH 500
#define MAX_KEYWORDS 10

// Function prototypes
void toLowerCase(char *str);
int isSpam(char *message, char spamKeywords[][MAX_LENGTH], int keywordCount);
void printMenu();
void readMessages(char messages[][MAX_LENGTH], int *messageCount);
void analyzeMessages(char messages[][MAX_LENGTH], int messageCount, char spamKeywords[][MAX_LENGTH], int keywordCount);

// Spam keywords array
char spamKeywords[MAX_KEYWORDS][MAX_LENGTH] = {
    "win", "free", "click", "money", "prize", 
    "offer", "winner", "urgent", "limited", "congratulations"
};

// Main function
int main() {
    char messages[MAX_MESSAGES][MAX_LENGTH];
    int messageCount = 0;

    // Print welcome message
    printf("========================================\n");
    printf("    Welcome to the Spam Detection System\n");
    printf("========================================\n");

    // Read messages from user
    readMessages(messages, &messageCount);

    // Analyze the messages for spam
    analyzeMessages(messages, messageCount, spamKeywords, MAX_KEYWORDS);

    return 0;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a message contains spam
int isSpam(char *message, char spamKeywords[][MAX_LENGTH], int keywordCount) {
    int spamCount = 0;

    // Convert message to lower case for comparison
    char tempMessage[MAX_LENGTH];
    strcpy(tempMessage, message);
    toLowerCase(tempMessage);

    // Check for each spam keyword
    for (int i = 0; i < keywordCount; i++) {
        if (strstr(tempMessage, spamKeywords[i]) != NULL) {
            spamCount++;
        }
    }

    // Return spam count
    return spamCount;
}

// Function to print the menu
void printMenu() {
    printf("1. Add Message\n");
    printf("2. Analyze Messages\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to read messages from user
void readMessages(char messages[][MAX_LENGTH], int *messageCount) {
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline after scanf

        switch (choice) {
            case 1:
                if (*messageCount < MAX_MESSAGES) {
                    printf("Enter message: ");
                    fgets(messages[*messageCount], MAX_LENGTH, stdin);
                    // Remove newline character
                    messages[*messageCount][strcspn(messages[*messageCount], "\n")] = 0;
                    (*messageCount)++;
                } else {
                    printf("Message limit reached!\n");
                }
                break;
            case 2:
                // Leave this blank as we will be analyzing in different function
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 3);
}

// Function to analyze messages for spam
void analyzeMessages(char messages[][MAX_LENGTH], int messageCount, char spamKeywords[][MAX_LENGTH], int keywordCount) {
    printf("Analyzing messages for spam...\n");
    for (int i = 0; i < messageCount; i++) {
        int spamHits = isSpam(messages[i], spamKeywords, keywordCount);
        if (spamHits > 0) {
            printf("Message %d: Detected Spam! (Hits: %d)\n", i + 1, spamHits);
        } else {
            printf("Message %d: No Spam Detected.\n", i + 1);
        }
    }
}