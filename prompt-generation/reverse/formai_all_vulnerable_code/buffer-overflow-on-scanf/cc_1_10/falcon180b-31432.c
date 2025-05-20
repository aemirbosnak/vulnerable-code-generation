//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phonebook is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[numEntries].phone);

    numEntries++;
}

void searchEntry() {
    printf("Enter name to search: ");
    char searchName[50];
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

void deleteEntry() {
    printf("Enter name to delete: ");
    char deleteName[50];
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, deleteName) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            numEntries--;
            found = 1;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    system("clear");

    while (1) {
        printf("\nPhonebook:\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
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
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}