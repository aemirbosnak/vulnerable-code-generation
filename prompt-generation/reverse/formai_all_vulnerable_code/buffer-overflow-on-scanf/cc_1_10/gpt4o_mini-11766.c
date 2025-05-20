//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[ENTRY_SIZE];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry();
void view_entries();
void save_diary();
void load_diary();
void display_menu();

int main() {
    load_diary();

    int choice;
    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline from buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                save_diary();
                printf("Diary saved successfully!\n");
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                save_diary();
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n=== Digital Diary ===\n");
    printf("1. Add New Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Diary\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Maximum entries reached. Can't add more!\n");
        return;
    }

    DiaryEntry new_entry;

    // Get current date
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(new_entry.date, sizeof(new_entry.date), "%Y-%m-%d", tm_info);

    printf("Enter your diary entry (max %d characters): ", ENTRY_SIZE);
    fgets(new_entry.content, ENTRY_SIZE, stdin);
    new_entry.content[strcspn(new_entry.content, "\n")] = '\0'; // Remove new line

    diary[entry_count++] = new_entry;

    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }

    printf("\n=== Diary Entries ===\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%s: %s\n", diary[i].date, diary[i].content);
    }
}

void save_diary() {
    FILE *file = fopen("diary.txt", "w+");
    if (file == NULL) {
        printf("Error saving diary.\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "%s: %s\n", diary[i].date, diary[i].content);
    }

    fclose(file);
}

void load_diary() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        return; // No diary file to load
    }

    while (fscanf(file, "%10s: %[^\n]", diary[entry_count].date, diary[entry_count].content) != EOF) {
        entry_count++;
        if (entry_count >= MAX_ENTRIES) {
            break; // Prevent overflow
        }
    }

    fclose(file);
}