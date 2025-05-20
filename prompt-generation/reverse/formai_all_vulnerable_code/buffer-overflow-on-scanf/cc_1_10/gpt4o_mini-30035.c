//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

typedef struct {
    char text[MAX_LENGTH];
} DiaryEntry;

void add_entry(DiaryEntry entries[], int *entry_count) {
    if (*entry_count >= MAX_ENTRIES) {
        printf("Diary is full, cannot add more entries.\n");
        return;
    }
    
    printf("Enter your diary entry:\n");
    getchar(); // To consume the newline character
    fgets(entries[*entry_count].text, MAX_LENGTH, stdin);
    
    // Remove newline character
    size_t len = strlen(entries[*entry_count].text);
    if (len > 0 && entries[*entry_count].text[len - 1] == '\n') {
        entries[*entry_count].text[len - 1] = '\0';
    }
    
    (*entry_count)++;
    printf("Entry added successfully!\n");
}

void view_entries(DiaryEntry entries[], int entry_count) {
    if (entry_count == 0) {
        printf("No diary entries to display.\n");
        return;
    }
    
    printf("\n--- Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%d: %s\n", i + 1, entries[i].text);
    }
}

void delete_entry(DiaryEntry entries[], int *entry_count) {
    if (*entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }
    
    view_entries(entries, *entry_count);
    
    int entry_to_delete;
    printf("Enter the entry number to delete: ");
    scanf("%d", &entry_to_delete);
    
    // Validate entry number
    if (entry_to_delete < 1 || entry_to_delete > *entry_count) {
        printf("Invalid entry number.\n");
        return;
    }
    
    for (int i = entry_to_delete - 1; i < *entry_count - 1; i++) {
        entries[i] = entries[i + 1];
    }
    
    (*entry_count)--;
    printf("Entry deleted successfully!\n");
}

void save_entries(DiaryEntry entries[], int entry_count) {
    FILE *file = fopen(DIARY_FILE, "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s\n", entries[i].text);
    }
    
    fclose(file);
    printf("Entries saved successfully!\n");
}

void load_entries(DiaryEntry entries[], int *entry_count) {
    FILE *file = fopen(DIARY_FILE, "r");
    if (!file) {
        printf("Could not open file for reading. Starting with an empty diary.\n");
        return;
    }
    
    while (fgets(entries[*entry_count].text, MAX_LENGTH, file) && *entry_count < MAX_ENTRIES) {
        // Remove newline character
        size_t len = strlen(entries[*entry_count].text);
        if (len > 0 && entries[*entry_count].text[len - 1] == '\n') {
            entries[*entry_count].text[len - 1] = '\0';
        }
        (*entry_count)++;
    }
    
    fclose(file);
    printf("Entries loaded successfully!\n");
}

void print_menu() {
    printf("\n--- Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Entries\n");
    printf("5. Load Entries\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int entry_count = 0;
    int choice;

    load_entries(entries, &entry_count);

    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(entries, &entry_count);
                break;
            case 2:
                view_entries(entries, entry_count);
                break;
            case 3:
                delete_entry(entries, &entry_count);
                break;
            case 4:
                save_entries(entries, entry_count);
                break;
            case 5:
                load_entries(entries, &entry_count);
                break;
            case 6:
                printf("Exiting. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}