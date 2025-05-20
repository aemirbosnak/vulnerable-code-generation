//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[20];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[numEntries].phone);

    numEntries++;
    printf("Entry added successfully!\n");
}

void searchEntry() {
    char searchName[50];
    int result = -1;

    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            result = i;
            break;
        }
    }

    if (result == -1) {
        printf("Entry not found!\n");
    } else {
        printf("Name: %s\nPhone number: %s\n", phonebook[result].name, phonebook[result].phone);
    }
}

void deleteEntry() {
    int result = -1;

    printf("Enter name to delete: ");
    char searchName[50];
    scanf("%s", searchName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            result = i;
            break;
        }
    }

    if (result == -1) {
        printf("Entry not found!\n");
    } else {
        for (int i = result; i < numEntries - 1; i++) {
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].phone, phonebook[i+1].phone);
        }
        numEntries--;
        printf("Entry deleted successfully!\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}