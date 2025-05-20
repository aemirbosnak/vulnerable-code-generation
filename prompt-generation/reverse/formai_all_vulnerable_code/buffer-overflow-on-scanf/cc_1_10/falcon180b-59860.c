//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_SUBJECT_LENGTH 200
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
    int num_contacts;
    contact contacts[100];
} mailing_list;

void add_contact(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, "") == 0) {
            printf("Enter name: ");
            scanf("%s", list->contacts[i].name);
            printf("Enter email: ");
            scanf("%s", list->contacts[i].email);
            printf("Contact added\n");
            return;
        }
    }
    printf("List is full\n");
}

void remove_contact(mailing_list *list) {
    int i, choice;
    printf("Enter index of contact to remove: ");
    scanf("%d", &choice);
    if (choice >= 0 && choice < list->num_contacts) {
        memset(&list->contacts[choice], 0, sizeof(contact));
        printf("Contact removed\n");
    } else {
        printf("Invalid index\n");
    }
}

void send_message(mailing_list *list) {
    int i;
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    scanf("%s", message);
    for (i = 0; i < list->num_contacts; i++) {
        if (strcmp(list->contacts[i].email, "")!= 0) {
            printf("Sending message to %s...\n", list->contacts[i].email);
        }
    }
}

int main() {
    mailing_list list;
    list.num_contacts = 0;
    int choice;
    while (1) {
        printf("1. Add contact\n2. Remove contact\n3. Send message\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_contact(&list);
            break;
        case 2:
            remove_contact(&list);
            break;
        case 3:
            send_message(&list);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}