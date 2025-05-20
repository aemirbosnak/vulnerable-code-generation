//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[20];
    char content[MAX_ENTRY_LENGTH];
};

void addEntry(struct DiaryEntry diaryEntries[], int *entryCount);
void viewEntry(struct DiaryEntry diaryEntries[], int entryCount);
void searchEntry(struct DiaryEntry diaryEntries[], int entryCount);
void deleteEntry(struct DiaryEntry diaryEntries[], int *entryCount);

int main() {
    struct DiaryEntry diaryEntries[MAX_ENTRIES];
    int entryCount = 0;
    int choice = 0;

    printf("Welcome to your digital diary!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Search entries\n");
        printf("4. Delete an entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry(diaryEntries, &entryCount);
                break;
            case 2:
                viewEntry(diaryEntries, entryCount);
                break;
            case 3:
                searchEntry(diaryEntries, entryCount);
                break;
            case 4:
                deleteEntry(diaryEntries, &entryCount);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void addEntry(struct DiaryEntry diaryEntries[], int *entryCount) {
    if(*entryCount == MAX_ENTRIES) {
        printf("Sorry, your diary is full.\n");
        return;
    }

    struct DiaryEntry newEntry;

    printf("\nEnter the date of the entry (DD/MM/YYYY): ");
    scanf(" %[^\n]s", newEntry.date);

    printf("Enter the content of the entry (max %d characters):\n", MAX_ENTRY_LENGTH);
    scanf(" %[^\n]s", newEntry.content);

    diaryEntries[*entryCount] = newEntry;

    printf("\nEntry added successfully!\n");

    (*entryCount)++;
}

void viewEntry(struct DiaryEntry diaryEntries[], int entryCount) {
    if(entryCount == 0) {
        printf("\nThere are no entries in your diary.\n");
        return;
    }

    printf("\nDigitally scrowl through your entries:\n\n");
    for(int i=0; i<entryCount; i++) {
        printf("%d. %s:\n%s\n\n", i+1, diaryEntries[i].date, diaryEntries[i].content);
    }
}

void searchEntry(struct DiaryEntry diaryEntries[], int entryCount) {
    if(entryCount == 0) {
        printf("\nThere are no entries in your diary.\n");
        return;
    }

    char searchTerm[MAX_ENTRY_LENGTH];

    printf("\nEnter a search term (max %d characters): ", MAX_ENTRY_LENGTH);
    scanf(" %[^\n]s", searchTerm);

    int resultsCount = 0;

    printf("\nSearch results for '%s':\n\n", searchTerm);
    for(int i=0; i<entryCount; i++) {
        if(strstr(diaryEntries[i].content, searchTerm) != NULL || strstr(diaryEntries[i].date, searchTerm) != NULL) {
            printf("%d. %s:\n%s\n\n", i+1, diaryEntries[i].date, diaryEntries[i].content);
            resultsCount++;
        }
    }

    if(resultsCount == 0) {
        printf("No results found for '%s'.\n\n", searchTerm);
    }
}

void deleteEntry(struct DiaryEntry diaryEntries[], int *entryCount) {
    if(*entryCount == 0) {
        printf("\nThere are no entries in your diary.\n");
        return;
    }

    int entryToDelete = 0;

    printf("\nEnter the number of the entry you want to delete: ");
    scanf("%d", &entryToDelete);

    if(entryToDelete < 1 || entryToDelete > *entryCount) {
        printf("Invalid entry number entered.\n");
        return;
    }

    for(int i=entryToDelete-1; i<*entryCount-1; i++) {
        diaryEntries[i] = diaryEntries[i+1];
    }

    (*entryCount)--;
    printf("\nEntry deleted successfully!\n");
}