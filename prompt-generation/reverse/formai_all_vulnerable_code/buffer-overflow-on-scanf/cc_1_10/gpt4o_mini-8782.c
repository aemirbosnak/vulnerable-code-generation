//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_LENGTH 256
#define SPAM_THRESHOLD 5

// Structure to hold message data
typedef struct {
    char text[MAX_LENGTH];
    int spamScore;
} Message;

// Function prototypes
void toLowerCase(char *str);
int calculateSpamScore(const char *message);
void scanMessages(Message messages[], int count);
void classifySpam(Message messages[], int count);
void displayResults(Message messages[], int count);

int main() {
    Message messages[MAX_MESSAGES];
    int messageCount;

    printf("Welcome to the Shape-shifting Spam Detection System!\n");
    printf("Please enter the number of messages (max 100): ");
    scanf("%d", &messageCount);
    getchar();  // Consume newline after the integer input

    // Input messages
    for (int i = 0; i < messageCount; i++) {
        printf("Enter message %d: ", i + 1);
        fgets(messages[i].text, sizeof(messages[i].text), stdin);
        messages[i].text[strcspn(messages[i].text, "\n")] = 0; // Remove newline
    }

    // Scan messages for spam
    scanMessages(messages, messageCount);
    classifySpam(messages, messageCount);
    displayResults(messages, messageCount);

    return 0;
}

// Convert a string to lower case
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Calculate spam score based on certain keywords
int calculateSpamScore(const char *message) {
    const char *spamKeywords[] = {"buy", "discount", "free", "limited", "offer", "win", "winner", "money"};
    int score = 0;
    
    // Check for each keyword
    for (int i = 0; i < sizeof(spamKeywords) / sizeof(spamKeywords[0]); i++) {
        if (strstr(message, spamKeywords[i]) != NULL) {
            score++;
        }
    }
    
    return score;
}

// Scan messages and determine their spam score
void scanMessages(Message messages[], int count) {
    for (int i = 0; i < count; i++) {
        toLowerCase(messages[i].text); // Transform the message to lower case
        messages[i].spamScore = calculateSpamScore(messages[i].text);
    }
}

// Classify the messages as spam or not
void classifySpam(Message messages[], int count) {
    for (int i = 0; i < count; i++) {
        if (messages[i].spamScore >= SPAM_THRESHOLD) {
            printf("Message %d is classified as SPAM.\n", i + 1);
        } else {
            printf("Message %d is classified as NOT SPAM.\n", i + 1);
        }
    }
}

// Display all messages with their scores
void displayResults(Message messages[], int count) {
    printf("\nSummary of Messages:\n");
    for (int i = 0; i < count; i++) {
        printf("Message %d: [%s] - Spam Score: %d\n", i + 1, messages[i].text, messages[i].spamScore);
    }
}