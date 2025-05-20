//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full. Please delete an entry to add a new one.\n");
        return;
    }
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[numEntries].date);
    printf("Enter your entry:\n");
    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    numEntries++;
    printf("Entry added.\n");
}

void viewEntries() {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void deleteEntry() {
    int i;
    printf("Enter date of entry to delete (YYYY-MM-DD): ");
    scanf("%s", diary[numEntries].date);
    for (i = 0; i < numEntries; i++) {
        if (strcmp(diary[i].date, diary[numEntries].date) == 0) {
            strcpy(diary[i].date, diary[numEntries].date);
            strcpy(diary[i].entry, diary[numEntries].entry);
            numEntries--;
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}