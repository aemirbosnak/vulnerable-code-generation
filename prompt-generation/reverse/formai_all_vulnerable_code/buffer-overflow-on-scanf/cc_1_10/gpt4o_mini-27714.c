//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILING_LISTS 10
#define MAX_SUBSCRIBERS 100
#define LIST_NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    char name[LIST_NAME_LENGTH];
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int subscriber_count;
} MailingList;

MailingList mailing_lists[MAX_MAILING_LISTS];
int mailing_list_count = 0;

void create_list() {
    if (mailing_list_count >= MAX_MAILING_LISTS) {
        printf("Maximum mailing lists reached!\n");
        return;
    }
    
    MailingList new_list;
    printf("Enter name for new mailing list: ");
    scanf("%s", new_list.name);
    new_list.subscriber_count = 0;
    
    mailing_lists[mailing_list_count++] = new_list;
    printf("Mailing list '%s' created successfully!\n", new_list.name);
}

void subscribe_to_list() {
    char list_name[LIST_NAME_LENGTH];
    char email[EMAIL_LENGTH];
    
    printf("Enter mailing list name to subscribe to: ");
    scanf("%s", list_name);
    
    for (int i = 0; i < mailing_list_count; ++i) {
        if (strcmp(mailing_lists[i].name, list_name) == 0) {
            if (mailing_lists[i].subscriber_count >= MAX_SUBSCRIBERS) {
                printf("Maximum subscribers reached for list '%s'!\n", list_name);
                return;
            }
            printf("Enter your email to subscribe: ");
            scanf("%s", email);
            strcpy(mailing_lists[i].subscribers[mailing_lists[i].subscriber_count++].email, email);
            printf("You have been subscribed to '%s'.\n", list_name);
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", list_name);
}

void view_subscribers() {
    char list_name[LIST_NAME_LENGTH];
    printf("Enter mailing list name to view subscribers: ");
    scanf("%s", list_name);
    
    for (int i = 0; i < mailing_list_count; ++i) {
        if (strcmp(mailing_lists[i].name, list_name) == 0) {
            printf("Subscribers for '%s':\n", list_name);
            for (int j = 0; j < mailing_lists[i].subscriber_count; ++j) {
                printf("%s\n", mailing_lists[i].subscribers[j].email);
            }
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", list_name);
}

void list_mailing_lists() {
    printf("Available Mailing Lists:\n");
    for (int i = 0; i < mailing_list_count; ++i) {
        printf("%s\n", mailing_lists[i].name);
    }
}

void delete_list() {
    char list_name[LIST_NAME_LENGTH];
    printf("Enter mailing list name to delete: ");
    scanf("%s", list_name);
    
    for (int i = 0; i < mailing_list_count; ++i) {
        if (strcmp(mailing_lists[i].name, list_name) == 0) {
            mailing_lists[i] = mailing_lists[--mailing_list_count]; // Replace with the last list
            printf("Mailing list '%s' deleted successfully!\n", list_name);
            return;
        }
    }
    printf("Mailing list '%s' not found!\n", list_name);
}

void display_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Create Mailing List\n");
    printf("2. Subscribe to Mailing List\n");
    printf("3. View Subscribers\n");
    printf("4. List Mailing Lists\n");
    printf("5. Delete Mailing List\n");
    printf("0. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_list(); break;
            case 2: subscribe_to_list(); break;
            case 3: view_subscribers(); break;
            case 4: list_mailing_lists(); break;
            case 5: delete_list(); break;
            case 0: 
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}