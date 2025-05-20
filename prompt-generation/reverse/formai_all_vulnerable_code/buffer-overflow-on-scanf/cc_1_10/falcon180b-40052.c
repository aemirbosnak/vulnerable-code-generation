//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Phone book is full. Please delete an entry before adding a new one.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);
    
    printf("Enter phone number: ");
    scanf("%s", phoneBook[numEntries].phone);
    
    numEntries++;
    
    printf("Entry added successfully!\n");
}

void deleteEntry() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    int choice;
    printf("Enter the index of the entry you want to delete (0-%d): ", numEntries-1);
    scanf("%d", &choice);
    
    if (choice >= 0 && choice < numEntries) {
        memset(&phoneBook[choice], 0, sizeof(Entry));
        numEntries--;
        printf("Entry deleted successfully!\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void searchEntry() {
    if (numEntries == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    
    char searchName[50];
    printf("Enter name to search: ");
    scanf("%s", searchName);
    
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", phoneBook[i].name, phoneBook[i].phone);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    int choice;
    
    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    
    return 0;
}