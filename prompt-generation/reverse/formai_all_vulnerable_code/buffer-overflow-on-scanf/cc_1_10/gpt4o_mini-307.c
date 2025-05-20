//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DATE_LENGTH 20

typedef struct {
    char date[DATE_LENGTH];
    char content[MAX_LENGTH];
} DiaryEntry;

void addEntry(DiaryEntry entries[], int *count);
void viewEntries(DiaryEntry entries[], int count);
void displayMenu();
void displayGoodbyeMessage();

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                addEntry(entries, &count);
                break;
            case 2:
                viewEntries(entries, count);
                break;
            case 3:
                displayGoodbyeMessage();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addEntry(DiaryEntry entries[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    DiaryEntry newEntry;
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    strftime(newEntry.date, DATE_LENGTH, "%Y-%m-%d %H:%M:%S", tm_struct);
    
    printf("Enter your diary entry (Max %d characters):\n", MAX_LENGTH);
    fgets(newEntry.content, MAX_LENGTH, stdin);
    newEntry.content[strcspn(newEntry.content, "\n")] = 0;  // Remove trailing newline

    entries[*count] = newEntry;
    (*count)++;
    
    printf("Your entry has been added successfully!\n");
}

void viewEntries(DiaryEntry entries[], int count) {
    if (count == 0) {
        printf("No entries to display!\n");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < count; i++) {
        printf("Entry %d (%s):\n", i + 1, entries[i].date);
        printf("%s\n\n", entries[i].content);
    }
}

void displayMenu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add new diary entry\n");
    printf("2. View diary entries\n");
    printf("3. Exit\n");
}

void displayGoodbyeMessage() {
    printf("Thank you for using the digital diary. Have a great day!\n");
}