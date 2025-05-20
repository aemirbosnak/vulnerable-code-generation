//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

//define struct for diary entry
struct Entry {
    char date[20];
    char time[20];
    char content[500];
};

//function to add new entry to diary
void addEntry(struct Entry diary[], int* numEntries) {
    //check if diary is full
    if (*numEntries == MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    //prompt user for date
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", diary[*numEntries].date);

    //prompt user for time
    printf("Enter time (hh:mm): ");
    scanf("%s", diary[*numEntries].time);

    //prompt user for content
    printf("Enter content (maximum 500 characters):\n");
    while (getchar() != '\n'); //clear input buffer
    fgets(diary[*numEntries].content, 500, stdin);

    //increment number of entries
    (*numEntries)++;

    printf("Entry added successfully.\n");
}

//function to print all entries in diary
void printEntries(struct Entry diary[], int numEntries) {
    //check if diary is empty
    if (numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Date\t\tTime\t\tContent\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s\t%s\t%s", diary[i].date, diary[i].time, diary[i].content);
        printf("--------------------------------------------------\n");
    }
}

//function to search for entries by date
void searchByDate(struct Entry diary[], int numEntries) {
    //check if diary is empty
    if (numEntries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    char date[20];
    printf("Enter date to search (dd/mm/yyyy): ");
    scanf("%s", date);

    printf("Date\t\tTime\t\tContent\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("%s\t%s\t%s", diary[i].date, diary[i].time, diary[i].content);
            printf("--------------------------------------------------\n");
        }
    }
}

//main function
int main() {
    struct Entry diary[MAX_ENTRIES];
    int numEntries = 0;
    int choice;

    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Print all entries\n");
        printf("3. Search by date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry(diary, &numEntries);
                break;
            case 2:
                printEntries(diary, numEntries);
                break;
            case 3:
                searchByDate(diary, numEntries);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}