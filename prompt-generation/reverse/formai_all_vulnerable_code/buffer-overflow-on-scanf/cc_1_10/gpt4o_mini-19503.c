//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define DATE_LENGTH 20

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void format_date(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    strftime(buffer, DATE_LENGTH, "%Y-%m-%d %H:%M:%S", tm);
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }
    char entry[ENTRY_LENGTH];
    char date[DATE_LENGTH];

    printf("Enter your diary entry: ");
    getchar(); // Clear the newline character from input buffer
    fgets(entry, ENTRY_LENGTH, stdin);
    entry[strcspn(entry, "\n")] = '\0'; // Remove new line character

    format_date(date);

    strcpy(diary[entry_count].date, date);
    strcpy(diary[entry_count].entry, entry);
    entry_count++;

    printf("Entry added on %s\n", date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found!.\n");
        return;
    }
    
    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%d] %s: %s\n", i + 1, diary[i].date, diary[i].entry);
    }
}

void save_entries() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error saving diary entries!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s;%s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
    printf("Diary entries saved to diary.txt\n");
}

void load_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary entries found.\n");
        return;
    }

    while (fgets(diary[entry_count].date, DATE_LENGTH, file) != NULL &&
           fgets(diary[entry_count].entry, ENTRY_LENGTH, file) != NULL) {
        char *newline;

        newline = strchr(diary[entry_count].date, '\n');
        if (newline) *newline = '\0';

        newline = strchr(diary[entry_count].entry, '\n');
        if (newline) *newline = '\0';

        entry_count++;
    }
    fclose(file);
    printf("Diary entries loaded: %d found.\n", entry_count);
}

void clear_entries() {
    entry_count = 0;
    printf("All diary entries have been cleared.\n");
}

int main() {
    int choice;

    load_entries();

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Save Entries\n");
        printf("4. Clear Entries\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_entries();
                break;
            case 4:
                clear_entries();
                break;
            case 5:
                save_entries();
                printf("Exiting the Diary. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}