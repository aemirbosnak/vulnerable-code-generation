//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256
#define DATE_FORMAT "%Y-%m-%d %H:%M:%S"

typedef struct {
    char title[128];
    char description[128];
    time_t timestamp;
} DiaryEntry;

DiaryEntry entries[MAX_ENTRIES];
int current_entry = 0;

void print_menu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add new entry\n");
    printf("2. View last entry\n");
    printf("3. View all entries\n");
    printf("4. Delete last entry\n");
    printf("5. Exit\n");
}

void add_entry(const char* title, const char* description) {
    if (current_entry >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    strcpy(entries[current_entry].title, title);
    strcpy(entries[current_entry].description, description);
    time(&entries[current_entry].timestamp);
    current_entry++;
}

void view_last_entry() {
    if (current_entry == 0) {
        printf("No entries yet.\n");
        return;
    }

    struct tm* timeinfo;
    char date_str[128];

    timeinfo = localtime(&entries[current_entry - 1].timestamp);
    strftime(date_str, sizeof(date_str), DATE_FORMAT, timeinfo);

    printf("\nEntry from %s\n", date_str);
    printf("Title: %s\n", entries[current_entry - 1].title);
    printf("Description: %s\n", entries[current_entry - 1].description);
}

void view_all_entries() {
    if (current_entry == 0) {
        printf("No entries yet.\n");
        return;
    }

    int i;
    for (i = 0; i < current_entry; i++) {
        struct tm* timeinfo;
        char date_str[128];

        timeinfo = localtime(&entries[i].timestamp);
        strftime(date_str, sizeof(date_str), DATE_FORMAT, timeinfo);

        printf("\nEntry from %s\n", date_str);
        printf("Title: %s\n", entries[i].title);
        printf("Description: %s\n", entries[i].description);
    }
}

int main() {
    char title[128];
    char description[128];

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                printf("Enter description: ");
                scanf("%s", description);
                add_entry(title, description);
                printf("Entry added successfully.\n");
                break;
            case 2:
                view_last_entry();
                break;
            case 3:
                view_all_entries();
                break;
            case 4:
                if (current_entry > 0)
                    current_entry--;
                printf("Last entry deleted.\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}