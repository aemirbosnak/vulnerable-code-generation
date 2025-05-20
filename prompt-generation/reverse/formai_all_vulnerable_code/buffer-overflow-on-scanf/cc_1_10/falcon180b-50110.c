//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void printMenu() {
    printf("\n");
    printf("1. Add Entry\n");
    printf("2. Search Entry\n");
    printf("3. Print Entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];

    printf("\nEnter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(phoneBook[numEntries].name, name);
    strcpy(phoneBook[numEntries].number, number);

    numEntries++;
}

void searchEntry() {
    char name[MAX_NAME_LENGTH];

    printf("\nEnter name to search: ");
    scanf("%s", name);

    int i;
    for(i=0;i<numEntries;i++) {
        if(strcmp(phoneBook[i].name, name) == 0) {
            printf("\nName: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
        }
    }
}

void printEntries() {
    int i;
    for(i=0;i<numEntries;i++) {
        printf("\nName: %s\nNumber: %s\n", phoneBook[i].name, phoneBook[i].number);
    }
}

int main() {
    int choice;

    printf("\nWelcome to the Phone Book!\n");

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                printEntries();
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(1);

    return 0;
}