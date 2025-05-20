//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("\nOh no! Your diary is full! Can't add more entries.\n");
        return;
    }

    printf("\n🎉 Let's add a new diary entry! 🎉\n");
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", diary[entryCount].date);
    printf("What's on your mind? ");
    getchar(); // clear newline from the buffer
    fgets(diary[entryCount].content, MAX_LENGTH, stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline
    entryCount++;
    printf("✨ Your diary entry has been saved! ✨\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("\nYour diary is empty! Go ahead and add some entries! 🌟\n");
        return;
    }

    printf("\n📓 Here are your diary entries: 📓\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].content);
    }
}

void searchEntry() {
    if (entryCount == 0) {
        printf("\nYour diary is empty! 🌈 Let's write a new entry!\n");
        return;
    }

    char searchDate[11];
    printf("\n🔍 Enter the date you want to search (YYYY-MM-DD): ");
    scanf("%s", searchDate);
    
    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcmp(diary[i].date, searchDate) == 0) {
            printf("Entry for %s: %s\n", diary[i].date, diary[i].content);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("🚫 No entries found for %s. Feel free to add some! 🎈\n", searchDate);
    }
}

void displayMenu() {
    printf("\n🌈 Welcome to your Digital Diary! 🌈\n");
    printf("1. Add Diary Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntry();
                break;
            case 4:
                printf("🌟 Thank you for using the Digital Diary! Have a great day! 🌟\n");
                exit(0);
            default:
                printf("🚫 Oops! Invalid choice. Please select again! 🎉\n");
        }
    }
    return 0;
}