//FormAI DATASET v1.0 Category: Digital Diary ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 20

struct diary_entry {
    char timestamp[20];
    char content[500];
};

void add_entry(struct diary_entry entries[], int *num_entries);
void view_entries(struct diary_entry entries[], int num_entries);

int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int num_entries = 0;
    int choice;

    while (1) {
        printf("*** Digital Diary ***\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                view_entries(entries, num_entries);
                break;
            case 3:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid Choice. Try Again.\n");
        }

        printf("\n");
    }

    return 0;
}

void add_entry(struct diary_entry entries[], int *num_entries) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Diary is Full!\n");
        return;
    }

    struct diary_entry new_entry;

    // Get Timestamp
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(new_entry.timestamp, sizeof(new_entry.timestamp), "%m/%d/%Y %I:%M:%S %p", tm);

    // Get Content
    printf("Enter your entry content: ");
    getchar(); // Remove trailing newline from previous scanf
    fgets(new_entry.content, sizeof(new_entry.content), stdin);

    // Add entry to diary
    entries[*num_entries] = new_entry;
    (*num_entries)++;

    printf("Entry added successfully!\n");
}

void view_entries(struct diary_entry entries[], int num_entries) {
    if (num_entries == 0) {
        printf("No entries found!\n");
        return;
    }

    printf("Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("[%s]\n%s\n", entries[i].timestamp, entries[i].content);
    }
}