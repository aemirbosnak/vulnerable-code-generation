//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addContact(char *name, char *phone) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].phone, phone);
    numEntries++;
}

void searchContact(char *name) {
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\n", phoneBook[i].name);
            printf("Phone: %s\n", phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(char *name) {
    int i, j;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (j = i; j < numEntries - 1; j++) {
                phoneBook[j] = phoneBook[j + 1];
            }
            numEntries--;
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayContacts() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("Name: %s\n", phoneBook[i].name);
        printf("Phone: %s\n", phoneBook[i].phone);
        printf("\n");
    }
}

int main() {
    char command[5];
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Name: ");
            scanf("%s", name);
            printf("Phone: ");
            scanf("%s", phone);
            addContact(name, phone);
        } else if (strcmp(command, "search") == 0) {
            printf("Name: ");
            scanf("%s", name);
            searchContact(name);
        } else if (strcmp(command, "delete") == 0) {
            printf("Name: ");
            scanf("%s", name);
            deleteContact(name);
        } else if (strcmp(command, "display") == 0) {
            displayContacts();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}