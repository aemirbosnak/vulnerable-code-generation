//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} entry;

entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry(char* name, char* phone) {
    if (numEntries == MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(phonebook[numEntries].name, name);
    strcpy(phonebook[numEntries].phone, phone);

    numEntries++;
    printf("Entry added successfully.\n");
}

void searchEntry(char* name) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry(char* name) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void printEntries() {
    int i;

    for (i = 0; i < numEntries; i++) {
        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;
    char name[50];
    char phone[15];

    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print all entries\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                addEntry(name, phone);
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteEntry(name);
                break;
            case 4:
                printEntries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}