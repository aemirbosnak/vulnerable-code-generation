//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
// *** My Digital Diary *** 
// Written by Ada Lovelace

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ENTRY_LIMIT 100
#define TEXT_LIMIT 500

// Entry struct 
struct Entry {
    char title[100];
    char text[TEXT_LIMIT];
    struct tm date;
};

// Global variables
int count = 0;
struct Entry diary[ENTRY_LIMIT];

// Function prototypes
void menu(void);
void newEntry(void);
void displayEntries(void);
void displayEntry(int i);

int main(void) {
    menu();
    return 0;
}

// Function to display menu options
void menu(void) {
    int choice;
    printf("******** MY DIGITAL DIARY ********\n");
    printf("1. Add new entry\n");
    printf("2. View all entries\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            newEntry();
            break;
        case 2:
            displayEntries();
            break;
        case 3:
            printf("Exiting...");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Try again.\n");
            menu();
    }
}

// Function to add new diary entry
void newEntry(void) {
    if (count >= ENTRY_LIMIT) {
        printf("Sorry, maximum entries limit reached.\n");
    } else {
        printf("Enter the title of the entry:\n");
        scanf(" %[^\n]s", diary[count].title);

        printf("Enter the content of the entry:\n");
        scanf(" %[^\n]s", diary[count].text);

        time_t now = time(NULL);
        diary[count].date = *localtime(&now);

        printf("New entry created successfully!\n");

        count++;
    }
    menu();
}

// Function to display all diary entries
void displayEntries(void) {
    if (count == 0) {
        printf("No entries yet.\n");
    } else {
        printf("******** ALL ENTRIES ********\n");
        for (int i = 0; i < count; i++) {
            displayEntry(i);
        }
    }
    menu();
}

// Function to display a single diary entry
void displayEntry(int i) {
    printf("Title: %s\n", diary[i].title);
    printf("Date: %02d/%02d/%04d\n", diary[i].date.tm_mday, diary[i].date.tm_mon + 1, diary[i].date.tm_year + 1900);
    printf("Content: %s\n", diary[i].text);
    printf("--------------------------------\n");
}