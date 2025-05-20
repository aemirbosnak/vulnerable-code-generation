//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH + 1];
} PhonebookEntry;

PhonebookEntry phonebook[100];
int numEntries = 0;

void addEntry(char *name, char *phoneNumber) {
    if (numEntries == 100) {
        printf("Phonebook is full.\n");
        return;
    }

    strcpy(phonebook[numEntries].name, name);
    strcpy(phonebook[numEntries].phoneNumber, phoneNumber);
    numEntries++;
}

void findEntry(char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].phoneNumber);
            return;
        }
    }

    printf("Entry not found.\n");
}

void deleteEntry(char *name) {
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < numEntries - 1; j++) {
                phonebook[j] = phonebook[j + 1];
            }

            numEntries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

void printPhonebook() {
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].phoneNumber);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH + 1];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH + 1];

    while (1) {
        printf("1. Add entry\n2. Find entry\n3. Delete entry\n4. Print phonebook\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %s", name);
                printf("Enter phone number: ");
                scanf(" %s", phoneNumber);
                addEntry(name, phoneNumber);
                break;
            case 2:
                printf("Enter name: ");
                scanf(" %s", name);
                findEntry(name);
                break;
            case 3:
                printf("Enter name: ");
                scanf(" %s", name);
                deleteEntry(name);
                break;
            case 4:
                printPhonebook();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}