//Falcon-180B DATASET v1.0 Category: Email Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 50
#define MAX_SUBJECT_LENGTH 100

// Struct to hold email data
typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_LINE_LENGTH];
} Email;

// Function to remove leading/trailing whitespace from a string
void trim(char* str) {
    char* end = str + strlen(str) - 1;
    while (isspace(*end)) {
        *end-- = '\0';
    }
}

// Function to parse an email from a string
Email parseEmail(char* emailStr) {
    Email email;
    char* from = strtok(emailStr, ":");
    trim(from);
    strcpy(email.from, from);

    char* to = strtok(NULL, ":");
    trim(to);
    strcpy(email.to, to);

    char* subject = strtok(NULL, ":");
    trim(subject);
    strcpy(email.subject, subject);

    char* body = strtok(NULL, "\r\n");
    trim(body);
    strcpy(email.body, body);

    return email;
}

// Function to send an email
void sendEmail(Email email) {
    printf("Sending email from %s to %s with subject %s:\n%s\n", email.from, email.to, email.subject, email.body);
}

// Function to save an email to a file
void saveEmail(Email email, FILE* file) {
    fprintf(file, "From: %s\nTo: %s\nSubject: %s\n\n%s\n", email.from, email.to, email.subject, email.body);
}

// Function to load emails from a file
Email loadEmail(FILE* file) {
    Email email;
    fscanf(file, "From: %[^\n]\nTo: %[^\n]\nSubject: %[^\n]\n\n%[^\n]", email.from, email.to, email.subject, email.body);
    return email;
}

// Main function
int main() {
    // Open input file
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Loop through input file
    Email email;
    while (fscanf(inputFile, "%[^\n]\n", email.from)!= EOF) {
        // Parse email
        email = parseEmail(email.from);

        // Save email to output file
        saveEmail(email, outputFile);

        // Send email
        sendEmail(email);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}