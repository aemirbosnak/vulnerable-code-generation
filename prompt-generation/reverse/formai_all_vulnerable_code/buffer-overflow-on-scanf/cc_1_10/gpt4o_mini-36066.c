//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define TITLE_LEN 50
#define ENTRY_LEN 500

typedef struct {
    char title[TITLE_LEN];
    char entry[ENTRY_LEN];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void printGreeting() {
    printf("Welcome to Your Digital Diary of Love.\n");
    printf("Where every thought is a cherished memory.\n\n");
}

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Your diary is full, my love. Can't pen down any more thoughts.\n");
        return;
    }
    
    printf("Please enter a title for your entry: ");
    getchar(); // flush newline from previously entered input
    fgets(diary[entryCount].title, TITLE_LEN, stdin);
    diary[entryCount].title[strcspn(diary[entryCount].title, "\n")] = '\0';  // remove newline

    printf("Write your heartfelt entry (max 500 characters):\n");
    fgets(diary[entryCount].entry, ENTRY_LEN, stdin);
    diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = '\0';  // remove newline

    diary[entryCount].timestamp = time(NULL);
    entryCount++;

    printf("Your entry has been saved, dear. 😊\n\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("Oh dear, your diary is still empty. Time to fill it with sweet memories!\n");
        return;
    }

    printf("Here are your cherished diary entries:\n");
    for (int i = 0; i < entryCount; i++) {
        struct tm *tm_info = localtime(&diary[i].timestamp);
        char buffer[26];
        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
        
        printf("Entry %d: %s\nDate: %s\nContent: %s\n\n", 
               i + 1, 
               diary[i].title, 
               buffer, 
               diary[i].entry);
    }
}

void searchEntry() {
    char searchTerm[TITLE_LEN];
    printf("Enter a title or keyword to search for: ");
    getchar(); // flush newline from previously entered input
    fgets(searchTerm, TITLE_LEN, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // remove newline

    int found = 0;
    printf("Searching for your sweet memories containing: %s\n", searchTerm);
    
    for (int i = 0; i < entryCount; i++) {
        if (strstr(diary[i].title, searchTerm) || strstr(diary[i].entry, searchTerm)) {
            struct tm *tm_info = localtime(&diary[i].timestamp);
            char buffer[26];
            strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
            
            printf("Entry %d: %s\nDate: %s\nContent: %s\n\n", 
                   i + 1, 
                   diary[i].title, 
                   buffer, 
                   diary[i].entry);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Oh my, no entries found with that title or keyword. 🌧️\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("There's nothing to delete, my love. Your diary is still blank.\n");
        return;
    }
    
    int entryNum;
    printf("Enter the entry number you wish to delete (1 to %d): ", entryCount);
    scanf("%d", &entryNum);
    
    if (entryNum < 1 || entryNum > entryCount) {
        printf("That's not a valid entry number. Please try again. 💔\n");
        return;
    }
    
    for (int i = entryNum - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1];
    }
    
    entryCount--;
    printf("Entry %d has been delicately removed from your diary. 💔\n\n", entryNum);
}

void quitDiary() {
    printf("Thank you for sharing your heartfelt moments with us, my love. Until next time.\n");
    exit(0);
}

int main() {
    printGreeting();
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Quit Diary\n");
        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchEntry(); break;
            case 4: deleteEntry(); break;
            case 5: quitDiary(); break;
            default: printf("Hmm, that option doesn't exist. Let’s try again!\n"); break;
        }
    }

    return 0;
}