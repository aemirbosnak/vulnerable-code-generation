//FormAI DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 20
#define MAX_NUMBER_LENGTH 10

typedef struct PhoneBookEntry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} PhoneBookEntry;

PhoneBookEntry phoneBook[MAX_ENTRIES];
int numEntries = 0;

// Function to add an entry to the phone book
void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Error: phone book is full!\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);
    printf("Enter number: ");
    scanf("%s", phoneBook[numEntries].number);
    numEntries++;
    printf("Entry added!\n");
}

// Function to delete an entry from the phone book
void deleteEntry() {
    if (numEntries == 0) {
        printf("Error: phone book is empty!\n");
        return;
    }
    int index = -1;
    char name[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int j = index; j < numEntries - 1; j++) {
            strcpy(phoneBook[j].name, phoneBook[j+1].name);
            strcpy(phoneBook[j].number, phoneBook[j+1].number);
        }
        numEntries--;
        printf("Entry deleted!\n");
    } else {
        printf("Error: entry not found!\n");
    }
}

// Function to search for an entry in the phone book
void search() {
    if (numEntries == 0) {
        printf("Error: phone book is empty!\n");
        return;
    }
    char name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("%s's number is %s.\n", phoneBook[i].name, phoneBook[i].number);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: entry not found!\n");
    }
}

// Function to display all entries in the phone book
void display() {
    if (numEntries == 0) {
        printf("Phone book is empty!\n");
    } else {
        printf("Phone book entries:\n");
        for (int i = 0; i < numEntries; i++) {
            printf("%s: %s\n", phoneBook[i].name, phoneBook[i].number);
        }
    }
}

int main() {
    printf("C Phone Book - Retro Edition\n\n");
    while (1) {
        printf("MENU:\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. Search\n");
        printf("4. Display All Entries\n");
        printf("5. Exit\n\n");
        printf("Select an option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addEntry();
                break;
            case 2:
                deleteEntry();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
        printf("\n");
    }
    return 0;
}