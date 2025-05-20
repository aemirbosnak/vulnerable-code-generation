//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    char email[50], password[20];
    printf("Welcome to MyEmailClient\n\n");
    printf("Please enter your email address: ");
    fgets(email, 50, stdin);
    strtok(email, "\n"); // remove newline character from email
    
    printf("Please enter your password: ");
    fgets(password, 20, stdin);
    strtok(password, "\n"); // remove newline character from password
    
    printf("\nConnecting to email server...\n");
    // code to connect to email server
    
    printf("\nConnected to email server successfully!\n\n");
    
    while(1) {
        printf("1. Inbox\n");
        printf("2. Compose new email\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        clearBuffer(); // clear input buffer
        
        switch(choice) {
            case 1:
                printf("\nFetching inbox...\n");
                // code to fetch inbox
                printf("\nInbox:\n");
                // code to display inbox
                break;
            case 2:
                printf("\nCompose new email:\n");
                
                char to[50], subject[100], body[500];
                printf("To: ");
                fgets(to, 50, stdin);
                strtok(to, "\n"); // remove newline character from to
                
                printf("Subject: ");
                fgets(subject, 100, stdin);
                strtok(subject, "\n"); // remove newline character from subject
                
                printf("Body: ");
                fgets(body, 500, stdin);
                strtok(body, "\n"); // remove newline character from body
                
                printf("\nSending email...\n");
                // code to send email
                printf("\nEmail sent successfully!\n");
                break;
            case 3:
                printf("\nThank you for using MyEmailClient. Goodbye!\n");
                exit(0); // exit program
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}