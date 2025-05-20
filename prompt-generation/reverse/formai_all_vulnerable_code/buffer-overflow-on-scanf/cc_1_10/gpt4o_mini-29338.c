//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: modular
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
    time_t timestamp;
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

// Function prototypes
void add_entry();
void view_entries();
void delete_entry();
void save_entries();
void load_entries();
void display_menu();
void clear_screen();

int main() {
    load_entries();
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume the newline character after the choice

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
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void display_menu() {
    clear_screen();
    printf("======== Digital Diary ========\n");
    printf("1. Add Diary Entry\n");
    printf("2. View Diary Entries\n");
    printf("3. Delete Diary Entry\n");
    printf("4. Save Entries to File\n");
    printf("5. Exit\n");
    printf("==============================\n");
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    DiaryEntry entry;
    printf("Enter the title of the entry: ");
    fgets(entry.title, MAX_TITLE_LENGTH, stdin);
    entry.title[strcspn(entry.title, "\n")] = 0; // remove newline character

    printf("Write your diary entry: ");
    fgets(entry.content, MAX_CONTENT_LENGTH, stdin);
    entry.content[strcspn(entry.content, "\n")] = 0; // remove newline character

    entry.timestamp = time(NULL); // get the current timestamp

    diary[entry_count++] = entry;
    printf("Entry added successfully!\n");
    getchar(); // wait for user input before continuing
}

void view_entries() {
    clear_screen();
    if (entry_count == 0) {
        printf("No diary entries found.\n");
        getchar(); // wait for user input before continuing
        return;
    }

    printf("======= Diary Entries =======\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%d. %s\n", i + 1, diary[i].title);
        printf("   %s\n", diary[i].content);
        printf("   (%s)\n", ctime(&diary[i].timestamp));
        printf("-----------------------------\n");
    }
    getchar(); // wait for user input before continuing
}

void delete_entry() {
    view_entries();
    int index;
    printf("Enter the number of the entry to delete: ");
    scanf("%d", &index);
    getchar(); // consume the newline character

    if (index < 1 || index > entry_count) {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;
    printf("Entry deleted successfully!\n");
    getchar(); // wait for user input before continuing
}

void save_entries() {
    FILE *file = fopen("diary.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Title: %s\n", diary[i].title);
        fprintf(file, "Content: %s\n", diary[i].content);
        fprintf(file, "Timestamp: %s\n", ctime(&diary[i].timestamp));
        fprintf(file, "-----------------------------\n");
    }

    fclose(file);
    printf("Entries saved to diary.txt!\n");
    getchar(); // wait for user input before continuing
}

void load_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (!file) {
        return; // if the file doesn't exist, just return
    }

    while (fgets(diary[entry_count].title, MAX_TITLE_LENGTH, file) && entry_count < MAX_ENTRIES) {
        diary[entry_count].title[strcspn(diary[entry_count].title, "\n")] = 0; // remove newline 
        fgets(diary[entry_count].content, MAX_CONTENT_LENGTH, file);
        diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // remove newline
        diary[entry_count].timestamp = time(NULL); // set current timestamp for simplicity
        entry_count++;
        fgets(diary[entry_count].title, 2, file); // read the separator line
    }

    fclose(file);
}