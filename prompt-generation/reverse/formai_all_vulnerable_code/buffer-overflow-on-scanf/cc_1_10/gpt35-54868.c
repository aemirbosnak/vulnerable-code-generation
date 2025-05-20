//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ENTRIES 1000
#define MAX_TITLE_SIZE 100
#define MAX_NOTE_SIZE 1000

typedef struct DiaryEntry {
    char title[MAX_TITLE_SIZE];
    char note[MAX_NOTE_SIZE];
    time_t date;
} DiaryEntry;

DiaryEntry diaryEntries[MAX_ENTRIES];
int currEntryIndex = 0;

void addEntry() {
    if(currEntryIndex == MAX_ENTRIES) {
        printf("Sorry! Diary is full\n");
        return;
    }

    DiaryEntry newEntry;
    printf("Enter title for entry: ");
    fgets(newEntry.title, MAX_TITLE_SIZE, stdin);
    printf("Enter note for entry: ");
    fgets(newEntry.note, MAX_NOTE_SIZE, stdin);
    newEntry.date = time(NULL);

    diaryEntries[currEntryIndex++] = newEntry;
    printf("Entry added successfully!\n");
}

void printAllEntries() {
    if(currEntryIndex == 0) {
        printf("No entries found\n");
        return;
    }

    printf("\nAll entries:\n");
    printf("------------------------\n");
    for(int i=0; i<currEntryIndex; i++) {
        struct tm * timeInfo;
        timeInfo = localtime(&diaryEntries[i].date);
        printf("Title: %s", diaryEntries[i].title);
        printf("Note: %s", diaryEntries[i].note);
        printf("Date: %s", asctime(timeInfo));
        printf("------------------------\n");
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nDigital Diary\n------------------------\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n'); // clear input buffer
        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                printAllEntries();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }
    }
    return 0;
}