//FormAI DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct diary {
    char date[10];
    char content[200];
};

typedef struct diary Diary;

void add_entry(Diary* entries, int* num_entries) {
    char date[10];
    char content[200];
    printf("\nEnter the date in DD/MM/YYYY format: ");
    scanf("%s", date);
    getchar(); // To consume extra newline character
    printf("Enter the diary entry: ");
    fgets(content, 200, stdin);
    content[strcspn(content, "\n")] = '\0'; // To remove trailing newline character
    strcpy(entries[*num_entries].date, date);
    strcpy(entries[*num_entries].content, content);
    (*num_entries)++;
    printf("\nDiary entry added successfully! Press enter to continue.");
    getchar(); // To wait for user input before continuing
}

void view_entries(Diary* entries, int num_entries) {
    printf("\nShowing all diary entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("\n%s:\n%s\n", entries[i].date, entries[i].content);
    }
    printf("\nPress enter to continue.");
    getchar(); // To wait for user input before continuing
}

int main() {
    Diary entries[50];
    int num_entries = 0;
    int choice = 0;
    while (1) {
        printf("\nDigital Diary:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume extra newline character
        if (choice == 1) {
            if (num_entries >= 50) {
                printf("\nError! Maximum number of entries reached.\n");
            }
            else {
                add_entry(entries, &num_entries);
            }
        }
        else if (choice == 2) {
            if (num_entries == 0) {
                printf("\nNo diary entries to display.\n");
            }
            else {
                view_entries(entries, num_entries);
            }
        }
        else if (choice == 3) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }
        else {
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}