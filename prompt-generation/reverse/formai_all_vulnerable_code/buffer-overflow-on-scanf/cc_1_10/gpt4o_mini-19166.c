//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

typedef struct {
    char entry[MAX_LENGTH];
    time_t timestamp;
} DiaryEntry;

void add_entry();
void view_entries();
void clear_entries();
void display_menu();
void flush_input_buffer();

int main() {
    int choice;
    do {
        display_menu();
        printf("Please select an option: ");
        scanf("%d", &choice);
        flush_input_buffer();

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                clear_entries();
                break;
            case 4:
                printf("Exiting diary program. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        printf("Error opening diary file!");
        return;
    }
    
    DiaryEntry new_entry;
    printf("Enter your diary entry: ");
    fgets(new_entry.entry, MAX_LENGTH, stdin);
    new_entry.timestamp = time(NULL); // get current time

    fprintf(file, "%s: %s", ctime(&new_entry.timestamp), new_entry.entry);
    fclose(file);

    printf("Entry added successfully!\n");
}

void view_entries() {
    char line[MAX_LENGTH + 26]; // Account for date and time format
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        printf("No entries found or error opening the diary.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    printf("\nEnd of entries.\n");
}

void clear_entries() {
    char confirm;
    printf("Are you sure you want to delete all entries? (y/n): ");
    confirm = getchar();
    flush_input_buffer();

    if (confirm == 'y' || confirm == 'Y') {
        FILE *file = fopen(DIARY_FILE, "w");
        if(file != NULL) {
            fclose(file);
            printf("All entries have been deleted!\n");
        } else {
            printf("Error clearing diary entries.\n");
        }
    } else {
        printf("No entries were deleted.\n");
    }
}

void display_menu() {
    printf("\n===== Digital Diary Menu =====\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Clear Diary Entries\n");
    printf("4. Exit\n");
}

void flush_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}