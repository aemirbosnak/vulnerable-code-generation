//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256
#define DIARY_FILE "diary.txt"

typedef struct {
    char date[11];     // "YYYY-MM-DD"
    char entry[MAX_LENGTH];
} DiaryEntry;

void add_entry();
void view_entries();
void delete_entry();
void display_menu();

int main() {
    int choice;
    
    while(1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf
        
        switch(choice) {
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
                printf("Exiting the Diary Application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}

void display_menu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    FILE *file = fopen(DIARY_FILE, "a");
    if (file == NULL) {
        perror("Unable to open diary file.");
        return;
    }

    DiaryEntry entry;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entry.date, sizeof(entry.date), "%Y-%m-%d", t);
    
    printf("Enter your diary entry: ");
    fgets(entry.entry, MAX_LENGTH, stdin);
    entry.entry[strcspn(entry.entry, "\n")] = 0; // Remove newline character

    fprintf(file, "%s: %s\n", entry.date, entry.entry);
    fclose(file);
    
    printf("Entry added successfully.\n");
}

void view_entries() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        perror("Unable to open diary file.");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    char line[MAX_LENGTH + 11]; // Extra space for date
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen(DIARY_FILE, "r");
    if (file == NULL) {
        perror("Unable to open diary file.");
        return;
    }

    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    while (fgets(entries[count].entry, sizeof(entries[count].entry), file)) {
        sscanf(entries[count].entry, "%10s : %255[^\n]", entries[count].date, entries[count].entry);
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    printf("Select entry to delete (1 to %d):\n", count);
    for(int i = 0; i < count; i++) {
        printf("%d. %s: %s\n", i + 1, entries[i].date, entries[i].entry);
    }

    int delete_index;
    printf("Enter the entry number to delete: ");
    scanf("%d", &delete_index);
    getchar(); // Consume newline character

    if (delete_index < 1 || delete_index > count) {
        printf("Invalid entry number.\n");
        return;
    }

    // Remove the entry by shifting
    FILE *output = fopen(DIARY_FILE, "w");
    if (output == NULL) {
        perror("Unable to open diary file for writing.");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (i != (delete_index - 1)) { // Skip the entry to delete
            fprintf(output, "%s: %s\n", entries[i].date, entries[i].entry);
        }
    }
    fclose(output);
    printf("Entry deleted successfully.\n");
}