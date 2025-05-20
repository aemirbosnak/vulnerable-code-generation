//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} MailingList;

void initializeMailingList(MailingList *list) {
    list->count = 0;
}

void addContact(MailingList *list, const char *name, const char *email) {
    if (list->count < MAX_CONTACTS) {
        strncpy(list->contacts[list->count].name, name, NAME_LENGTH);
        strncpy(list->contacts[list->count].email, email, EMAIL_LENGTH);
        list->count++;
        printf("Contact '%s' added successfully!\n", name);
    } else {
        printf("Oh dear! The mailing list is full! Cannot add more contacts.\n");
    }
}

void displayContacts(const MailingList *list) {
    printf("\n--- Current Contacts in the Mailing List ---\n");
    for (int i = 0; i < list->count; i++) {
        printf("(%d) Name: %s, Email: %s\n", i + 1, list->contacts[i].name, list->contacts[i].email);
    }
    printf("---------------------------------------------\n");
}

void removeContact(MailingList *list, int index) {
    if (index < 1 || index > list->count) {
        printf("Alas! Invalid contact index. No contact removed.\n");
        return;
    }
    for (int i = index - 1; i < list->count - 1; i++) {
        list->contacts[i] = list->contacts[i + 1];
    }
    list->count--;
    printf("Contact removed successfully!\n");
}

void menu() {
    printf("\n--- Sherlock Holmes' Mailing List Manager ---\n");
    printf("1. Add Contact\n");
    printf("2. Display Contacts\n");
    printf("3. Remove Contact\n");
    printf("4. Exit\n");
    printf("---------------------------------------------\n");
}

int main() {
    MailingList mailingList;
    initializeMailingList(&mailingList);
    int choice;
    char name[NAME_LENGTH], email[EMAIL_LENGTH];
    
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter Email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline

                addContact(&mailingList, name, email);
                break;
            case 2:
                displayContacts(&mailingList);
                break;
            case 3:
                displayContacts(&mailingList);
                printf("Enter the index of the contact to remove: ");
                int index;
                scanf("%d", &index);
                removeContact(&mailingList, index);
                break;
            case 4:
                printf("Thank you for using the mailing list manager. Goodbye!\n");
                exit(0);
            default:
                printf("Hmm... an unknown command, my dear Watson!\n");
                break;
        }
    }

    return 0;
}