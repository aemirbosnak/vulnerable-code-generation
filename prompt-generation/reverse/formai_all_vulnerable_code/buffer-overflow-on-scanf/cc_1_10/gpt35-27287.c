//FormAI DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRY_SIZE 1000

/*
* Digital Diary program in C
* Allows users to add, delete and view diary entries
*/

typedef struct DiaryEntry {
    char date[11];
    char entry[MAX_ENTRY_SIZE];
} DiaryEntry;

DiaryEntry* diaryEntries;
int count = 0;

// function to add entry to the diary
void addEntry() {
    // allocate memory for new entry
    diaryEntries = (DiaryEntry*)realloc(diaryEntries, (count + 1) * sizeof(DiaryEntry));
    
    // prompt user for date and entry
    char date[11];
    char entry[MAX_ENTRY_SIZE];
    
    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%10s", date);
    
    printf("Enter your diary entry: ");
    getchar();
    fgets(entry, MAX_ENTRY_SIZE, stdin);
    
    // add entry to the diary
    strcpy(diaryEntries[count].date, date);
    strcpy(diaryEntries[count].entry, entry);
    count++;
    
    printf("Entry added successfully!\n\n");
}

// function to delete entry from the diary
void deleteEntry() {
    // prompt user for index of entry to delete
    int index;
    printf("Enter the index of the entry you want to delete: ");
    scanf("%d", &index);
    
    // check if index is valid
    if (index < 1 || index > count) {
        printf("Invalid index. Please try again.\n\n");
        return;
    }
    
    // shift entries to fill gap
    for (int i = index; i < count; i++) {
        strcpy(diaryEntries[i-1].date, diaryEntries[i].date);
        strcpy(diaryEntries[i-1].entry, diaryEntries[i].entry);
    }
    
    // reduce count of entries
    count--;
    // resize memory
    diaryEntries = (DiaryEntry*)realloc(diaryEntries, count * sizeof(DiaryEntry));
    
    printf("Entry deleted successfully!\n\n");
}

// function to view all entries in the diary
void viewEntries() {
    // check if there are entries to display
    if (count == 0) {
        printf("No entries.\n\n");
        return;
    }
    
    // display all entries
    printf("Date\t\tEntry\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\n", diaryEntries[i].date, diaryEntries[i].entry);
    }
    printf("\n");
}

int main() {
    int choice;
    
    // allocate memory for entries
    diaryEntries = (DiaryEntry*)malloc(count * sizeof(DiaryEntry));
    
    do {
        // display menu
        printf("Digital Diary\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. View Entries\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        
        // get user choice
        scanf("%d", &choice);
        
        // perform chosen action
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                deleteEntry();
                break;
            case 3:
                viewEntries();
                break;
            case 4:
                printf("Goodbye!\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 4);
    
    // free allocated memory
    free(diaryEntries);
    
    return 0;
}