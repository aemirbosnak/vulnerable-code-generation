//FormAI DATASET v1.0 Category: Spam Detection System ; Style: calm
#include<stdio.h>
#include<string.h>

#define SPAM_THRESHOLD 5 // Threshold value to detect spam messages

// Struct to store message information
struct Message {
    char text[100];
    int count;
};

// Function to check if a string is present in the message list
int isPresent(char *text, struct Message *messages, int count) {
    for(int i=0; i<count; i++) {
        if(strcmp(messages[i].text, text) == 0) {
            messages[i].count++;
            return messages[i].count;
        }
    }
    return 0;
}

int main() {
    int n; // Number of messages
    struct Message messages[100]; // Array to store messages and their count
    int spamCounter = 0; // Counter to keep track of spam messages
    
    // Taking input of messages' count
    printf("Enter number of messages: ");
    scanf("%d", &n);
    
    // Taking input of messages and checking if they're spam
    for(int i=0; i<n; i++) {
        char text[100]; // Variable to store each message
        scanf("%s", text);
        int count = isPresent(text, messages, i); // Check if message is already present in the array and increment its count if it is
        if(count >= SPAM_THRESHOLD) { // If message count is greater than or equal to the spam threshold, mark it as spam
            printf("Message %d is spam!\n", i+1);
            spamCounter++;
        }
        else { // Otherwise, add the message to the array with a count of 1
            strcpy(messages[i].text, text);
            messages[i].count = 1;
        }
    }
    
    // Print total number of spam messages
    printf("%d spam messages were detected.\n", spamCounter);
    
    return 0;
}