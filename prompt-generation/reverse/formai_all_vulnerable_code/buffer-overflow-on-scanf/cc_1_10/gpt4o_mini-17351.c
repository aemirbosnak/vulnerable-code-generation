//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_MSG_LENGTH 256
#define SPAM_KEYWORDS 10

// Struct representing a message with some attributes
typedef struct {
    char content[MAX_MSG_LENGTH];
    int spamScore;
} Message;

// List of predefined spam keywords
const char *spamKeywords[SPAM_KEYWORDS] = {
    "win", "free", "winner", "click", "login", 
    "urgent", "risk-free", "offer", "prize", "money"
};

// Function to clean the message content
void cleanMessage(char *msg) {
    char cleanedMsg[MAX_MSG_LENGTH];
    int j = 0;
    for (int i = 0; msg[i] != '\0'; i++) {
        if (isalnum(msg[i]) || isspace(msg[i])) {
            cleanedMsg[j++] = tolower(msg[i]);
        }
    }
    cleanedMsg[j] = '\0';
    strcpy(msg, cleanedMsg);
}

// Function to calculate spam score based on keywords
int calculateSpamScore(const char *msg) {
    int score = 0;
    for (int i = 0; i < SPAM_KEYWORDS; i++) {
        if (strstr(msg, spamKeywords[i]) != NULL) {
            score++;
        }
    }
    return score;
}

// Function to determine if the message is spam based on spam score
bool isSpam(const Message *message) {
    return message->spamScore > 2; // Threshold for spam
}

// Function to get user messages
void getUserMessages(Message *messages, int *numMessages) {
    printf("Enter the number of messages to analyze (max %d): ", MAX_MSG_LENGTH);
    scanf("%d", numMessages);
    getchar(); // To consume newline character

    for (int i = 0; i < *numMessages; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i].content, MAX_MSG_LENGTH, stdin);
        
        // Remove newline character
        size_t len = strlen(messages[i].content);
        if (len > 0 && messages[i].content[len - 1] == '\n') {
            messages[i].content[len - 1] = '\0';
        }

        cleanMessage(messages[i].content);
        messages[i].spamScore = calculateSpamScore(messages[i].content);
        printf("Spam Score for message %d: %d\n", i + 1, messages[i].spamScore);
    }
}

// Function to show spam results
void showResults(const Message *messages, int numMessages) {
    printf("\nSpam Detection Results:\n");
    for (int i = 0; i < numMessages; i++) {
        printf("Message %d: [%s] - %s\n", i + 1, messages[i].content, 
               isSpam(&messages[i]) ? "Detected as Spam" : "Not Spam");
    }
}

int main() {
    Message messages[MAX_MSG_LENGTH];
    int numMessages;

    printf("Welcome to the Spam Detection System!\n");
    
    getUserMessages(messages, &numMessages);
    showResults(messages, numMessages);

    printf("\nThank you for using the Spam Detection System. Goodbye!\n");
    return 0;
}