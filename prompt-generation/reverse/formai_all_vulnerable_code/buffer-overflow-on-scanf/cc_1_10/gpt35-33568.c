//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_EMAILS 100

typedef struct {
    char* name;
    char* email;
} Contact;

int count = 0;
Contact contacts[MAX_EMAILS];

void addContact() {
    char* name = (char*)malloc(MAX_LEN * sizeof(char));
    char* email = (char*)malloc(MAX_LEN * sizeof(char));

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter email: ");
    scanf("%s", email);

    contacts[count].name = name;
    contacts[count].email = email;

    count++;
}

int findContact(char* email) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].email, email) == 0) {
            return i;
        }
    }
    return -1;
}

void removeContact(char* email) {
    int index = findContact(email);
    if (index != -1) {
        free(contacts[index].name);
        free(contacts[index].email);
        for (int i = index; i < count - 1; i++) {
            contacts[i].name = contacts[i + 1].name;
            contacts[i].email = contacts[i + 1].email;
        }
        count--;
        printf("Contact removed successfully!\n");
    } else {
        printf("Contact not found!\n");
    }
}

void printContacts() {
    if (count == 0) {
        printf("No contacts found!\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < count; i++) {
            printf("%s - %s\n", contacts[i].name, contacts[i].email);
        }
    }
}

int main() {
    char command[MAX_LEN];

    while (strcmp(command, "exit") != 0) {
        printf("Enter command (add, remove, print, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addContact();
        } else if (strcmp(command, "remove") == 0) {
            char* email = (char*)malloc(MAX_LEN * sizeof(char));
            printf("Enter email: ");
            scanf("%s", email);
            removeContact(email);
        } else if (strcmp(command, "print") == 0) {
            printContacts();
        } else if (strcmp(command, "exit") != 0) {
            printf("Unknown command!\n");
        }
    }

    for (int i = 0; i < count; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
    }

    return 0;
}