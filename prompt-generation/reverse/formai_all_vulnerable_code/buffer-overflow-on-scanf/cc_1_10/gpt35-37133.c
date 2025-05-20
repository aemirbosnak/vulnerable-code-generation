//FormAI DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_LIST_LENGTH 1000

// struct for a single email address
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} email_t;

// struct for the email list
typedef struct {
    email_t emails[MAX_LIST_LENGTH];
    int length;
} email_list_t;

// function to add a new email to the list
void add_email(email_list_t *list, char *name, char *email) {
    if (list->length == MAX_LIST_LENGTH) {
        printf("List is full. Cannot add more emails.\n");
        return;
    }
    
    email_t new_email;
    strcpy(new_email.name, name);
    strcpy(new_email.email, email);
    list->emails[list->length++] = new_email;
    printf("Email added successfully!\n");
}

// function to remove an email from the list
void remove_email(email_list_t *list, char *email) {
    int i, j = 0;
    bool found = false;
    
    for (i = 0; i < list->length; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            found = true;
        } else {
            list->emails[j++] = list->emails[i];
        }
    }
    
    if (found) {
        list->length--;
        printf("Email removed successfully!\n");
    } else {
        printf("Email not found in list.\n");
    }
}

// function to print out all emails in the list
void print_emails(email_list_t list) {
    printf("Email list:\n");
    for (int i = 0; i < list.length; i++) {
        printf("%s - %s\n", list.emails[i].name, list.emails[i].email);
    }
}

int main() {
    email_list_t my_list = { .length = 0 };
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int choice;
    
    do {
        printf("\n1. Add email\n");
        printf("2. Remove email\n");
        printf("3. Print all emails\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_email(&my_list, name, email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                remove_email(&my_list, email);
                break;
            case 3:
                print_emails(my_list);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}