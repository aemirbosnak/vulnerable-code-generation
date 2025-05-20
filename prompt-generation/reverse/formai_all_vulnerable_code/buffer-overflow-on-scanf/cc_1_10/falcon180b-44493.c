//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 5000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

Entry diary[MAX_ENTRIES];
int numEntries = 0;

void displayMenu() {
    printf("\n");
    printf("Digital Diary\n");
    printf("1. Write an entry\n");
    printf("2. Read entries\n");
    printf("3. Search entries\n");
    printf("4. Exit\n");
    printf("\n");
}

void writeEntry() {
    char date[20];
    time_t now = time(NULL);
    strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

    printf("Enter your entry for %s:\n", date);
    fgets(diary[numEntries].entry, MAX_ENTRY_LENGTH, stdin);
    strcpy(diary[numEntries].date, date);
    numEntries++;

    printf("\nEntry saved.\n");
}

void readEntries() {
    if (numEntries == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n");
    printf("Date\tEntry\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\n", diary[i].date, diary[i].entry);
    }
}

void searchEntries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("\nEnter a keyword to search for:\n");
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strstr(diary[i].entry, keyword)) {
            printf("\n%s\n%s\n", diary[i].date, diary[i].entry);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo entries found with that keyword.\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to your digital diary!\n");
    printf("Press any key to continue...\n");
    getchar();

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            writeEntry();
            break;
        case 2:
            readEntries();
            break;
        case 3:
            searchEntries();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}