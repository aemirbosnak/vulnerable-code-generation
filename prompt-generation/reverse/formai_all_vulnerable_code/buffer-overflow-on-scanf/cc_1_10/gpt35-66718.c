//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
/*
* C Digital Diary Example Program
* Author: Chatbot
* Date: 26th September 2021
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 200

// Data structure to store diary entries
struct DiaryEntry {
    char date[20];
    char subject[MAX_STRING_LENGTH];
    char content[MAX_STRING_LENGTH];
};

// Global variables
int numEntries = 0;
struct DiaryEntry diary[MAX_ENTRIES];

// Function to display menu and get menu choice from user
int get_menu_choice() {
    int choice;

    printf("\n\n~~~ Digital Diary ~~~\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Exit\n\n");
    printf("Enter your Choice: ");
    scanf("%d", &choice);

    return choice;
}

// Function to add new diary entry
void add_entry() {
    if(numEntries == MAX_ENTRIES) {
        printf("\nMaximum number of entries reached!");
        return;
    }

    struct DiaryEntry newEntry;

    printf("\n\n~~~ Add New Entry ~~~\n");
    printf("Subject: ");
    scanf("\n%[^\n]", newEntry.subject);
    printf("Content: ");
    scanf("\n%[^\n]", newEntry.content);

    time_t now = time(NULL);
    strftime(newEntry.date, sizeof(newEntry.date), "%d/%m/%Y %H:%M:%S", localtime(&now));

    diary[numEntries] = newEntry;
    numEntries++;

    printf("\nEntry Added Successfully!");
}

// Function to view all diary entries
void view_entries() {
    if(numEntries == 0) {
        printf("\nNo entries yet!");
        return;
    }

    printf("\n\n~~~ View all entries ~~~\n");
    for(int i=0; i<numEntries; i++) {
        printf("\n%d.\nDate: %s\nSubject: %s\nContent: %s\n", 
            i+1, diary[i].date, diary[i].subject, diary[i].content);
    }
}

int main() {
    int choice;

    while(1) {
        choice = get_menu_choice();

        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("\n~~~ Exiting Digital Diary ~~~\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again!\n");
        }
    }

    return 0;
}