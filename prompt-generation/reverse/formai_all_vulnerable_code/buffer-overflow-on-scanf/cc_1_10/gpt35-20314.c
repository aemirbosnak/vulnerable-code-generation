//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of entries allowed in the diary
#define MAX_ENTRIES 10
// Define the maximum length of each entry
#define MAX_LENGTH 1000

// Declare struct for each diary entry
struct diary_entry {
    char date[20];
    char body[MAX_LENGTH];
};

// Function to display all entries in the diary
void view_entries(struct diary_entry entries[], int num_entries) {
    printf("DIARY ENTRIES:\n\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Entry: %s\n\n", entries[i].body);
    }
}

int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char command[10];

    while (1) {
        printf("Enter a command (ADD, VIEW, or QUIT): ");
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            // Add a new entry to the diary
            if (num_entries < MAX_ENTRIES) {
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                sprintf(entries[num_entries].date, "%04d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
                printf("Enter your diary entry (max %d characters):\n", MAX_LENGTH);
                scanf(" %[^\n]", entries[num_entries].body);
                num_entries++;
                printf("Entry added!\n");
            } else {
                printf("Diary is full! Please delete an entry to add a new one.\n");
            }
        } else if (strcmp(command, "VIEW") == 0) {
            // Display all entries in the diary
            if (num_entries == 0) {
                printf("Diary is empty! Please add an entry.\n");
            } else {
                view_entries(entries, num_entries);
            }
        } else if (strcmp(command, "QUIT") == 0) {
            // Exit the program
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command! Please enter ADD, VIEW, or QUIT.\n");
        }
    }

    return 0;
}