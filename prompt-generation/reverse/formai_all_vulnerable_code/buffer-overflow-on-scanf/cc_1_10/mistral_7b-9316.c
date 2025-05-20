//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_MAX_SIZE 100
#define ENTRY_MAX_LEN 200

typedef struct DiaryEntry {
    time_t timestamp;
    char content[ENTRY_MAX_LEN];
} DiaryEntry;

DiaryEntry diary[DIARY_MAX_SIZE];
int diary_index = 0;

void print_menu() {
    printf("\nPost-Apocalyptic Digital Diary\n");
    printf("--------------------------------\n");
    printf("1. Add new entry\n");
    printf("2. Read last entry\n");
    printf("3. List all entries\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (diary_index >= DIARY_MAX_SIZE) {
        printf("Diary is full. Delete some entries to add new ones.\n");
        return;
    }

    time_t now = time(NULL);
    diary[diary_index].timestamp = now;

    printf("Enter content for entry %d: ", diary_index + 1);
    fgets(diary[diary_index].content, ENTRY_MAX_LEN, stdin);
    diary[diary_index].content[strcspn(diary[diary_index].content, "\n")] = 0;

    diary_index++;
}

void read_last_entry() {
    if (diary_index <= 0) {
        printf("No entries yet.\n");
        return;
    }

    DiaryEntry* last_entry = &diary[diary_index - 1];
    struct tm* timeinfo;
    char time_buffer[80];

    timeinfo = localtime(&(last_entry->timestamp));

    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    printf("\nLast Entry:\n");
    printf("Date and Time: %s\n", time_buffer);
    printf("Content: %s\n", last_entry->content);
}

void list_all_entries() {
    if (diary_index <= 0) {
        printf("No entries yet.\n");
        return;
    }

    printf("\nAll Entries:\n");
    for (int i = 0; i < diary_index; i++) {
        DiaryEntry* entry = &diary[i];
        struct tm* timeinfo;
        char time_buffer[80];

        timeinfo = localtime(&(entry->timestamp));

        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

        printf("\nEntry %d:\n", i + 1);
        printf("Date and Time: %s\n", time_buffer);
        printf("Content: %s\n", entry->content);
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                read_last_entry();
                break;
            case 3:
                list_all_entries();
                break;
            case 4:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}