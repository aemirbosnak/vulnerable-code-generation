//FormAI DATASET v1.0 Category: Spam Detection System ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Function to check for spam keywords
int isSpam(char *msg) {
    char spamWords[10][20] = { "free", "offer", "discount", "limited time", 
                                "stop", "cancel", "unsubscribe", "click", 
                                "make money", "earn money" };
    int numSpamWords = 10;
    int i, j;
    char tempMsg[100];
    
    strcpy(tempMsg, msg);
    
    // Convert all letters to lowercase
    for(i=0; i<strlen(tempMsg); i++) {
        if(tempMsg[i] >= 'A' && tempMsg[i] <= 'Z') {
            tempMsg[i] = tempMsg[i] + 32;
        }
    }
    
    // Check for spam keywords
    for(i=0; i<numSpamWords; i++) {
        if(strstr(tempMsg, spamWords[i]) != NULL) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char msg[100];
    
    printf("Welcome to the Spam Detection System!\n\n");
    
    // Get user input
    printf("Please enter your message: ");
    gets(msg);
    
    // Check for spam
    if(isSpam(msg)) {
        printf("\nWARNING! This message contains spam.\n");
    } else {
        printf("\nThis message is safe to send.\n");
    }
    
    printf("\nThank you for using the Spam Detection System!\n");

    return 0;
}