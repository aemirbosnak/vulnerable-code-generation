//FormAI DATASET v1.0 Category: Email Client ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAILS 100 // Maximum Number of Emails

struct Email {
    char from[50];
    char to[50];
    char cc[50];
    char bcc[50];
    char subject[100];
    char message[1000];
};

struct Email emails[MAX_EMAILS]; // Array of Emails
int totalEmails = 0; // Counter to keep track of total emails in the array

// Function to add new email to the array
void addEmail() {
    struct Email newEmail;
    printf("Enter From Email Address: ");
    scanf("%s", newEmail.from);
    printf("Enter To Email Address: ");
    scanf("%s", newEmail.to);
    printf("Enter CC Email Address: ");
    scanf("%s", newEmail.cc);
    printf("Enter BCC Email Address: ");
    scanf("%s", newEmail.bcc);
    printf("Enter Subject: ");
    scanf("%s", newEmail.subject);
    printf("Enter Message: ");
    scanf("%s", newEmail.message);
    
    emails[totalEmails++] = newEmail;
    printf("Email Added Successfully!\n");
}

// Function to display the list of emails
void displayEmails() {
    if(totalEmails == 0) {
        printf("No Emails Found!\n");
    } else {
        printf("List of Emails:\n\n");
        for(int i = 0; i < totalEmails; i++) {
            printf("Email %d\n", i+1);
            printf("From       : %s\n", emails[i].from);
            printf("To         : %s\n", emails[i].to);
            printf("CC         : %s\n", emails[i].cc);
            printf("BCC        : %s\n", emails[i].bcc);
            printf("Subject    : %s\n", emails[i].subject);
            printf("Message    : %s\n", emails[i].message);
            printf("\n");
        }
    }
}

int main() {
    int choice;
    do {
        printf("\n********** C EMAIL CLIENT **********\n\n");
        printf("1. New Email\n");
        printf("2. View Emails\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addEmail();
                break;
            case 2:
                displayEmails();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}