//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for email list
typedef struct email_list {
    char email[50];
    struct email_list *next;
} EmailList;

// Function for adding email to list
EmailList* add_email(EmailList *head, char email[]) {
    EmailList *node = (EmailList*)malloc(sizeof(EmailList));
    if(node == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    strcpy(node->email, email);
    node->next = NULL;

    if(head == NULL) {
        head = node;
    } else {
        EmailList *current = head;
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = node;
    }

    return head;
}

// Function for removing email from list
EmailList* remove_email(EmailList *head, char email[]) {
    EmailList *prev = NULL;
    EmailList *current = head;

    while(current != NULL) {
        if(strcmp(current->email, email) == 0) {
            if(prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            return head;
        }

        prev = current;
        current = current->next;
    }

    printf("Email not found\n");
    return head;
}

// Function for printing email list
void print_list(EmailList *head) {
    EmailList *current = head;

    printf("\nEmail List:\n");
    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int choice;
    char email[50];

    EmailList *head = NULL;

    printf("\nWelcome to the Mailing List Manager\n");

    do {
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Print List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter email: ");
                scanf("%s", email);
                head = add_email(head, email);
                printf("Email added\n");
                break;
            case 2:
                printf("\nEnter email: ");
                scanf("%s", email);
                head = remove_email(head, email);
                printf("Email removed\n");
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                printf("\nExiting Mailing List Manager\n");
                break;
            default:
                printf("\nInvalid choice\n");
                break;
        }

        printf("\n");

    } while(choice != 4);

    return 0;
}