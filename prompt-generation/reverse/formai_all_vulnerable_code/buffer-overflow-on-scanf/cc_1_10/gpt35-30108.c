//FormAI DATASET v1.0 Category: Email Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 100

// Struct for an email
typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    struct tm* timestamp;
    char sender[20];
    char receiver[20];
} Email;

// Function to print emails
void printEmails(Email emails[MAX_EMAILS], int numEmails) {
    printf("\nInbox:\n");
    for (int i = 0; i < numEmails; i++) {
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].receiver);
        printf("Timestamp: %s", asctime(emails[i].timestamp));
        printf("Subject: %s\n", emails[i].subject);
        printf("Message: %s\n\n", emails[i].message);
    }
}

int main() {
    Email emails[MAX_EMAILS]; // Array of emails
    int numEmails = 0; // Number of emails currently in inbox
    char input[100]; // User input for menu options
    int loop = 1; // Flag to stay in menu loop
    
    // Greetings
    printf("Welcome to Email Client!\n");
    printf("Created by Salvador Dali\n");
    
    // Main menu loop
    while (loop) {
        printf("\nMain Menu:\n");
        printf("1. Compose new email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n\n");
        printf("Please enter your choice: ");
        scanf("%s", input);
        getchar(); // Clear input buffer
        
        if (strcmp(input, "1") == 0) { // Compose new email
            Email newEmail; // New email to create
            
            printf("\nCompose Email:\n");
            printf("To: ");
            fgets(newEmail.receiver, 20, stdin);
            newEmail.receiver[strcspn(newEmail.receiver, "\n")] = 0; // Remove newline character
            
            printf("Subject: ");
            fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
            newEmail.subject[strcspn(newEmail.subject, "\n")] = 0; // Remove newline character
            
            printf("Message: ");
            fgets(newEmail.message, MAX_MESSAGE_LENGTH, stdin);
            newEmail.message[strcspn(newEmail.message, "\n")] = 0; // Remove newline character
            
            // Get timestamp of email
            time_t currTime = time(NULL);
            newEmail.timestamp = localtime(&currTime);
            
            // Set sender to "Yourself"
            strcpy(newEmail.sender, "Yourself");
            
            // Add email to inbox
            emails[numEmails] = newEmail;
            numEmails++;
            
            printf("\nEmail sent successfully!\n");
        }
        else if (strcmp(input, "2") == 0) { // View inbox
            printEmails(emails, numEmails);
        }
        else if (strcmp(input, "3") == 0) { // Exit
            loop = 0;
            printf("\nThank you for using Email Client, have a surreal day!\n");
        }
        else { // Invalid input
            printf("\nInvalid input, please try again.\n");
        }
    }
    
    return 0;
}