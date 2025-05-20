//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to send an email
void sendEmail(char *to, char *subject, char *message) {
    FILE *fp;
    char email[100];
    char subjectString[100];
    char messageString[100];

    // Convert subject and message to string
    strcpy(subjectString, subject);
    strcpy(messageString, message);

    // Create email
    sprintf(email, "From: %s\nTo: %s\nSubject: %s\n\n%s", "John Doe", to, subjectString, messageString);

    // Open email file
    fp = fopen("email.txt", "w");
    if (fp == NULL) {
        printf("Unable to open file for writing\n");
        exit(1);
    }

    // Write email to file
    fprintf(fp, "%s", email);
    fclose(fp);

    // Display message
    printf("Email sent successfully\n");
}

// Function to read email
void readEmail(char *fileName) {
    FILE *fp;
    char email[100];

    // Open email file
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Unable to open file for reading\n");
        exit(1);
    }

    // Read email from file
    fgets(email, sizeof(email), fp);
    printf("%s\n", email);

    // Close email file
    fclose(fp);
}

int main() {
    // Prompt user for recipient email address
    char to[100];
    printf("Enter recipient email address: ");
    scanf("%s", to);

    // Prompt user for subject
    char subject[100];
    printf("Enter subject: ");
    scanf("%s", subject);

    // Prompt user for message
    char message[100];
    printf("Enter message: ");
    scanf("%s", message);

    // Send email
    sendEmail(to, subject, message);

    // Read email
    readEmail("email.txt");

    return 0;
}