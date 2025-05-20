//FormAI DATASET v1.0 Category: Email Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char sender[50];
    char recipients[50][50];
    char subject[100];
    char body[1000];
};

int main() {
    struct email my_email;
    char choice;
    int num_recipients = 0;
    
    printf("Welcome to My Email Client!\n\n");
    
    // get user input for email content
    printf("Please enter the sender's email address: ");
    scanf("%s", my_email.sender);
    
    // get recipient information
    while (num_recipients < 10) {
        printf("Enter recipient email address (or 'q' to quit): ");
        scanf(" %c", &choice);
        if (choice == 'q') {
            break;
        }
        strcpy(my_email.recipients[num_recipients], &choice);      
        num_recipients++;
    }
    
    // get subject and body
    printf("Enter the email subject: ");
    scanf(" %[^\n]", my_email.subject);
    
    printf("Enter the body of the email: ");
    scanf(" %[^\n]", my_email.body);
    
    // display email information
    printf("\nEmail Information:\n");
    printf("Sender: %s\n", my_email.sender);
    printf("Recipients:\n");
    for (int i=0; i<num_recipients; i++) {
        printf("- %s\n", my_email.recipients[i]);
    }
    printf("Subject: %s\n", my_email.subject);
    printf("Body: %s\n", my_email.body);
    
    printf("Email sent successfully!\n");
    
    return 0;
}