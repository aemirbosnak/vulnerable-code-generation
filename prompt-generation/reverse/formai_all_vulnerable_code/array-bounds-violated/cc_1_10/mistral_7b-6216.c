//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addContact() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    fgets(phoneBook[numEntries].name, sizeof(phoneBook[numEntries].name), stdin);
    phoneBook[numEntries].name[strlen(phoneBook[numEntries].name) - 1] = '\0';

    printf("Enter phone number: ");
    fgets(phoneBook[numEntries].phone, sizeof(phoneBook[numEntries].phone), stdin);
    phoneBook[numEntries].phone[strlen(phoneBook[numEntries].phone) - 1] = '\0';

    numEntries++;
}

void searchContact() {
    char searchName[50];
    int i;

    printf("Enter name to search for: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strlen(searchName) - 1] = '\0';

    for (i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Found contact:\nName: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}