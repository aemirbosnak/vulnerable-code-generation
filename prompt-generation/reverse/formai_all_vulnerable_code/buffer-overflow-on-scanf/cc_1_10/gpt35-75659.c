//FormAI DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_EMAIL_LENGTH 50

struct email {
    char address[MAX_EMAIL_LENGTH];
    struct email *next;
};

typedef struct email email_t;

email_t* head = NULL;

void Add_Email() {
    email_t *new_email = NULL;
    new_email = (email_t*) malloc(sizeof(email_t));
    if(new_email == NULL) {
        printf("Could not allocate memory for new email.\n");
        return;
    }
    printf("Enter the email address: ");
    scanf("%s",new_email->address);
    getchar();
    new_email->next = head;
    head = new_email;
    printf("Email address added successfully!\n\n");
}

void Remove_Email() {
    email_t *current_email, *prev_email;
    char address[MAX_EMAIL_LENGTH];
    printf("Enter the email address to be removed: ");
    scanf("%s",address);
    getchar();
    current_email = head;
    prev_email = NULL;
    while(current_email != NULL) {
        if(strcmp(current_email->address, address) == 0) {
            if(prev_email == NULL) {
                head = current_email->next;
            } else {
                prev_email->next = current_email->next;
            }
            printf("Email address removed successfully!\n\n");
            free(current_email);
            return;
        }
        prev_email = current_email;
        current_email = current_email->next;
    }
    printf("Email address not found in the mailing list.\n\n");
}

void Print_Emails() {
    email_t *current_email;
    if(head == NULL) {
        printf("There are no email addresses in the mailing list.\n\n");
        return;
    }
    current_email = head;
    printf("Mailing List:\n");
    while(current_email != NULL) {
        printf("\t%s\n",current_email->address);
        current_email = current_email->next;
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        printf("Mailing List Manager\n");
        printf("1. Add email to mailing list\n");
        printf("2. Remove email from mailing list\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d",&choice);
        getchar();
        switch(choice) {
            case 1:
                Add_Email();
                break;
            case 2:
                Remove_Email();
                break;
            case 3:
                Print_Emails();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }
    return 0;
}