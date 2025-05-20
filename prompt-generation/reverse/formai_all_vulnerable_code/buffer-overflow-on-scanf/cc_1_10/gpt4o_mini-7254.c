//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char entry[MAX_LENGTH];
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry();
void view_entries();
void delete_entry();
void save_entries();
void load_entries();
void clear_stdin();

int main() {
    int choice;

    load_entries();

    while (1) {
        printf("Digital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save & Exit\n");
        printf("5. Exit without Saving\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clear_stdin();

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
                save_entries();
                return 0;
            case 5:
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry!\n");
        return;
    }
    
    printf("Enter your diary entry (max 256 chars): ");
    fgets(diary[entry_count].entry, MAX_LENGTH, stdin);
    diary[entry_count].timestamp = time(NULL);
    entry_count++;
    printf("Entry added successfully.\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d (Date: %s): %s", i + 1, ctime(&diary[i].timestamp), diary[i].entry);
    }
}

void delete_entry() {
    int index;
    printf("Enter the entry number to delete: ");
    scanf("%d", &index);
    clear_stdin();

    if (index < 1 || index > entry_count) {
        printf("Invalid entry number.\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry deleted successfully.\n");
}

void save_entries() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Could not open diary.txt for writing.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s", diary[i].entry);
        fprintf(file, "Timestamp: %s", ctime(&diary[i].timestamp));
    }
    fclose(file);
    printf("Entries saved to diary.txt.\n");
}

void load_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved entries found.\n");
        return;
    }

    while (fgets(diary[entry_count].entry, MAX_LENGTH, file) && entry_count < MAX_ENTRIES) {
        diary[entry_count].timestamp = time(NULL);
        entry_count++;
    }

    fclose(file);
    printf("Entries loaded from diary.txt.\n");
}

void clear_stdin() {
    while (getchar() != '\n');
}