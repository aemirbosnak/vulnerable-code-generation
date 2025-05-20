//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[20];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Thy phone book is full! Pray thee, add an entry to replace an old one.\n");
        return;
    }
    printf("Enter the name, milord: ");
    fgets(phoneBook[numEntries].name, sizeof(phoneBook[numEntries].name), stdin);
    phoneBook[numEntries].name[strcspn(phoneBook[numEntries].name, "\n")] = '\0';
    printf("Enter the phone number, milady: ");
    fgets(phoneBook[numEntries].phone, sizeof(phoneBook[numEntries].phone), stdin);
    phoneBook[numEntries].phone[strcspn(phoneBook[numEntries].phone, "\n")] = '\0';
    numEntries++;
    printf("Entry added successfully, may the blessings of the heavens be upon thee!\n");
}

void searchEntry() {
    char searchName[50];
    int i;

    printf("Enter the name to search for, milady: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (i = 0; i < numEntries; i++) {
        if (strcmp(searchName, phoneBook[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("No entry found, milady.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Thy Medieval Phone Book ---");
        printf("\n1. Add an entry\n2. Search for an entry\n3. Exit\nEnter thy choice, milord: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                printf("Fare thee well, milord.\n");
                return 0;
            default:
                printf("Invalid choice, milord. Try again.\n");
        }
    }

    return 0;
}