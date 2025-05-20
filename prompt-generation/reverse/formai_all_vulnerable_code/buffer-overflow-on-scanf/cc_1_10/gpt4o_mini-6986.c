//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500

typedef struct {
    char title[50];
    char content[MAX_LENGTH];
    time_t date;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entryCount = 0;

void addEntry() {
    if (entryCount >= MAX_ENTRIES) {
        printf("Uh-oh! You've reached the limit of diary entries!\n");
        return;
    }
    
    printf("\n--- Add New Diary Entry ---\n");
    printf("Enter title: ");
    fgets(diary[entryCount].title, sizeof(diary[entryCount].title), stdin);
    diary[entryCount].title[strcspn(diary[entryCount].title, "\n")] = 0; // Remove newline

    printf("What's on your mind? (max %d characters)\n", MAX_LENGTH);
    fgets(diary[entryCount].content, sizeof(diary[entryCount].content), stdin);
    diary[entryCount].content[strcspn(diary[entryCount].content, "\n")] = 0; // Remove newline

    diary[entryCount].date = time(NULL);
    entryCount++;
    
    printf("Diary entry added successfully! 🎉\n");
}

void viewEntries() {
    if (entryCount == 0) {
        printf("Your diary is empty! How about writing something? 📝\n");
        return;
    }

    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entryCount; i++) {
        printf("Entry #%d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Date: %s", ctime(&diary[i].date));
        printf("Content: %s\n\n", diary[i].content);
    }
}

void searchEntry() {
    if (entryCount == 0) {
        printf("No diary entries to search! Create one first! 🕵️\n");
        return;
    }

    char searchTitle[50];
    printf("\nEnter title to search for: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline

    int found = 0;
    for (int i = 0; i < entryCount; i++) {
        if (strcasecmp(diary[i].title, searchTitle) == 0) {
            printf("Found Entry #%d:\n", i + 1);
            printf("Title: %s\n", diary[i].title);
            printf("Date: %s", ctime(&diary[i].date));
            printf("Content: %s\n", diary[i].content);
            found++;
            break;
        }
    }

    if (!found) {
        printf("No entry found with that title! 😢\n");
    }
}

void deleteEntry() {
    if (entryCount == 0) {
        printf("Oops! No entries to delete! Create some first! 🗑️\n");
        return;
    }

    int index;
    printf("\nEnter entry number to delete: ");
    scanf("%d", &index);
    getchar(); // Consume newline character

    if (index < 1 || index > entryCount) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entryCount - 1; i++) {
        diary[i] = diary[i + 1]; // Shift entries left
    }
    
    entryCount--;
    printf("Diary entry #%d deleted successfully! 🚮🎈\n", index);
}

void displayMenu() {
    printf("\n--- Welcome to Your Digital Diary! ---\n");
    printf("1. Add New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search for an Entry\n");
    printf("4. Delete an Entry\n");
    printf("5. Exit\n");
    printf("---------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
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
                deleteEntry();
                break;
            case 5:
                printf("Thank you for using the Digital Diary! Happy writing! ✍️💖\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-5.\n");
                break;
        }
    }

    return 0;
}