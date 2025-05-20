//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11];
    char entry[MAX_LENGTH];
} DiaryEntry;

void add_entry();
void view_entries();
void delete_entry();
void display_menu();
void clear_stdin();

int main() {
    int choice;
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_stdin();  // Clear the input buffer

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
                printf("Exiting the diary program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n*** Digital Diary Menu ***\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        perror("Could not open diary.txt");
        return;
    }

    DiaryEntry entry;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(entry.date, "%02d-%02d-%04d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);

    printf("Enter your diary entry: ");
    fgets(entry.entry, MAX_LENGTH, stdin);
    entry.entry[strcspn(entry.entry, "\n")] = 0;  // Remove newline

    fprintf(file, "%s: %s\n", entry.date, entry.entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void view_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        perror("Could not open diary.txt");
        return;
    }

    char line[MAX_LENGTH + 20]; // Extra space for date and colon
    printf("\n*** Your Diary Entries ***\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

void delete_entry() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        perror("Could not open diary.txt");
        return;
    }

    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;

    while (fgets(entries[count].date, sizeof(entries[count].date), file) && count < MAX_ENTRIES) {
        char *colon_pos = strchr(entries[count].date, ':');
        if (colon_pos != NULL) {
            strcpy(entries[count].entry, colon_pos + 2); // Skip the colon and the space
            *colon_pos = '\0'; // Null terminate the date
            count++;
        }
    }
    fclose(file);

    printf("\nEnter the date of the diary entry to delete (format DD-MM-YYYY): ");
    char date_to_delete[11];
    fgets(date_to_delete, sizeof(date_to_delete), stdin);
    date_to_delete[strcspn(date_to_delete, "\n")] = 0; // Remove newline

    file = fopen("diary.txt", "w");
    if (file == NULL) {
        perror("Could not open diary.txt");
        return;
    }

    int deleted = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(date_to_delete, entries[i].date) != 0) {
            fprintf(file, "%s: %s\n", entries[i].date, entries[i].entry);
        } else {
            deleted = 1;
        }
    }
    
    fclose(file);
    
    if (deleted) {
        printf("Entry deleted successfully!\n");
    } else {
        printf("No entry found for the given date.\n");
    }
}

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}