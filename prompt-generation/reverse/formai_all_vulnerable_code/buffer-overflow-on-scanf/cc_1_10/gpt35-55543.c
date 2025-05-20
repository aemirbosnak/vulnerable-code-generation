//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 500
#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[11];
    char time[9];
    char text[MAX_ENTRY_SIZE];
};

struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
};

void add_entry(struct Diary* diary) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    time_t current_time;
    struct tm* time_info;
    char time_str[9];
    char date_str[11];
    char text[MAX_ENTRY_SIZE];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(time_str, 9, "%H:%M:%S", time_info);
    strftime(date_str, 11, "%Y-%m-%d", time_info);

    printf("Enter your diary entry:\n");
    fgets(text, MAX_ENTRY_SIZE, stdin);

    struct DiaryEntry new_entry;
    strncpy(new_entry.date, date_str, 11);
    strncpy(new_entry.time, time_str, 9);
    strncpy(new_entry.text, text, MAX_ENTRY_SIZE);

    diary->entries[diary->num_entries] = new_entry;
    diary->num_entries++;
}

void display_entries(struct Diary* diary) {
    printf("Diary Entries:\n");

    for (int i = 0; i < diary->num_entries; i++) {
        printf("Entry %d:\n", i+1);
        printf("Date: %s\n", diary->entries[i].date);
        printf("Time: %s\n", diary->entries[i].time);
        printf("Text: %s\n", diary->entries[i].text);
    }

    printf("\n");
}

int main() {
    struct Diary diary;
    diary.num_entries = 0;
    int choice;

    while(1) {
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                display_entries(&diary);
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}