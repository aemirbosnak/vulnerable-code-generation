//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: medieval
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
    time_t date_created;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function to add a new entry to the diary
void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Verily, thou hast reached the limit of entries! Cannot add more.\n");
        return;
    }
    
    DiaryEntry new_entry;
    printf("Enter the title of thy entry: ");
    getchar();  // To consume the newline character left by previous input
    fgets(new_entry.title, MAX_TITLE_LENGTH, stdin);
    new_entry.title[strcspn(new_entry.title, "\n")] = 0; // Remove newline character

    printf("Write thy thoughts, brave soul:\n");
    fgets(new_entry.content, MAX_CONTENT_LENGTH, stdin);
    new_entry.content[strcspn(new_entry.content, "\n")] = 0; // Remove newline character
    
    new_entry.date_created = time(NULL);
    diary[entry_count] = new_entry;
    entry_count++;

    printf("Thou hast successfully added a new entry!\n");
}

// Function to display all entries
void display_entries() {
    if (entry_count == 0) {
        printf("Alas! There are no entries in thy diary.\n");
        return;
    }
    printf("Thy Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Title: %s\n", diary[i].title);
        printf("Content: %s\n", diary[i].content);
        printf("Date Created: %s", ctime(&diary[i].date_created));
        printf("----------------------------------------\n");
    }
}

// Function to save entries to a file
void save_entries() {
    FILE *file = fopen("medieval_diary.txt", "w");
    if (!file) {
        printf("Alas! The file could not be opened for writing.\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Entry %d:\n", i + 1);
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content: %s\n", diary[i].content);
        fprintf(file, "Date Created: %s", ctime(&diary[i].date_created));
        fprintf(file, "----------------------------------------\n");
    }

    fclose(file);
    printf("Thy entries have been inscribed upon the parchment! Saved in 'medieval_diary.txt'.\n");
}

// Function to load entries from a file
void load_entries() {
    FILE *file = fopen("medieval_diary.txt", "r");
    if (!file) {
        printf("Verily, there are no previous entries to be found upon the parchment.\n");
        return;
    }

    while (!feof(file)) {
        DiaryEntry new_entry;
        if (fgets(new_entry.title, MAX_TITLE_LENGTH, file) == NULL) break;
        new_entry.title[strcspn(new_entry.title, "\n")] = 0; // Remove newline character

        if (fgets(new_entry.content, MAX_CONTENT_LENGTH, file) == NULL) break;
        new_entry.content[strcspn(new_entry.content, "\n")] = 0; // Remove newline character

        char date_line[100];
        if (fgets(date_line, sizeof(date_line), file) == NULL) break;
        new_entry.date_created = time(NULL); // Assign current time (not actual due to file format)

        diary[entry_count] = new_entry;
        entry_count++;
    }

    fclose(file);
    printf("Thy previous entries have been recovered from the parchment.\n");
}

// Main function with which the adventurer shall interact
int main() {
    int choice;
    do {
        printf("\n=== Medieval Diary ===\n");
        printf("1. Add New Entry\n");
        printf("2. Display Entries\n");
        printf("3. Save Entries\n");
        printf("4. Load Entries\n");
        printf("5. Exit\n");
        printf("Choose thy quest (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                save_entries();
                break;
            case 4:
                load_entries();
                break;
            case 5:
                printf("Fare thee well, noble scribe!\n");
                break;
            default:
                printf("Pray, choose a valid quest!\n");
        }
    } while (choice != 5);

    return 0;
}