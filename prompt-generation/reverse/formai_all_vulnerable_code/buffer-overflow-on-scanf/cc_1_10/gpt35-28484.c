//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to get an integer input from the user
int getIntegerInput() {
    int num;
    scanf("%d", &num);
    return num;
}

// Structure to hold each entry in the diary
struct DiaryEntry {
    int day;
    int month;
    int year;
    char* title;
    char* content;
};

// Function to create a new diary entry
struct DiaryEntry createDiaryEntry() {
    struct DiaryEntry newEntry;
    printf("Enter the day: ");
    newEntry.day = getIntegerInput();
    printf("Enter the month: ");
    newEntry.month = getIntegerInput();
    printf("Enter the year: ");
    newEntry.year = getIntegerInput();
    printf("Enter the title: ");
    newEntry.title = (char*)malloc(100*sizeof(char));
    scanf(" %[^\n]s", newEntry.title);
    printf("Enter the content: ");
    newEntry.content = (char*)malloc(1000*sizeof(char));
    scanf(" %[^\n]s", newEntry.content);
    return newEntry;
}

// Function to display a single diary entry
void displayDiaryEntry(struct DiaryEntry entry) {
    printf("Date: %d/%d/%d\nTitle: %s\nContent: %s\n", entry.day, entry.month, entry.year, entry.title, entry.content);
}

// Function to display all diary entries
void displayAllDiaryEntries(struct DiaryEntry* entries, int count) {
    printf("Number of entries: %d\n", count);
    for(int i=0; i<count; i++) {
        printf("Entry %d:\n", i+1);
        displayDiaryEntry(entries[i]);
        printf("\n");
    }
}

int main() {
    // Create an array to hold the diary entries
    struct DiaryEntry diary[100];
    int count = 0;
    int choice;
    while(1) {
        printf("Digital Diary\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        choice = getIntegerInput();
        switch(choice) {
            case 1:
                if(count < 100) {
                    diary[count] = createDiaryEntry();
                    count++;
                    printf("Entry added successfully!\n");
                }
                else {
                    printf("The diary is full!\n");
                }
                break;
            case 2:
                if(count == 0) {
                    printf("The diary is empty!\n");
                }
                else {
                    displayAllDiaryEntries(diary, count);
                }
                break;
            case 3:
                printf("Exiting the diary...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
    return 0;
}