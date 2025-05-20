//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[15];
} entry;

int main() {
    entry phonebook[MAX_ENTRIES];
    int numEntries = 0;
    int choice;
    char searchName[50];
    char newName[50];
    char newNumber[15];

    system("clear");
    printf("Welcome to the Phone Book!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new entry\n");
        printf("2. Search for an entry\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter the name for the new entry: ");
            scanf("%s", newName);

            for(int i = 0; i < numEntries; i++) {
                if(strcmp(phonebook[i].name, newName) == 0) {
                    printf("\nThis name already exists. Please enter a different name.\n");
                    continue;
                }
            }

            printf("\nEnter the phone number for the new entry: ");
            scanf("%s", newNumber);

            strcpy(phonebook[numEntries].name, newName);
            strcpy(phonebook[numEntries].number, newNumber);
            numEntries++;

            printf("\nEntry added successfully!\n");
        }
        else if(choice == 2) {
            printf("\nEnter the name to search: ");
            scanf("%s", searchName);

            for(int i = 0; i < numEntries; i++) {
                if(strcmp(phonebook[i].name, searchName) == 0) {
                    printf("\n%s - %s\n", phonebook[i].name, phonebook[i].number);
                    break;
                }
            }
        }
        else if(choice == 3) {
            printf("\nExiting program...\n");
            break;
        }
        else {
            printf("\nInvalid choice. Please try again.\n");
        }

        system("clear");
    }

    return 0;
}