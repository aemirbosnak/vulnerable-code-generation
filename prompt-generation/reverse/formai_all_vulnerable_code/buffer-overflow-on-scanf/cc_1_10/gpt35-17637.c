//FormAI DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Function prototypes
void addEntry();
void viewEntries();

// Structure to represent a diary entry
typedef struct DiaryEntry {
    char date[20];
    char title[50];
    char body[500];
} DiaryEntry;

// Array to hold all diary entries
DiaryEntry diary[MAX_ENTRIES];

// Counter for number of entries
int numEntries = 0;

int main() {
    int choice;

    printf("Welcome to the Multiplayer Digital Diary!\n");

    do {
        // Display menu
        printf("\n1. Add entry\n2. View entries\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute selected option
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}

void addEntry() {
    if(numEntries == MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    printf("Enter the date: ");
    scanf("%s", diary[numEntries].date);

    printf("Enter the title: ");
    scanf("%s", diary[numEntries].title);

    printf("Enter the body: ");
    scanf("%s", diary[numEntries].body);

    numEntries++;

    printf("Entry added successfully.\n");
}

void viewEntries() {
    if(numEntries == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("Diary Entries:\n");

    for(int i = 0; i < numEntries; i++) {
        printf("\nEntry %d:\n", i+1);
        printf("Date: %s\n", diary[i].date);
        printf("Title: %s\n", diary[i].title);
        printf("Body: %s\n", diary[i].body);
    }
}