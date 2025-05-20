//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char time[10];
    char entry[500];
} DiaryEntry;

void addEntry(DiaryEntry* diary, int index, char* date, char* time, char* entry) {
    strcpy(diary[index].date, date);
    strcpy(diary[index].time, time);
    strcpy(diary[index].entry, entry);
}

void printEntries(DiaryEntry* diary, int numEntries) {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].entry);
    }
}

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int numEntries = 0;
    char date[20];
    char time[10];
    char entry[500];

    printf("Welcome to the Sherlock Holmes Digital Diary!\n");

    while (1) {
        printf("\nOptions:\n1. Add Entry\n2. View Entries\n3. Exit\n");
        scanf("%d", &numEntries);

        switch (numEntries) {
        case 1:
            printf("Enter date (DD/MM/YYYY): ");
            scanf("%s", date);
            printf("Enter time (HH:MM:SS): ");
            scanf("%s", time);
            printf("Enter entry:\n");
            scanf("%[^\n]", entry);

            addEntry(diary, numEntries - 1, date, time, entry);
            printf("Entry added successfully!\n");
            break;

        case 2:
            printf("Diary Entries:\n");
            printEntries(diary, numEntries);
            break;

        case 3:
            printf("Thank you for using the Sherlock Holmes Digital Diary!\n");
            exit(0);

        default:
            printf("Invalid option selected.\n");
        }
    }

    return 0;
}