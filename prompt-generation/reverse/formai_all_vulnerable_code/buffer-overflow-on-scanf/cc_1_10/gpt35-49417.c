//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

struct email {
    char name[MAX_NAME_LENGTH];
    char address[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    struct email emails[MAX_EMAILS];
    int count;
};

void print_menu() {
    printf("1. Add email\n");
    printf("2. Remove email\n");
    printf("3. Print all emails\n");
    printf("4. Exit\n");
}

void add_email(struct mailing_list* list) {
    if(list->count >= MAX_EMAILS) {
        printf("Mailing list is full.\n");
        return;
    }

    struct email new_email;
    printf("Enter name: ");
    scanf("%s", new_email.name);
    printf("Enter email address: ");
    scanf("%s", new_email.address);

    list->emails[list->count++] = new_email;
    printf("Email added.\n");
}

void remove_email(struct mailing_list* list) {
    char email_to_remove[MAX_EMAIL_LENGTH];
    int index_to_remove = -1;

    printf("Enter email address to remove: ");
    scanf("%s", email_to_remove);

    for(int i = 0; i < list->count; i++) {
        if(strcmp(list->emails[i].address, email_to_remove) == 0) {
            index_to_remove = i;
            break;
        }
    }

    if(index_to_remove == -1) {
        printf("Email address not found.\n");
        return;
    }

    for(int i = index_to_remove; i < list->count - 1; i++) {
        list->emails[i] = list->emails[i+1];
    }

    list->count--;
    printf("Email address removed.\n");
}

void print_emails(struct mailing_list* list) {
    for(int i = 0; i < list->count; i++) {
        printf("%s (%s)\n", list->emails[i].name, list->emails[i].address);
    }
}

int main() {
    struct mailing_list list;
    list.count = 0;
    int choice;

    while(1) {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_email(&list);
                break;

            case 2:
                remove_email(&list);
                break;

            case 3:
                print_emails(&list);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}