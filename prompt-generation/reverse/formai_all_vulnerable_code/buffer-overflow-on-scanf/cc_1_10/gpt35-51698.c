//FormAI DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

int num_entries = 0;
struct entry {
    char date[11];
    char body[1000];
} diary[MAX_ENTRIES];


void printMenu() {
    printf("Digital Diary Options\n");
    printf("1. Add Entry\n");
    printf("2. Edit Entry\n");
    printf("3. View All Entries\n");
    printf("4. Exit\n");
}

void addEntry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, the diary is full!\n");
        return;
    }
    printf("Enter today's date (DD/MM/YYYY): ");
    scanf("%s", diary[num_entries].date);
    getchar();
    printf("Enter your entry today:\n");
    fgets(diary[num_entries].body, 1000, stdin);
    num_entries++;
    printf("Entry added successfully!\n");
}

void editEntry() {
    char date[11];
    printf("Enter the date of the entry you wish to edit (DD/MM/YYYY): ");
    scanf("%s", date);
    getchar();

    for (int i=0; i<num_entries; i++) {
        if (strcmp(diary[i].date, date) == 0) {
            printf("Enter the new entry for %s:\n", date);
            fgets(diary[i].body, 1000, stdin);
            printf("Entry edited successfully!\n");
            return;
        }
    }
    printf("Sorry, no entry was found for %s.\n", date);
}

void viewEntries() {
    if (num_entries == 0) {
        printf("Sorry, there are no entries to display. Add an entry first!\n");
        return;
    }
    for (int i=0; i<num_entries; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].body);
        printf("---------------------------\n");
    }
}

int main() {
    printf("Welcome to your digital diary! Let's start writing!\n\n");
    int option;
    while (1) {
        printMenu();
        scanf("%d", &option);
        getchar();
        switch(option) {
            case 1: addEntry(); break;
            case 2: editEntry(); break;
            case 3: viewEntries(); break;
            case 4: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid option. Try again.\n"); break;
        }
    }
    return 0;
}