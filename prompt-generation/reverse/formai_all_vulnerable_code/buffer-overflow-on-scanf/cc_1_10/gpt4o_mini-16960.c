//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256

// Function declarations
void analyzeMessages(char messages[MAX_MESSAGES][MAX_LENGTH], int index, int count);
int isSpam(char *message);
void displayResults(int spamCount, int totalCount);
void convertToLower(char *str);

// Main function
int main() {
    char messages[MAX_MESSAGES][MAX_LENGTH];
    int count = 0;

    printf("Enter the number of messages (max %d): ", MAX_MESSAGES);
    scanf("%d", &count);
    getchar(); // Clear the newline character from the input buffer

    if (count > MAX_MESSAGES || count <= 0) {
        printf("Invalid number of messages. Please enter a number between 1 and %d.\n", MAX_MESSAGES);
        return 1;
    }

    printf("Please enter the messages:\n");
    for (int i = 0; i < count; i++) {
        fgets(messages[i], MAX_LENGTH, stdin);
        // Remove newline character at the end of the message
        messages[i][strcspn(messages[i], "\n")] = 0;
    }

    // Analyze messages
    analyzeMessages(messages, 0, count);

    return 0;
}

// Recursive function to analyze messages
void analyzeMessages(char messages[MAX_MESSAGES][MAX_LENGTH], int index, int count) {
    if (index >= count) {
        return;
    }

    int spamCount = isSpam(messages[index]);
    if (spamCount) {
        printf("Message %d: [SPAM] %s\n", index + 1, messages[index]);
    } else {
        printf("Message %d: [NOT SPAM] %s\n", index + 1, messages[index]);
    }

    analyzeMessages(messages, index + 1, count);
}

// Function to check if a message is spam
int isSpam(char *message) {
    const char *spamWords[] = {"money", "win", "free", "click", "subscribe", "offer", "buy now"};
    int spamCount = 0;

    // Convert message to lower case for case insensitive comparison
    char tempMessage[MAX_LENGTH];
    strcpy(tempMessage, message);
    convertToLower(tempMessage);

    // Count the spam words
    for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
        if (strstr(tempMessage, spamWords[i]) != NULL) {
            spamCount++;
        }
    }

    // Threshold for considering the message as spam
    return (spamCount >= 1) ? 1 : 0;
}

// Utility function to convert a string to lower case
void convertToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}