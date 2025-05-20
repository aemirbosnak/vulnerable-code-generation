//GPT-4o-mini DATASET v1.0 Category: Spam Detection System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGES 100
#define MAX_WORD_LENGTH 100

// Structure to hold messages
typedef struct {
    char text[256];
} Message;

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if the message is spam based on predefined keywords
int isSpam(Message msg) {
    const char *spamKeywords[] = {
        "win", "free", "winner", "cash", "urgent", "call now", 
        "subscribe", "limited time", "act now", "prize"
    };

    // Check for spam keywords
    char temp[256];
    strcpy(temp, msg.text);
    toLowerCase(temp);
    
    for (int i = 0; i < sizeof(spamKeywords) / sizeof(spamKeywords[0]); i++) {
        if (strstr(temp, spamKeywords[i]) != NULL) {
            return 1; // Message is spam
        }
    }
    
    return 0; // Message is not spam
}

// Function to take input messages
void inputMessages(Message messages[], int count) {
    printf("Enter %d messages:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Message %d: ", i + 1);
        fgets(messages[i].text, sizeof(messages[i].text), stdin);
        // Remove newline character if present
        messages[i].text[strcspn(messages[i].text, "\n")] = 0;
    }
}

// Function to display messages and their Spam status
void displayMessages(Message messages[], int count) {
    printf("\nMessage Status:\n");
    for (int i = 0; i < count; i++) {
        printf("Message %d: '%s' - %s\n", 
               i + 1, messages[i].text, isSpam(messages[i]) ? "SPAM" : "NOT SPAM");
    }
}

int main() {
    Message messages[MAX_MESSAGES];
    int numMessages;

    // Input the number of messages
    printf("How many messages would you like to enter (max %d)? ", MAX_MESSAGES);
    scanf("%d", &numMessages);
    getchar(); // To consume newline from input buffer

    if (numMessages > MAX_MESSAGES) {
        printf("Error: Number of messages exceeds the maximum limit.\n");
        return 1;
    }

    inputMessages(messages, numMessages);
    displayMessages(messages, numMessages);

    return 0;
}