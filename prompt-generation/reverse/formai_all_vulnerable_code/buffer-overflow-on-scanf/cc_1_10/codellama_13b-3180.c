//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: shape shifting
// Email Client in a Shape-Shifting Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold email information
struct Email {
    char* subject;
    char* sender;
    char* recipient;
    char* body;
};

// Function to read an email from the console
void readEmail(struct Email* email) {
    printf("Enter the subject: ");
    fgets(email->subject, 100, stdin);
    printf("Enter the sender: ");
    fgets(email->sender, 100, stdin);
    printf("Enter the recipient: ");
    fgets(email->recipient, 100, stdin);
    printf("Enter the body: ");
    fgets(email->body, 1000, stdin);
}

// Function to send an email
void sendEmail(struct Email* email) {
    printf("Sending email to %s...\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Sender: %s\n", email->sender);
    printf("Body: %s\n", email->body);
}

// Function to read an email from a file
void readEmailFromFile(struct Email* email, char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    fscanf(fp, "%s", email->subject);
    fscanf(fp, "%s", email->sender);
    fscanf(fp, "%s", email->recipient);
    fscanf(fp, "%s", email->body);
    fclose(fp);
}

// Function to send an email from a file
void sendEmailFromFile(struct Email* email, char* filename) {
    printf("Sending email from file %s...\n", filename);
    printf("Subject: %s\n", email->subject);
    printf("Sender: %s\n", email->sender);
    printf("Recipient: %s\n", email->recipient);
    printf("Body: %s\n", email->body);
}

int main() {
    struct Email email;
    char filename[100];
    int choice;

    // Read email from console
    readEmail(&email);

    // Send email
    sendEmail(&email);

    // Read email from file
    printf("Enter the filename: ");
    scanf("%s", filename);
    readEmailFromFile(&email, filename);

    // Send email from file
    sendEmailFromFile(&email, filename);

    return 0;
}