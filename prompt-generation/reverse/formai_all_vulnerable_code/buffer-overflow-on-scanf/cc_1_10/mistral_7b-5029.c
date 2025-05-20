//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for diary entry
typedef struct {
    time_t timestamp;
    char title[100];
    char content[500];
} DiaryEntry;

// Function to get current time
time_t get_current_time() {
    time_t rawtime;
    struct tm *timeinfo;

    char time_string[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Convert string to time_t
    strptime(time_string, "%Y-%m-%d %H:%M:%S", &timeinfo);
    time_t current_time = mktime(timeinfo);

    return current_time;
}

// Function to write a new entry
void write_entry(DiaryEntry *entry, char *title, char *content) {
    entry->timestamp = get_current_time();
    strcpy(entry->title, title);
    strcpy(entry->content, content);
}

// Function to display an entry
void display_entry(DiaryEntry *entry) {
    printf("\nTitle: %s\n", entry->title);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
    printf("Content:\n%s\n", entry->content);
}

// Function to add a new entry
void add_entry(DiaryEntry *diary, int *num_entries, char *title, char *content) {
    DiaryEntry new_entry;

    write_entry(&new_entry, title, content);

    diary[*num_entries] = new_entry;
    (*num_entries)++;
}

// Function to display all entries
void display_all_entries(DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        display_entry(&diary[i]);
    }
}

// Main function
int main() {
    int num_entries = 0;
    DiaryEntry diary[100];

    char title[100];
    char content[500];

    while (1) {
        printf("\nDigital Diary\n");
        printf("1. Add new entry\n");
        printf("2. Display all entries\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]", content);
                add_entry(diary, &num_entries, title, content);
                break;
            case 2:
                printf("\nAll entries:\n");
                display_all_entries(diary, num_entries);
                break;
            case 3:
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}