//Code Llama-13B DATASET v1.0 Category: Spam Detection System ; Style: happy
// Spam Detection System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a message
struct message {
    char* sender;
    char* recipient;
    char* subject;
    char* body;
};

// Function to read a message from a file
struct message read_message(FILE* fp) {
    struct message msg;
    char sender[100], recipient[100], subject[100], body[100];
    fscanf(fp, "%s %s %s %s", sender, recipient, subject, body);
    msg.sender = sender;
    msg.recipient = recipient;
    msg.subject = subject;
    msg.body = body;
    return msg;
}

// Function to classify a message as spam or not spam
int classify_message(struct message msg) {
    // Check if the message contains the word "VIAGRA"
    if (strstr(msg.body, "VIAGRA") != NULL) {
        return 1;
    }
    // Check if the message contains the word "FREE"
    if (strstr(msg.subject, "FREE") != NULL) {
        return 1;
    }
    // Check if the message contains the word "SEX"
    if (strstr(msg.body, "SEX") != NULL) {
        return 1;
    }
    // Check if the message contains the word "SCAM"
    if (strstr(msg.subject, "SCAM") != NULL) {
        return 1;
    }
    // If none of the above conditions are met, classify the message as not spam
    return 0;
}

// Main function
int main(void) {
    // Open the input file
    FILE* fp = fopen("spam_messages.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the first message
    struct message msg = read_message(fp);

    // Classify the message as spam or not spam
    int is_spam = classify_message(msg);

    // Print the result
    if (is_spam) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}