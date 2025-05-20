//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

typedef struct {
    time_t timestamp;
    char title[MAX_TITLE_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function to get current time as a string
char *current_time_string() {
    time_t now = time(NULL);
    return ctime(&now);
}

// Function to display all diary entries
void display_entries() {
    if (entry_count == 0) {
        printf("Your diary is empty.\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        printf("Entry %d:\n", i + 1);
        printf("Date: %s", ctime(&(diary[i].timestamp)));
        printf("Title: %s\n", diary[i].title);
        printf("Content:\n%s\n", diary[i].content);
        printf("------------------------------------\n");
    }
}

// Function to add a new entry to the diary
void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full, cannot add more entries.\n");
        return;
    }

    printf("Enter the title of your entry: ");
    fgets(diary[entry_count].title, MAX_TITLE_LENGTH, stdin);
    diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0;  // Remove newline

    printf("Write your content below (end with EOF or `Ctrl+D`):\n");
    printf("Content: ");
    fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, stdin);
    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0;  // Remove newline

    diary[entry_count].timestamp = time(NULL);
    entry_count++;

    printf("Entry added successfully!\n");
}

// Function to clear the diary
void clear_diary() {
    entry_count = 0;
    printf("All diary entries have been cleared.\n");
}

// Function to save the diary to a file
void save_diary(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to save diary");
        return;
    }
    fwrite(diary, sizeof(DiaryEntry), entry_count, file);
    fclose(file);
    printf("Diary saved to %s\n", filename);
}

// Function to load the diary from a file
void load_diary(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to load diary");
        return;
    }
    entry_count = fread(diary, sizeof(DiaryEntry), MAX_ENTRIES, file);
    fclose(file);
    printf("Diary loaded from %s\n", filename);
}

// Main menu function
void menu() {
    int choice;
    char filename[100];

    while (1) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Clear Diary\n");
        printf("4. Save Diary\n");
        printf("5. Load Diary\n");
        printf("6. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                clear_diary();
                break;
            case 4:
                printf("Enter filename to save diary: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                save_diary(filename);
                break;
            case 5:
                printf("Enter filename to load diary: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                load_diary(filename);
                break;
            case 6:
                printf("Exiting the diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}