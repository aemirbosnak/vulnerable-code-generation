//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    time_t timestamp;
    char entry[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    printf("Enter your diary entry:\n");
    getchar(); // To consume the newline left by previous input
    fgets(diary[entry_count].entry, MAX_LENGTH, stdin);
    diary[entry_count].timestamp = time(NULL);
    entry_count++;
    printf("Entry added successfully!\n");
}

void list_entries() {
    if (entry_count == 0) {
        printf("No entries in the diary yet.\n");
        return;
    }
    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        struct tm *tm_info = localtime(&diary[i].timestamp);
        char buffer[26];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        printf("[%d] %s - %s", i + 1, buffer, diary[i].entry);
    }
}

void delete_entry() {
    int index;
    list_entries();
    printf("Enter the index of the entry to delete:\n");
    scanf("%d", &index);
    if (index < 1 || index > entry_count) {
        printf("Invalid index! Please try again.\n");
        return;
    }
    // Shift entries to delete the selected one
    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry deleted successfully!\n");
}

void save_diary() {
    FILE *file = fopen("diary_entries.txt", "w");
    if (!file) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < entry_count; i++) {
        struct tm *tm_info = localtime(&diary[i].timestamp);
        char buffer[26];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
        fprintf(file, "[%s] %s", buffer, diary[i].entry);
    }
    fclose(file);
    printf("Diary entries saved successfully!\n");
}

void load_diary() {
    FILE *file = fopen("diary_entries.txt", "r");
    if (!file) {
        printf("No saved diary found.\n");
        return;
    }
    while (fgets(diary[entry_count].entry, MAX_LENGTH, file) && entry_count < MAX_ENTRIES) {
        diary[entry_count].timestamp = time(NULL);  // Timestamp for new entries
        entry_count++;
    }
    fclose(file);
    printf("Diary entries loaded successfully!\n");
}

void display_menu() {
    printf("\n--- Cryptic Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. List Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Diary\n");
    printf("5. Load Diary\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    load_diary();
    do {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                list_entries();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                save_diary();
                break;
            case 5:
                load_diary();
                break;
            case 6:
                printf("Exiting The Cryptic Diary...\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}