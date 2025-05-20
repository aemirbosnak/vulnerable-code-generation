//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to store the diary entry
struct DiaryEntry {
    char date[20];
    char content[500];
};

// Function to get the current date
void getCurrentDate(char* buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(buffer, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

// Function to add a new entry to the diary
void addEntry(struct DiaryEntry* diary, int* count) {
    char date[20];
    char content[500];
    
    getCurrentDate(date);
    
    printf("Sweetheart, what lovely moment would you like to pen down today? \n");
    printf("Content (max 500 chars): ");
    getchar(); // To clear the buffer before taking input
    fgets(content, sizeof(content), stdin);
    content[strcspn(content, "\n")] = 0; // Remove the trailing newline

    strcpy(diary[*count].date, date);
    strcpy(diary[*count].content, content);
    
    (*count)++;
    printf("Darling, your memory has been saved!\n\n");
}

// Function to display all entries
void displayEntries(struct DiaryEntry* diary, int count) {
    if (count == 0) {
        printf("Oh my love, there are no entries in your diary yet.\n");
    } else {
        printf("Here are the precious thoughts of your heart:\n");
        for (int i = 0; i < count; i++) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            printf("---------------\n");
        }
    }
}

// Function to search for an entry by date
void searchEntry(struct DiaryEntry* diary, int count) {
    char searchDate[20];
    
    printf("Which date would you like to search? (dd-mm-yyyy): ");
    scanf("%s", searchDate);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(diary[i].date, searchDate) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Oh darling, there’s no entry for this date in your heart's book.\n");
    }
}

int main() {
    struct DiaryEntry diary[100];
    int count = 0;
    int choice;
    
    printf("Welcome to your Romantic Digital Diary!\n");
    
    while (1) {
        printf("Menu:\n");
        printf("1. Add a new entry\n");
        printf("2. Display all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(diary, &count);
                break;
            case 2:
                displayEntries(diary, count);
                break;
            case 3:
                searchEntry(diary, count);
                break;
            case 4:
                printf("Goodbye my love! May your heart be forever warm and your thoughts sweet.\n");
                return 0;
            default:
                printf("Oh sweet! That option is not recognized. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}