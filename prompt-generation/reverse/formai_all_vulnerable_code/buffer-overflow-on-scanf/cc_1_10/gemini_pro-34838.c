//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[32];
    char phone[16];
} PhoneEntry;

PhoneEntry phonebook[MAX_ENTRIES];

int numEntries = 0;

void addEntry(char *name, char *phone) {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(phonebook[numEntries].name, name);
    strcpy(phonebook[numEntries].phone, phone);
    numEntries++;
}

void removeEntry(char *name) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            break;
        }
    }

    if (i == numEntries) {
        printf("Error: Entry not found.\n");
        return;
    }

    for (i; i < numEntries - 1; i++) {
        phonebook[i] = phonebook[i + 1];
    }

    numEntries--;
}

void findEntry(char *name) {
    int i;

    for (i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            break;
        }
    }

    if (i == numEntries) {
        printf("Error: Entry not found.\n");
        return;
    }

    printf("%s\t%s\n", phonebook[i].name, phonebook[i].phone);
}

void listEntries() {
    int i;

    for (i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;
    char name[32];
    char phone[16];

    while (1) {
        printf("\n1. Add entry\n2. Remove entry\n3. Find entry\n4. List entries\n5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %s", name);
                printf("Enter phone: ");
                scanf(" %s", phone);
                addEntry(name, phone);
                break;
            case 2:
                printf("Enter name: ");
                scanf(" %s", name);
                removeEntry(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf(" %s", name);
                findEntry(name);
                break;
            case 4:
                listEntries();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return EXIT_SUCCESS;
}