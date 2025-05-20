//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 512

typedef struct {
    char date[20];
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void displayMenu() {
    printf("\n=======================\n");
    printf("   Digital Diary Menu  \n");
    printf("=======================\n");
    printf("1. Add a New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entries\n");
    printf("4. Delete an Entry\n");
    printf("5. Exit\n");
    printf("=======================\n");
    printf("Select an option (1-5): ");
}

void addEntry() {
    if(entryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entryCount].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    printf("Enter your diary entry: ");
    getchar(); // consume newline character
    fgets(diary[entryCount].entry, MAX_LENGTH, stdin);
    
    // Remove the newline character from the entry
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = 0;
    
    entryCount++;
    printf("Entry added on %s!\n", diary[entryCount - 1].date);
}

void viewEntries() {
    if (entryCount == 0) {
        printf("No entries to display!\n");
        return;
    }
    
    printf("\n===== Your Diary Entries =====\n");
    for(int i = 0; i < entryCount; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].entry);
        printf("===========================\n");
    }
}

void searchEntries() {
    if (entryCount == 0) {
        printf("No entries to search!\n");
        return;
    }

    printf("Enter a keyword to search: ");
    char keyword[MAX_LENGTH];
    getchar(); // consume newline character
    fgets(keyword, MAX_LENGTH, stdin);
    
    // Remove the newline character from the keyword
    keyword[strcspn(keyword, "\n")] = 0;

    printf("\n=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].entry);
            printf("===========================\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found containing the keyword '%s'!\n", keyword);
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("No entries to delete!\n");
        return;
    }
    
    printf("Enter the entry number to delete (1-%d): ", entryCount);
    int number;
    scanf("%d", &number);
    
    if (number < 1 || number > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }
    
    for (int i = number - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    
    entryCount--;
    printf("Entry %d deleted successfully!\n", number);
}

int main() {
    int choice;

    printf("Welcome to Your Energetic Digital Diary!\n");
    printf("Where memories are typed and moments are cherished!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                printf("Thank you for using Your Digital Diary! See you next time!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose between 1 to 5.\n");
        }
    }
    return 0;
}