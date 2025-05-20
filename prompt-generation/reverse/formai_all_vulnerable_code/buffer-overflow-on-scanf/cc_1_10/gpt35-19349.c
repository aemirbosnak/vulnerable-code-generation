//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_EMAIL_LENGTH 500

typedef struct email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_EMAIL_LENGTH];
} Email;

void addEmail(Email emails[], int *num_of_emails);
void viewEmails(Email emails[], int num_of_emails);
void searchEmails(Email emails[], int num_of_emails);

int main() {
    Email emails[100]; // Assuming maximum of 100 emails can be stored
    int num_of_emails = 0;
    int menu_option = 0;
    
    printf("\n*** Welcome to the email client ***\n");
    
    while(menu_option != 4) {
        printf("\n--- Main Menu ---\n");
        printf("1 - Add an email\n");
        printf("2 - View all emails\n");
        printf("3 - Search emails\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_option);
        
        switch(menu_option) {
            case 1: 
                addEmail(emails, &num_of_emails);
                break;
            case 2: 
                viewEmails(emails, num_of_emails);
                break;
            case 3: 
                searchEmails(emails, num_of_emails);
                break;
            case 4:
                printf("Exiting email client. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void addEmail(Email emails[], int *num_of_emails) {
    Email new_email;
    fflush(stdin);
    printf("\nEnter sender's email address: ");
    scanf("%s", &new_email.sender);
    fflush(stdin);
    printf("Enter receiver's email address: ");
    scanf("%s", &new_email.receiver);
    fflush(stdin);
    printf("Enter email subject (max %d characters): ", MAX_SUBJECT_LENGTH);
    fgets(new_email.subject, sizeof(new_email.subject), stdin);
    printf("Enter email body:\n");
    fgets(new_email.body, sizeof(new_email.body), stdin);
    
    emails[*num_of_emails] = new_email;
    *num_of_emails = *num_of_emails + 1;
    
    printf("\nEmail added successfully!\n");
}

void viewEmails(Email emails[], int num_of_emails) {
    if(num_of_emails == 0) {
        printf("No emails to display. Add an email first.\n");
    } else {
        printf("\n--- Email List ---\n");
        for(int i=0; i<num_of_emails; i++) {
            printf("Email #%d\n", i+1);
            printf("Sender: %s\n", emails[i].sender);
            printf("Receiver: %s\n", emails[i].receiver);
            printf("Subject: %s", emails[i].subject);
            printf("Body: %s", emails[i].body);
        }
    }
}

void searchEmails(Email emails[], int num_of_emails) {
    char search_query[MAX_SUBJECT_LENGTH];
    int search_result_count = 0;
    
    printf("\nEnter search query (max %d characters): ", MAX_SUBJECT_LENGTH);
    scanf("%s", &search_query);
    
    printf("\n--- Search Results ---\n");
    for(int i=0; i<num_of_emails; i++) {
        if(strstr(emails[i].subject, search_query) != NULL) {
            printf("Email #%d\n", i+1);
            printf("Sender: %s\n", emails[i].sender);
            printf("Receiver: %s\n", emails[i].receiver);
            printf("Subject: %s", emails[i].subject);
            printf("Body: %s", emails[i].body);
            search_result_count++;
        }   
    }
    
    if(search_result_count == 0) {
        printf("No matching emails found.\n");
    } else {
        printf("Total matching emails found: %d\n", search_result_count);
    }
}