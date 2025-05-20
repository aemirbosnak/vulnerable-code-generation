//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct DiaryEntry {
    time_t timestamp;
    char description[ENTRY_SIZE];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int current_entry = 0;

void print_header() {
    printf("\n========== DIGITAL DIARY ==========\n");
    printf("Entry %d | Date        | Description\n", current_entry + 1);
}

void print_entry(DiaryEntry *entry) {
    char date_str[32];
    struct tm *tm_info = localtime(&entry->timestamp);

    strftime(date_str, sizeof(date_str), "%Y-%m-%d", tm_info);

    printf("| %d-%s | %s\n", (int)tm_info->tm_year + 1900, date_str, entry->description);
}

void save_entry() {
    DiaryEntry *entry = &diary[current_entry];

    time(&entry->timestamp);

    printf("\nEnter your entry: ");
    fgets(entry->description, ENTRY_SIZE, stdin);
    entry->description[strcspn(entry->description, "\n")] = '\0';

    current_entry++;

    if (current_entry == MAX_ENTRIES) {
        printf("\nDiary is full!\n");
        current_entry--;
    }
}

int main() {
    int choice;

    while (1) {
        system("clear");
        print_header();

        for (int i = 0; i < current_entry; i++) {
            print_entry(&diary[i]);
        }

        printf("\n1. Add new entry\n2. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                save_entry();
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}