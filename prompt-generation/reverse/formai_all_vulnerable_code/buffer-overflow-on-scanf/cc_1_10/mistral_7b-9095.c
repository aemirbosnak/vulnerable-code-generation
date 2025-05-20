//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_MAX_ENTRIES 20
#define ENTRY_MAX_LENGTH 100

// Structure to store diary entries
typedef struct {
    char title[ENTRY_MAX_LENGTH];
    char content[ENTRY_MAX_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[DIARY_MAX_ENTRIES];
int current_entry = 0;

// Function to get the current date and time
void get_timestamp(time_t *timestamp) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    *timestamp = mktime(timeinfo);
}

// Function to add a new diary entry
void add_entry(const char *title, const char *content) {
    if (current_entry >= DIARY_MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }

    get_timestamp(&diary[current_entry].timestamp);
    strncpy(diary[current_entry].title, title, ENTRY_MAX_LENGTH);
    strncpy(diary[current_entry].content, content, ENTRY_MAX_LENGTH);

    current_entry++;
}

// Function to view the contents of a specific diary entry
void view_entry(int index) {
    if (index >= 0 && index < current_entry) {
        printf("\nTitle: %s\n", diary[index].title);
        printf("Content:\n%s\n", diary[index].content);
        printf("Timestamp: %s", ctime(&diary[index].timestamp));
    } else {
        printf("Invalid index. Cannot view entry.\n");
    }
}

int main() {
    char title[ENTRY_MAX_LENGTH];
    char content[ENTRY_MAX_LENGTH];
    int choice, index;

    printf("\n-------------------------\n");
    printf("| Welcome to Digital Diary |\n");
    printf("|-------------------------|\n");

    while (1) {
        printf("\n1. Add Entry\n2. View Entry\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);
                add_entry(title, content);
                break;
            case 2:
                printf("Enter index of entry to view: ");
                scanf("%d", &index);
                view_entry(index);
                break;
            case 3:
                printf("Exiting Diary Program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}