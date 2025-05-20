//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char entry[ENTRY_SIZE];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry();
void view_entries();
void delete_entry();
void display_menu();
void timestamp_to_string(time_t timestamp, char *buffer);

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting the diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }
    return 0;
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full. Please delete some entries before adding new ones.\n");
        return;
    }
    
    printf("Enter your diary entry: ");
    fgets(diary[entry_count].entry, ENTRY_SIZE, stdin);
    
    diary[entry_count].timestamp = time(NULL);
    entry_count++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found in your diary.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        char time_buffer[26];
        timestamp_to_string(diary[i].timestamp, time_buffer);
        printf("Entry %d (%s): %s", i + 1, time_buffer, diary[i].entry);
    }
}

void delete_entry() {
    int index;
    printf("Enter the entry number to delete (1 to %d): ", entry_count);
    scanf("%d", &index);
    getchar();  // Consume newline character
    
    if (index < 1 || index > entry_count) {
        printf("Invalid entry number. Please try again.\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry %d deleted successfully!\n", index);
}

void display_menu() {
    printf("\n=== Digital Diary Menu ===\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Exit\n");
}

void timestamp_to_string(time_t timestamp, char *buffer) {
    struct tm *tm_info;
    tm_info = localtime(&timestamp);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
}