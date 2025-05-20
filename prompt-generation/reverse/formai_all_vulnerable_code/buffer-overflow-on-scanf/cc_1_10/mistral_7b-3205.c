//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to store diary entry data
typedef struct {
    char title[50];
    char content[100];
    time_t timestamp;
} DiaryEntry;

// Function to get current time and save it to a DiaryEntry struct
void get_timestamp(DiaryEntry *entry) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    entry->timestamp = rawtime;
    strftime(entry->title, sizeof(entry->title), "%Y-%m-%d %H:%M:%S", timeinfo);
}

// Function to add a new entry to the diary
void add_entry(DiaryEntry *diary, int *num_entries, const char *title, const char *content) {
    if (*num_entries < 10) { // Array has room for 10 entries
        get_timestamp(&diary[*num_entries]);
        strcpy(diary[*num_entries].content, content);
        strcpy(diary[*num_entries].title, title);
        (*num_entries)++;
    } else {
        printf("Diary is full. Can't add new entry.\n");
    }
}

// Function to display all entries in the diary
void display_diary(DiaryEntry *diary, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("\nTitle: %s\nDate: %s\nContent:\n%s\n", diary[i].title, diary[i].title, diary[i].content);
    }
}

int main() {
    DiaryEntry diary[10];
    int num_entries = 0;

    while (1) {
        printf("\n1. Add Entry\n2. Display Diary\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char title[50];
                char content[100];

                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter content: ");
                scanf("%[^\n]s", content);

                add_entry(diary, &num_entries, title, content);
                break;
            }

            case 2: {
                display_diary(diary, num_entries);
                break;
            }

            case 3: {
                printf("Quitting...\n");
                exit(0);
            }

            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}