//FormAI DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char sender[50];
    char recipient[50];
} Email;

void clear_buffer() {
    int c;
    while((c = getchar()) != EOF && c != '\n');
}

void print_menu() {
    printf("\nEMAIL CLIENT\n");
    printf("1. Compose Email\n");
    printf("2. List Emails\n");
    printf("3. Open Email\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    clear_buffer();
    return choice;
}

void compose_email(Email *emails, int *num_emails) {
    if(*num_emails == MAX_EMAILS) {
        printf("\nCannot add more emails.\n");
        return;
    }

    printf("\nEnter Recipient: ");
    fgets(emails[*num_emails].recipient, 50, stdin);
    printf("Enter Subject: ");
    fgets(emails[*num_emails].subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Enter Body: ");
    fgets(emails[*num_emails].body, MAX_BODY_LENGTH, stdin);
    printf("Enter Sender: ");
    fgets(emails[*num_emails].sender, 50, stdin);

    printf("\nEmail added!\n");
    (*num_emails)++;
}

void list_emails(Email *emails, int num_emails) {
    if(num_emails == 0) {
        printf("\nNo emails to list.\n");
        return;
    }

    printf("\nEmails:\n");
    for(int i = 0; i < num_emails; i++) {
        printf("%d. %s - %s\n", i+1, emails[i].subject, emails[i].sender);
    }
}

void open_email(Email *emails, int num_emails) {
    if(num_emails == 0) {
        printf("\nNo emails to open.\n");
        return;
    }

    int choice;
    printf("\nEnter email number: ");
    scanf("%d", &choice);
    clear_buffer();

    if(choice < 1 || choice > num_emails) {
        printf("\nInvalid email number.\n");
        return;
    }

    printf("\nFrom: %s\n", emails[choice-1].sender);
    printf("To: %s\n", emails[choice-1].recipient);
    printf("Subject: %s\n", emails[choice-1].subject);
    printf("Body: %s\n", emails[choice-1].body);
}

int main() {
    Email emails[MAX_EMAILS];
    int num_emails = 0;

    int choice;
    do {
        print_menu();
        choice = get_choice();

        switch(choice) {
            case 1:
                compose_email(emails, &num_emails);
                break;
            case 2:
                list_emails(emails, num_emails);
                break;
            case 3:
                open_email(emails, num_emails);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}