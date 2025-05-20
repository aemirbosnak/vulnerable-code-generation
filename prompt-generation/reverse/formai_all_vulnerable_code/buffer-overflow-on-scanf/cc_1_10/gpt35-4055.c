//FormAI DATASET v1.0 Category: Digital Diary ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100 // maximum number of entries allowed
#define MAX_ENTRY_LEN 500 // maximum length of each diary entry

typedef struct {
    time_t timestamp; // timestamp of the entry
    char text[MAX_ENTRY_LEN]; // text of the entry
} entry_t;

entry_t entries[MAX_ENTRIES]; // array of diary entries
int num_entries = 0; // current number of entries

void add_entry(char* text) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: diary full\n");
        return;
    }
    time_t timestamp = time(NULL);
    entry_t new_entry = {timestamp, ""};
    strncpy(new_entry.text, text, MAX_ENTRY_LEN-1);
    entries[num_entries++] = new_entry;
    printf("Entry added successfully\n");
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        struct tm* timeinfo = localtime(&entries[i].timestamp);
        char timebuf[20];
        strftime(timebuf, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
        printf("%s: %s\n", timebuf, entries[i].text);
    }
}

int main() {
    int choice;
    char entry_text[MAX_ENTRY_LEN];
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter diary entry text:\n");
                scanf(" %[^\n]s", entry_text);
                add_entry(entry_text);
                break;
            case 2:
                view_entries();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}