//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shape-shifting Digital Diary */

typedef struct {
    char date[20];
    char event[100];
} DiaryEntry;

void displayMenu();
void addEntry(DiaryEntry diary[], int *count);
void viewEntries(DiaryEntry diary[], int count);
void searchEntries(DiaryEntry diary[], int count);

int main() {

    DiaryEntry diary[100];  // Diary to hold entries 
    int count = 0;  // Number of entries in diary

    char option;  // Option selected by user

    printf("\n:: Shape-shifting Digital Diary ::\n");

    do {
        displayMenu();
        printf("\nEnter an option: ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                addEntry(diary, &count);
                break;
            case '2':
                viewEntries(diary, count);
                break;
            case '3':
                searchEntries(diary, count);
                break;
            case '4':
                printf("\nExiting digital diary...\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
                break;
        }
    } while (option != '4');

    return 0; 
}

/* Display menu options */
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Exit\n");
}

/* Add a new entry to diary */
void addEntry(DiaryEntry diary[], int *count) {
    char date[20];
    char event[100];

    printf("\nEnter the date (dd/mm/yyyy): ");
    scanf(" %[^\n]s", date);
    printf("Enter the event: ");
    scanf(" %[^\n]s", event);

    strcpy(diary[*count].date, date);
    strcpy(diary[*count].event, event);

    printf("\nEntry added successfully.\n");

    *count += 1;
}

/* View all entries in diary */
void viewEntries(DiaryEntry diary[], int count) {
    if (count == 0) {
        printf("\nNo entries found.\n");
    } else {
        printf("\nAll entries:\n\n");
        for (int i = 0; i < count; i++) {
            printf("%s - %s\n", diary[i].date, diary[i].event);
        }
    }
}

/* Search for an entry in diary */
void searchEntries(DiaryEntry diary[], int count) {
    char searchDate[20];
    int found = 0;

    printf("\nEnter the date to search (dd/mm/yyyy): ");
    scanf(" %[^\n]s", searchDate);

    for (int i = 0; i < count; i++) {
        if (strcmp(diary[i].date, searchDate) == 0) {
            printf("\nEntry found:\n\n");
            printf("%s - %s\n", diary[i].date, diary[i].event);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEntry not found.\n");
    }
}