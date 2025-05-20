//FormAI DATASET v1.0 Category: Email Client ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold the email details
struct email {
    char from[100];
    char to[100];
    char subject[200];
    char message[500];
};

//Function to display all the emails in the inbox
void display_emails(struct email *emails, int count) {
    if(count == 0) {
        printf("No emails found!\n");
    }
    else {
        printf("------------------------------------------------------------------------\n");
        printf("| %-10s | %-30s | %-50s |\n", "From", "To", "Subject");
        printf("------------------------------------------------------------------------\n");
        for(int i=0;i<count;i++) {
            printf("| %-10s | %-30s | %-50s |\n", emails[i].from, emails[i].to, emails[i].subject); 
        }
        printf("------------------------------------------------------------------------\n");
    }
}

int main() {
    int choice, count=0;
    struct email *emails = malloc(100*sizeof(struct email));
    do {
        printf("------------------------------------------------------\n");
        printf("Welcome to the C Email Client!\n");
        printf("------------------------------------------------------\n");
        printf("1. Compose Email\n");
        printf("2. View Inbox\n");
        printf("3. Exit\n");
        printf("------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("------------------------------------------------------\n");
                printf("Compose Email\n");
                printf("------------------------------------------------------\n");
                printf("From: ");
                scanf("%s", emails[count].from);
                printf("To: ");
                scanf("%s", emails[count].to);
                printf("Subject: ");
                scanf("%s", emails[count].subject);
                printf("Message: ");
                scanf("%s", emails[count].message);
                count++;
                printf("Email Sent!\n");
                printf("------------------------------------------------------\n");
                break;
            case 2:
                printf("------------------------------------------------------\n");
                printf("Inbox\n");
                printf("------------------------------------------------------\n");
                display_emails(emails, count);
                printf("------------------------------------------------------\n");
                break;
            case 3:
                printf("Exiting C Email Client...\n");
                free(emails);
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    } while(choice != 3);
    return 0;
}