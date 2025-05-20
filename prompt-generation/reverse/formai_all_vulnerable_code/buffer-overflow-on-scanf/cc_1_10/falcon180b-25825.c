//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH+1];
    char number[MAX_NUMBER_LENGTH+1];
} Entry;

int numEntries = 0;
Entry phoneBook[MAX_ENTRIES];

void addEntry() {
    printf("Enter name (up to 50 characters): ");
    scanf("%s", phoneBook[numEntries].name);
    printf("Enter phone number (up to 15 digits): ");
    scanf("%s", phoneBook[numEntries].number);
    numEntries++;
}

void deleteEntry() {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LENGTH+1];
    scanf("%s", name);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            for (int j = i; j < numEntries-1; j++) {
                strcpy(phoneBook[j].name, phoneBook[j+1].name);
                strcpy(phoneBook[j].number, phoneBook[j+1].number);
            }
            numEntries--;
            break;
        }
    }
}

void searchEntry() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH+1];
    scanf("%s", name);
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
        }
    }
}

void printEntries() {
    for (int i = 0; i < numEntries; i++) {
        printf("Name: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print all entries\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                deleteEntry();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printEntries();
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