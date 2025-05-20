//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry;

entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter number: ");
    fgets(number, MAX_NUMBER_LENGTH, stdin);
    number[strcspn(number, "\n")] = '\0';

    strcpy(phonebook[numEntries].name, name);
    strcpy(phonebook[numEntries].number, number);

    numEntries++;
    printf("Entry added successfully.\n");
}

void searchEntry() {
    char searchName[MAX_NAME_LENGTH];

    printf("Enter name to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int i;
    for(i = 0; i < numEntries; i++) {
        if(strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

void deleteEntry() {
    char deleteName[MAX_NAME_LENGTH];

    printf("Enter name to delete: ");
    fgets(deleteName, MAX_NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    int i;
    for(i = 0; i < numEntries; i++) {
        if(strcmp(phonebook[i].name, deleteName) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].number, "");
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}