//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Define structure for the diary entry
typedef struct {
    int year;
    int month;
    int day;
    char time[10];
    char description[100];
} DiaryEntry;

// Define function for adding a new entry to diary
void addEntry(DiaryEntry *diary, int entryCount) {
    printf("\nEnter the details of your diary entry\n");
    printf("Year (YYYY): ");
    scanf("%d", &diary[entryCount].year);
    printf("Month (MM): ");
    scanf("%d", &diary[entryCount].month);
    printf("Day (DD): ");
    scanf("%d", &diary[entryCount].day);
    printf("Time (hh:mm AM/PM): ");
    scanf("%s", diary[entryCount].time);
    printf("Description (max 100 characters): ");
    getchar(); // to clear input buffer
    fgets(diary[entryCount].description, 100, stdin);
}

// Define function for displaying all diary entries
void displayAllEntries(DiaryEntry *diary, int entryCount) {
    printf("\nAll diary entries:\n");
    for (int i = 0; i < entryCount; i++) {
        printf("%d-%d-%d %s: %s", diary[i].year, diary[i].month, diary[i].day, diary[i].time, diary[i].description);
    }
}

// Define function for displaying diary entries for a given date
void displayEntriesForDate(DiaryEntry *diary, int entryCount, int searchYear, int searchMonth, int searchDay) {
    printf("\nDiary entries for %d-%d-%d:\n", searchYear, searchMonth, searchDay);
    for (int i = 0; i < entryCount; i++) {
        if (diary[i].year == searchYear && diary[i].month == searchMonth && diary[i].day == searchDay) {
            printf("%s: %s", diary[i].time, diary[i].description);
        }
    }
}

int main() {
    char choice;
    int entryCount = 0;
    DiaryEntry diary[365];

    do {
        printf("\nSelect an option:\n");
        printf("1. Add new diary entry\n");
        printf("2. Display all diary entries\n");
        printf("3. Search diary entries for a given date\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if (entryCount == 365) {
                    printf("\nDiary is full. No more entries can be added.\n");
                    break;
                }
                addEntry(diary, entryCount);
                entryCount++;
                printf("\nEntry added successfully.\n");
                break;
            case '2':
                if (entryCount == 0) {
                    printf("\nDiary is empty. No entries to display.\n");
                    break;
                }
                displayAllEntries(diary, entryCount);
                break;
            case '3':
                if (entryCount == 0) {
                    printf("\nDiary is empty. No entries to search.\n");
                    break;
                }
                int searchYear, searchMonth, searchDay;
                printf("\nEnter the date to search (YYYY-MM-DD): ");
                scanf("%d-%d-%d", &searchYear, &searchMonth, &searchDay);
                displayEntriesForDate(diary, entryCount, searchYear, searchMonth, searchDay);
                break;
            case '4':
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '4');

    return 0;
}