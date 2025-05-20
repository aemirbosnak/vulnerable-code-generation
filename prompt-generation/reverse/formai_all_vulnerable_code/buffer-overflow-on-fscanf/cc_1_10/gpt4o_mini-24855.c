//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256

typedef struct {
    char date[11];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    sprintf(diary[entry_count].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    printf("Enter your diary entry for %s: ", diary[entry_count].date);
    getchar(); // Consume newline left over
    fgets(diary[entry_count].entry, ENTRY_LENGTH, stdin);
    
    // Remove newline character from entry
    diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0;
    
    entry_count++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No diary entries available.\n");
        return;
    }
    
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%d] %s: %s\n", i + 1, diary[i].date, diary[i].entry);
    }
    printf("--------------------------\n");
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No diary entries available to delete.\n");
        return;
    }

    view_entries();
    int entry_number;
    printf("Enter the entry number to delete: ");
    scanf("%d", &entry_number);

    if (entry_number < 1 || entry_number > entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    // Shift entries back to fill the deleted entry
    for (int i = entry_number - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry deleted successfully!\n");
}

void save_entries() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s\n%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Entries saved to diary.txt successfully!\n");
}

void load_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("No saved diary entries found.\n");
        return;
    }
    
    while (fscanf(file, "%10s\n%255[^\n]\n", diary[entry_count].date, diary[entry_count].entry) == 2) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) {
            printf("Loaded maximum diary entries!\n");
            break;
        }
    }
    fclose(file);
    printf("Entries loaded successfully!\n");
}

void display_menu() {
    printf("\n--- Digital Diary Menu ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Save Entries\n");
    printf("5. Load Entries\n");
    printf("6. Exit\n");
    printf("--------------------------\n");
}

int main() {
    int choice;
    
    load_entries();
    
    do {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
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
                break;
            case 5:
                load_entries();
                break;
            case 6:
                printf("Exiting the diary... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}