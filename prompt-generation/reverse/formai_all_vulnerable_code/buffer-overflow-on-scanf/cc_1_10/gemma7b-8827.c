//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EMAIL_LENGTH 255

typedef struct MailListEntry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct MailListEntry* next;
} MailListEntry;

MailListEntry* insertEntry(MailListEntry* head) {
    MailListEntry* newEntry = malloc(sizeof(MailListEntry));
    newEntry->next = NULL;

    printf("Enter name: ");
    scanf("%s", newEntry->name);

    printf("Enter email: ");
    scanf("%s", newEntry->email);

    if (head == NULL) {
        head = newEntry;
    } else {
        head->next = newEntry;
    }

    return head;
}

void printEntries(MailListEntry* head) {
    MailListEntry* currentEntry = head;

    printf("List of entries:\n");
    while (currentEntry) {
        printf("Name: %s\n", currentEntry->name);
        printf("Email: %s\n", currentEntry->email);
        printf("\n");
        currentEntry = currentEntry->next;
    }
}

int main() {
    MailListEntry* head = NULL;

    while (1) {
        printf("Enter 'add' to add a new entry, 'print' to print entries, or 'exit' to exit: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            head = insertEntry(head);
        } else if (strcmp(command, "print") == 0) {
            printEntries(head);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}