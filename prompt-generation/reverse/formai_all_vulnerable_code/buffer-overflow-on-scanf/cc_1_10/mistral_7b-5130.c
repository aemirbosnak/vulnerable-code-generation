//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUM 20
#define MAX_ENTRY 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_NUM];
} PhoneBookEntry;

PhoneBookEntry phoneBook[MAX_ENTRY];
int numEntries = 0;

void searchName(char name[]) {
    for (int i = 0; i < numEntries; i++) {
        if (strcasecmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }

    printf("Name not found.\n");
}

void addEntry() {
    if (numEntries >= MAX_ENTRY) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[numEntries].phone);

    numEntries++;
    printf("Entry added successfully.\n");
}

void displayEntries() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Phone book:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\tPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nPhone Book Menu:\n1. Add Entry\n2. Search Name\n3. Display All Entries\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchName(name);
                break;
            case 3:
                displayEntries();
                break;
            case 4:
                printf("Exiting phone book application...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}