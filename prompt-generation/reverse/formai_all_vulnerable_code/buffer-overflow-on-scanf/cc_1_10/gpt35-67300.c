//FormAI DATASET v1.0 Category: Digital Diary ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct DiaryEntry {
    char title[30];
    char content[500];
    char date[30];
} DiaryEntry;

void addEntryToFile(DiaryEntry* entry) {
    FILE* fp = fopen("diary.txt", "a");
    if(fp == NULL) {
        printf("ERROR: Unable to open file\n");
        return;
    }
    fprintf(fp, "%s\n%s\n%s\n", entry->date, entry->title, entry->content);
    fclose(fp);
}

int printAllEntries() {
    FILE* fp = fopen("diary.txt", "r");
    if(fp == NULL) {
        printf("ERROR: Unable to open file\n");
        return 0;
    }
    DiaryEntry entry;
    int count = 0;
    while(fgets(entry.date, sizeof entry.date, fp)) {
        fgets(entry.title, sizeof entry.title, fp);
        fgets(entry.content, sizeof entry.content, fp);
        printf("Date: %sTitle: %sContent: %s\n", entry.date, entry.title, entry.content);
        count++;
    }
    fclose(fp);
    return count;
}

DiaryEntry* readEntryFromUser() {
    DiaryEntry* entry = (DiaryEntry*) malloc(sizeof(DiaryEntry));
    printf("\nPlease enter your diary entry title (max 30 characters):\n");
    scanf(" %[^\n]s", entry->title);
    printf("\nPlease enter your diary entry content (max 500 characters):\n");
    scanf(" %[^\n]s", entry->content);
    time_t now;
    time(&now);
    strcpy(entry->date, ctime(&now));
    return entry;
}

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int choice;
    do {
        clearScreen();
        printf("Digital Diary\n");
        printf("1. Add entry\n");
        printf("2. View all entries\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                DiaryEntry* entry = readEntryFromUser();
                addEntryToFile(entry);
                printf("\n\nEntry added successfully!\n");
                break;
            }
            case 2: {
                int count = printAllEntries();
                if(count == 0) {
                    printf("\n\nNo entries found!\n");
                }
                break;
            }
            case 0:
                printf("\n\nExiting Digital Diary. Goodbye!\n");
                break;
            default:
                printf("\n\nInvalid choice. Please try again!\n");
        }
        printf("\nPress any key to continue...");
        getchar();
        getchar();
    } while(choice != 0);
    return 0;
}