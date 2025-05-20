//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char title[100];
    char content[500];
    char date[20];
} Diary;

int DiaryCount = 0;

void AddEntry(Diary *entries) {
    Diary entry;

    printf("\nEnter Title: ");
    scanf(" %[^\n]s", entry.title);

    printf("Enter Content: ");
    scanf(" %[^\n]s", entry.content);

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(entry.date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

    entries[DiaryCount] = entry;
    DiaryCount++;
    printf("\nEntry Added Successfully!\n\n");
}

void ViewEntries(Diary *entries) {
    if (DiaryCount == 0) {
        printf("\nNo Entries Found!\n\n");
        return;
    }

    printf("\n---- View Entries ----\n\n");

    for (int i = 0; i < DiaryCount; i++) {
        printf("Title: %s\n", entries[i].title);
        printf("Content: %s\n", entries[i].content);
        printf("Date: %s\n", entries[i].date);
        printf("\n");
    }

    printf("-----------------------\n\n");
}

int main() {
    Diary entries[100];
    int option = 0;

    while (1) {
        printf("---- Digital Diary ----\n\n");
        printf("1) Add Entry\n");
        printf("2) View Entries\n");
        printf("3) Quit\n\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                AddEntry(entries);
                break;

            case 2:
                ViewEntries(entries);
                break;

            case 3:
                printf("\nExiting Program...\n\n");
                return 0;

            default:
                printf("\nInvalid Option!\n\n");
        }
    }
}