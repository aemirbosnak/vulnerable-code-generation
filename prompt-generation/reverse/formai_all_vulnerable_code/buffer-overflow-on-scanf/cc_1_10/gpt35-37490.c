//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

typedef struct diary_entry {
    char date[10];
    char time[10];
    char description[100];
} DiaryEntry;

void add_entry(DiaryEntry *entry, DiaryEntry diary[], int *count);
void view_entries(DiaryEntry diary[], int count);

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int count = 0;
    int choice;
    DiaryEntry entry;

    printf("Welcome to your digital diary!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&entry, diary, &count);
                break;
            case 2:
                view_entries(diary, count);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void add_entry(DiaryEntry *entry, DiaryEntry diary[], int *count) {
    if (*count < MAX_ENTRIES) {
        printf("\nEnter the date of this entry (MM/DD/YY): ");
        scanf("%s", entry->date);
        printf("Enter the time of this entry (HH:MM): ");
        scanf("%s", entry->time);
        printf("Enter a brief description of this entry: ");
        scanf(" %[^\n]", entry->description);

        diary[*count] = *entry;
        (*count)++;
        printf("Entry added successfully!\n");
    } else {
        printf("Diary is full, cannot add any more entries.\n");
    }
}

void view_entries(DiaryEntry diary[], int count) {
    if (count == 0) {
        printf("\nThere are no entries to view.\n");
    } else {
        printf("\nHere are your diary entries:\n");
        for (int i = 0; i < count; i++) {
            printf("\nDate: %s\nTime: %s\nDescription: %s\n",
                diary[i].date, diary[i].time, diary[i].description);
        }
    }
}