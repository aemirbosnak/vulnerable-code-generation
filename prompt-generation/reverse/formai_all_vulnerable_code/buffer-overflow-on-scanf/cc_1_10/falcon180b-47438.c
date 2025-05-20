//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);

    printf("Enter phone number: ");
    scanf("%s", phoneBook[numEntries].number);

    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", phoneBook[i].name, phoneBook[i].number);
        }
    }
}

void deleteEntry() {
    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, deleteName) == 0) {
            strcpy(phoneBook[i].name, "");
            strcpy(phoneBook[i].number, "");
        }
    }
}

void printPhonebook() {
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nPhone number: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhonebook Menu:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Print phonebook\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printPhonebook();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}