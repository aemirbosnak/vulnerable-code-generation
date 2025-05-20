//Gemma-7B DATASET v1.0 Category: Email Client ; Style: medieval
#include <stdio.h>
#include <string.h>

// Define a structure to store email information
typedef struct Email {
    char sender[50];
    char recipient[50];
    char subject[50];
    char message[1000];
} Email;

// Function to read email from a file
Email readEmail(char *filename) {
    Email email;
    FILE *file = fopen(filename, "r");

    // Read sender, recipient, subject, and message from the file
    fscanf(file, "%s", email.sender);
    fscanf(file, "%s", email.recipient);
    fscanf(file, "%s", email.subject);
    fscanf(file, "%[^\n]", email.message);

    fclose(file);

    return email;
}

// Function to write email to a file
void writeEmail(Email email) {
    FILE *file = fopen(email.recipient, "w");

    // Write sender, recipient, subject, and message to the file
    fprintf(file, "%s\n", email.sender);
    fprintf(file, "%s\n", email.recipient);
    fprintf(file, "%s\n", email.subject);
    fprintf(file, "%s\n", email.message);

    fclose(file);
}

int main() {
    // Create an email structure
    Email email;

    // Read email from a file
    email = readEmail("email.txt");

    // Print email information
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);

    // Write email to a file
    writeEmail(email);

    return 0;
}