//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phoneNumber[MAX_NUMBER_LEN];
} PhoneBookEntry;

PhoneBookEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[numEntries].phoneNumber);
    numEntries++;
}

void displayEntries() {
    printf("Phone book entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s: %s\n", entries[i].name, entries[i].phoneNumber);
    }
}

void searchEntry() {
    char searchName[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    tolower(searchName);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(tolower(entries[i].name), searchName) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", entries[i].name);
            printf("Phone number: %s\n", entries[i].phoneNumber);
        }
    }
}

int main() {
    printf("Welcome to the phone book program!\n");
    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Display entries\n");
        printf("3. Search entry\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addEntry();
            break;
        case 2:
            displayEntries();
            break;
        case 3:
            searchEntry();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}