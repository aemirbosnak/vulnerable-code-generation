//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 50
#define MAX_CONTENT_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    time_t created_time;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries!\n");
        return;
    }

    DiaryEntry new_entry;

    printf("Enter the title of your diary entry: ");
    getchar(); // clear newline character from buffer
    fgets(new_entry.title, MAX_TITLE_LENGTH, stdin);
    new_entry.title[strcspn(new_entry.title, "\n")] = 0; // remove newline

    printf("Write your entry:\n");
    fgets(new_entry.content, MAX_CONTENT_LENGTH, stdin);
    new_entry.content[strcspn(new_entry.content, "\n")] = 0; // remove newline

    new_entry.created_time = time(NULL);
    diary[entry_count++] = new_entry;

    printf("Your entry has been added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d: %s\n", i + 1, diary[i].title);
        printf("%s - %s", diary[i].content, ctime(&diary[i].created_time));
        printf("\n");
    }
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }

    int entry_number;
    printf("Enter entry number to delete (1 to %d): ", entry_count);
    scanf("%d", &entry_number);

    if (entry_number < 1 || entry_number > entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = entry_number - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry %d has been deleted.\n", entry_number);
}

void save_diary() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Could not open diary.txt for writing.\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content: %s\n", diary[i].content);
        fprintf(file, "Date: %s\n", ctime(&diary[i].created_time));
    }
    
    fclose(file);
    printf("Diary saved to diary.txt\n");
}

void load_diary() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        printf("Could not open diary.txt for reading. It may be empty.\n");
        return;
    }
    
    while (!feof(file) && entry_count < MAX_ENTRIES) {
        DiaryEntry entry;
        char buffer[1024];
        
        fgets(buffer, 1024, file);
        sscanf(buffer, "Title: %[^\n]\n", entry.title);
        
        fgets(buffer, 1024, file);
        sscanf(buffer, "Content: %[^\n]\n", entry.content);
        
        fgets(buffer, 1024, file);
        struct tm tm;
        strptime(buffer + 6, "%a %b %d %H:%M:%S %Y\n", &tm);
        entry.created_time = mktime(&tm);
        
        diary[entry_count++] = entry;
    }

    fclose(file);
    printf("Diary loaded from diary.txt\n");
}

int main() {
    int choice;
    load_diary();

    do {
        printf("\n=== Digital Diary ===\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Delete Entry\n");
        printf("4. Save Diary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                save_diary();
                break;
            case 5:
                printf("Exiting the diary application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}