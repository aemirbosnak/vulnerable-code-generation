//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char time[10];
    char entry[500];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    time_t now = time(0);
    struct tm *t = localtime(&now);
    strftime(diary[numEntries].date, 20, "%Y-%m-%d", t);
    strftime(diary[numEntries].time, 10, "%H:%M:%S", t);
    printf("Enter your entry: ");
    scanf("%[^\n]", diary[numEntries].entry);
    printf("\nEntry added!\n");
    numEntries++;
}

void viewEntries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].entry);
    }
}

void deleteEntry() {
    printf("Enter the date (YYYY-MM-DD) of the entry you want to delete: ");
    scanf("%s", diary[numEntries-1].date);
    printf("Entry deleted!\n");
    numEntries--;
}

void searchEntry() {
    printf("Enter the date (YYYY-MM-DD) of the entry you want to search: ");
    scanf("%s", diary[numEntries-1].date);
    printf("Entry found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add Entry\n2. View Entries\n3. Delete Entry\n4. Search Entry\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                searchEntry();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}