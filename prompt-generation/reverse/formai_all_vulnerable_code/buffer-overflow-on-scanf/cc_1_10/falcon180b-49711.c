//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
#include <stdio.h>

// Define the maximum number of entries in the diary
#define MAX_ENTRIES 1000

// Define the structure of a diary entry
typedef struct {
    char date[20];
    char time[20];
    char content[5000];
} DiaryEntry;

// Define the global diary array
DiaryEntry diary[MAX_ENTRIES];

// Define the number of entries in the diary
int entryCount = 0;

// Function to display the main menu
void displayMenu() {
    printf("\nDigital Diary\n");
    printf("1. Write an entry\n");
    printf("2. Read entries\n");
    printf("3. Search entries\n");
    printf("4. Quit\n");
}

// Function to write an entry
void writeEntry() {
    char date[20], time[20];
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter the time (hh:mm:ss): ");
    scanf("%s", time);
    printf("Enter the content:\n");
    fgets(diary[entryCount].content, 5000, stdin);
    strcpy(diary[entryCount].date, date);
    strcpy(diary[entryCount].time, time);
    entryCount++;
    printf("\nEntry saved.\n");
}

// Function to read entries
void readEntries() {
    int i;
    if (entryCount == 0) {
        printf("\nNo entries found.\n");
    } else {
        for (i = 0; i < entryCount; i++) {
            printf("\nDate: %s\nTime: %s\nContent:\n%s\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

// Function to search entries
void searchEntries() {
    char keyword[100];
    printf("Enter the keyword to search: ");
    scanf("%s", keyword);
    int i;
    for (i = 0; i < entryCount; i++) {
        if (strstr(diary[i].content, keyword)!= NULL) {
            printf("\nDate: %s\nTime: %s\nContent:\n%s\n", diary[i].date, diary[i].time, diary[i].content);
        }
    }
}

// Function to clear the diary
void clearDiary() {
    entryCount = 0;
    printf("\nDiary cleared.\n");
}

// Main function
int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
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
                clearDiary();
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}