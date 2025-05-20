//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: active
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

void addEntry(MailListEntry** head) {
    MailListEntry* newEntry = malloc(sizeof(MailListEntry));
    printf("Enter name: ");
    scanf("%s", newEntry->name);
    printf("Enter email: ");
    scanf("%s", newEntry->email);

    if (*head == NULL) {
        *head = newEntry;
    } else {
        (*head)->next = newEntry;
    }
    *head = newEntry;
}

void printEntries(MailListEntry* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Email: %s\n", head->email);
        printf("\n");
        head = head->next;
    }
}

int main() {
    MailListEntry* head = NULL;

    while (1) {
        printf("Enter 1 to add an entry, 2 to print entries, 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(&head);
                break;
            case 2:
                printEntries(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}