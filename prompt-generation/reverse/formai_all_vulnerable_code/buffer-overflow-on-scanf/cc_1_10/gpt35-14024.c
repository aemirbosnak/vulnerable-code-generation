//FormAI DATASET v1.0 Category: Digital Diary ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ENTRIES 100

// Structure for a diary entry
struct diary_entry {
    char date[15];
    char content[500];
};

// Function to add a new entry to the diary
void add_entry(struct diary_entry entries[], int *count) {
    if(*count == MAX_ENTRIES) {
        printf("Diary is full\n");
        return;
    }

    struct diary_entry new_entry;

    // Get current date
    time_t now = time(NULL);
    strftime(new_entry.date, sizeof(new_entry.date), "%Y-%m-%d", localtime(&now));

    printf("Enter your thoughts for today:\n");
    fgets(new_entry.content, sizeof(new_entry.content), stdin);

    // Clear input buffer
    while(getchar() != '\n');

    entries[*count] = new_entry;
    (*count)++;

    printf("Entry added!\n");
}

// Function to list all entries in the diary
void list_entries(struct diary_entry entries[], int count) {
    if(count == 0) {
        printf("No entries found\n");
        return;
    }

    printf("==== DIARY ENTRIES ====\n");

    for(int i = 0; i < count; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("%s\n", entries[i].content);
        printf("=======================\n");
    }
}

// Main function
int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    printf("Welcome to your digital diary!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new entry\n");
        printf("2. List all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                list_entries(entries, count);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input\n");
        }

    } while(choice != 3);

    return 0;
}