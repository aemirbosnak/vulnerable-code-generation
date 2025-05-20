//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char title[80];
    char entry[500];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int numEntries, char* date, char* title, char* entry) {
    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].title, title);
    strcpy(diary[numEntries].entry, entry);
    numEntries++;
}

void printEntries(DiaryEntry* diary, int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        printf("Date: %s\nTitle: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].title, diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;
    char username[20];

    printf("Welcome to the Digital Diary!\n");
    printf("Please enter your name:\n");
    scanf("%s", username);

    printf("\n%s's Digital Diary\n", username);

    while (1) {
        int choice;
        printf("\nWhat would you like to do?\n");
        printf("1. Add an entry\n2. View entries\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            char date[20];
            char title[80];
            char entry[500];

            printf("\nEnter the date (YYYY-MM-DD):\n");
            scanf("%s", date);

            printf("Enter the title:\n");
            scanf("%s", title);

            printf("Enter the entry:\n");
            scanf("%[^\n]", entry);

            addEntry(diary, numEntries, date, title, entry);
            numEntries++;

            printf("\nEntry added successfully!\n");
        } else if (choice == 2) {
            if (numEntries == 0) {
                printf("\nNo entries yet.\n");
            } else {
                printEntries(diary, numEntries);
            }
        } else if (choice == 3) {
            printf("\nExiting program...\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}