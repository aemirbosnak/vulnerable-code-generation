//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char time[20];
    char entry[500];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    if (numEntries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }
    time_t now = time(NULL);
    struct tm* currentTime = localtime(&now);
    strftime(diary[numEntries].date, 20, "%Y-%m-%d", currentTime);
    strftime(diary[numEntries].time, 20, "%H:%M:%S", currentTime);
    printf("Enter your diary entry:\n");
    fgets(diary[numEntries].entry, 500, stdin);
    numEntries++;
    printf("Entry added.\n");
}

void viewEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < numEntries; i++) {
        printf("Date: %s\nTime: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].time, diary[i].entry);
    }
}

void searchEntries() {
    char keyword[50];
    printf("Enter keyword to search:\n");
    scanf("%s", keyword);
    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("Date: %s\nTime: %s\nEntry:\n%s\n\n", diary[i].date, diary[i].time, diary[i].entry);
        }
    }
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. View Entries\n3. Search Entries\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}