//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_BUFFER_SIZE 1024

struct mail {
    char *to;
    char *cc;
    char *subject;
    char *body;
};

int main() {
    // Allocate memory for email struct
    struct mail *email = malloc(sizeof(struct mail));
    
    // Declare variables for user input
    char buffer[MAX_BUFFER_SIZE];
    int option;
    int validInput = 0;
    
    // Prompt user for input
    printf("Email Client\n");
    printf("-------------\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Quit\n");
    printf("Select an option: ");
    
    // Validate and parse user input
    while(!validInput) {
        fgets(buffer, MAX_BUFFER_SIZE, stdin);
        if(sscanf(buffer, "%d", &option) == 1 && option >= 1 && option <= 3) {
            validInput = 1;
        }
        else {
            printf("Invalid input. Please select a valid option: ");
        }
    }
    
    // Handle user's selected option
    switch(option) {
        case 1:
            // Compose Email
            
            // Clear stdin buffer
            fseek(stdin, 0, SEEK_END);
            
            // Prompt for email recipients
            printf("\nTo: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            email->to = malloc((strlen(buffer)+1) * sizeof(char));
            strcpy(email->to, buffer);
            
            printf("Cc: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            email->cc = malloc((strlen(buffer)+1) * sizeof(char));
            strcpy(email->cc, buffer);
            
            // Prompt for email subject and body
            printf("Subject: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            email->subject = malloc((strlen(buffer)+1) * sizeof(char));
            strcpy(email->subject, buffer);
            
            printf("Body: ");
            fgets(buffer, MAX_BUFFER_SIZE, stdin);
            email->body = malloc((strlen(buffer)+1) * sizeof(char));
            strcpy(email->body, buffer);
            
            printf("\nEmail composed successfully!\n");
            break;
            
        case 2:
            // View Inbox
            printf("\nView Inbox\n");
            printf("------------\n");
            printf("No new emails.\n");
            break;
            
        case 3:
            // Quit
            printf("\nGoodbye!\n");
            free(email->to);
            free(email->cc);
            free(email->subject);
            free(email->body);
            free(email);
            exit(0);
            break;       
    }
    
    return 0;
}