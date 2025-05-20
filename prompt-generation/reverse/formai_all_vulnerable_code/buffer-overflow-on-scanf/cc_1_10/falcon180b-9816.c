//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int numEntries = 0;

void printMenu() {
    printf("Digital Diary Menu:\n");
    printf("1. Create new entry\n");
    printf("2. View all entries\n");
    printf("3. Search by date\n");
    printf("4. Exit\n");
}

void createEntry() {
    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%d/%m/%Y", localtime(&now));

    char entry[MAX_ENTRY_LENGTH];
    printf("Enter your entry for %s:\n", date);
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    strcpy(diary[numEntries].date, date);
    strcpy(diary[numEntries].entry, entry);

    numEntries++;
    printf("Entry created successfully.\n");
}

void viewEntries() {
    printf("Diary Entries:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

void searchByDate() {
    char date[20];
    printf("Enter the date to search (dd/mm/yyyy): ");
    scanf("%s", date);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(date, diary[i].date) == 0) {
            printf("%s - %s\n", diary[i].date, diary[i].entry);
        }
    }
}

int main() {
    system("clear");
    srand(time(NULL));

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchByDate();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}