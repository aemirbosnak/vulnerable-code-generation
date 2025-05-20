//FormAI DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
} PhoneBookEntry;

void addEntry(PhoneBookEntry *entries, int *numEntries);
void searchEntry(PhoneBookEntry *entries, int numEntries);
void deleteEntry(PhoneBookEntry *entries, int *numEntries);

int main() {
    PhoneBookEntry *entries = malloc(MAX_ENTRIES * sizeof(PhoneBookEntry));
    int numEntries = 0;
    int choice;

    while (1) {
        printf("\n\n");
        printf("1) Add New Entry\n");
        printf("2) Search for Entry\n");
        printf("3) Delete an Entry\n");
        printf("4) Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(entries, &numEntries);
                break;
            case 2:
                searchEntry(entries, numEntries);
                break;
            case 3:
                deleteEntry(entries, &numEntries);
                break;
            case 4:
                free(entries);
                exit(0);
            default:
                printf("Invalid Choice, Try Again!\n");
                break;
        }
    }

    return 0;
}

void addEntry(PhoneBookEntry *entries, int *numEntries) {
    if (*numEntries >= MAX_ENTRIES) {
        printf("Phone Book is Full, Delete Some Entries to Add New Ones!\n");
        return;
    }

    PhoneBookEntry newEntry;
    printf("Enter Name: ");
    scanf("%s", newEntry.name);
    printf("Enter Phone Number: ");
    scanf("%s", newEntry.phoneNumber);

    entries[*numEntries++] = newEntry;

    printf("New Entry Added Successfully!\n");
}

void searchEntry(PhoneBookEntry *entries, int numEntries) {
    char name[MAX_NAME_LENGTH];
    printf("Enter Name to Search: ");
    scanf("%s", name);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Match Found!\n");
            printf("Name: %s\n", entries[i].name);
            printf("Phone Number: %s\n", entries[i].phoneNumber);
            return;
        }
    }

    printf("No Match Found!\n");
}

void deleteEntry(PhoneBookEntry *entries, int *numEntries) {
    char name[MAX_NAME_LENGTH];
    printf("Enter Name to Delete: ");
    scanf("%s", name);

    for (int i = 0; i < *numEntries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            for (int j = i; j < *numEntries - 1; j++) {
                entries[j] = entries[j + 1];
            }
            (*numEntries)--;
            printf("Entry Deleted Successfully!\n");
            return;
        }
    }

    printf("No Match Found, Deletion Failed!\n");
}