//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_NAME_LENGTH 20
#define MAX_EMAILS_PER_LIST 10

typedef struct Email {
    char email[MAX_EMAIL_LENGTH];
} Email;

typedef struct MailingList {
    char name[MAX_LIST_NAME_LENGTH];
    Email emails[MAX_EMAILS_PER_LIST];
    int num_emails;
} MailingList;

void print_menu() {
    printf("\n1. Create new mailing list\n");
    printf("2. Add email to mailing list\n");
    printf("3. Remove email from mailing list\n");
    printf("4. Print mailing list\n");
    printf("5. Exit\n");
}

void create_mailing_list(MailingList *list) {
    printf("Enter name for mailing list: ");
    scanf("%s", list->name);
    list->num_emails = 0;
    printf("Mailing list %s created successfully.\n", list->name);
}

void add_email_to_list(MailingList *list, char email[MAX_EMAIL_LENGTH]) {
    if (list->num_emails >= MAX_EMAILS_PER_LIST) {
        printf("Maximum number of emails reached.\n");
        return;
    }
    
    for (int i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            printf("Email already exists in this list.\n");
            return;
        }
    }
    
    strcpy(list->emails[list->num_emails].email, email);
    list->num_emails++;
    printf("Email %s added to %s mailing list successfully.\n", email, list->name);
}

void remove_email_from_list(MailingList *list, char email[MAX_EMAIL_LENGTH]) {
    int index_to_remove = -1;
    
    for (int i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i].email, email) == 0) {
            index_to_remove = i;
            break;
        }
    }
    
    if (index_to_remove == -1) {
        printf("Email does not exist in this list.\n");
        return;
    }
    
    for (int i = index_to_remove; i < list->num_emails - 1; i++) {
        strcpy(list->emails[i].email, list->emails[i+1].email);
    }
    
    list->num_emails--;
    printf("Email %s removed from %s mailing list successfully.\n", email, list->name);
}

void print_mailing_list(MailingList *list) {
    printf("Mailing List: %s\n", list->name);
    printf("------------------------------\n");
    
    for (int i = 0; i < list->num_emails; i++) {
        printf("%d. %s\n", i+1, list->emails[i].email);
    }
    
    printf("------------------------------\n");
}

int main() {
    int choice;
    char email[MAX_EMAIL_LENGTH];
    MailingList list;
    list.num_emails = 0;
    
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                create_mailing_list(&list);
                break;
            case 2:
                printf("Enter email to add: ");
                scanf("%s", email);
                add_email_to_list(&list, email);
                break;
            case 3:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_email_from_list(&list, email);
                break;
            case 4:
                print_mailing_list(&list);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}