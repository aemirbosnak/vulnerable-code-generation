//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20
#define MAX_ENTRIES 5000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} PhoneBookEntry;

PhoneBookEntry entries[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", entries[numEntries].name);
    
    printf("Enter phone number: ");
    scanf("%s", entries[numEntries].number);
    
    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Phone number: %s\n", entries[i].number);
        }
    }
}

void deleteEntry() {
    char searchName[MAX_NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", searchName);
    
    int i;
    for (i = 0; i < numEntries; i++) {
        if (strcmp(entries[i].name, searchName) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(PhoneBookEntry) * (numEntries - i - 1));
            numEntries--;
            break;
        }
    }
}

void viewAllEntries() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("Name: %s\n", entries[i].name);
        printf("Phone number: %s\n", entries[i].number);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int choice;
    
    do {
        printf("Romeo and Juliet's Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. View all entries\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
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
                viewAllEntries();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
    
    return 0;
}