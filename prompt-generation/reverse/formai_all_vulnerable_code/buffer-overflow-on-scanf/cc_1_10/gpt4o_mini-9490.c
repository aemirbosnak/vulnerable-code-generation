//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 500
#define FILE_NAME "diary.txt"

typedef struct {
    int id;
    char date[15];
    char content[MAX_LENGTH];
} DiaryEntry;

void add_entry();
void view_entries();
void update_entry();
void delete_entry();
void display_menu();
void load_entries(DiaryEntry[], int*);
void save_entries(DiaryEntry[], int);
void clear_buffer();

int main() {
    char choice;

    while (1) {
        display_menu();
        choice = getchar();
        clear_buffer();

        switch (choice) {
            case '1': add_entry(); break;
            case '2': view_entries(); break;
            case '3': update_entry(); break;
            case '4': delete_entry(); break;
            case '5': exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n----- Digital Diary -----\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Update Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_entry() {
    DiaryEntry entry;
    FILE *file = fopen(FILE_NAME, "a");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", entry.date);
    clear_buffer();
    
    printf("Enter your diary content: ");
    fgets(entry.content, MAX_LENGTH, stdin);
    entry.id = (rand() % 1000); // Random ID, could be improved
    fprintf(file, "%d|%s|%s", entry.id, entry.date, entry.content);
    fclose(file);
    printf("Diary entry added successfully.\n");
}

void view_entries() {
    FILE *file = fopen(FILE_NAME, "r");
    DiaryEntry entry;

    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\n--- Diary Entries ---\n");
    while (fscanf(file, "%d|%[^|]|%[^\n]\n", &entry.id, entry.date, entry.content) != EOF) {
        printf("ID: %d\nDate: %s\nContent: %s\n", entry.id, entry.date, entry.content);
        printf("-------------------------\n");
    }
    fclose(file);
}

void update_entry() {
    int id;
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;
    load_entries(entries, &count);

    printf("Enter the ID of the entry you wish to update: ");
    scanf("%d", &id);
    clear_buffer();

    for (int i = 0; i < count; i++) {
        if (entries[i].id == id) {
            printf("Current Content: %s", entries[i].content);
            printf("Enter new content: ");
            fgets(entries[i].content, MAX_LENGTH, stdin);
            printf("Entry updated successfully.\n");
            save_entries(entries, count);
            return;
        }
    }
    printf("Entry with ID %d not found.\n", id);
}

void delete_entry() {
    int id;
    DiaryEntry entries[MAX_ENTRIES];
    int count = 0;
    load_entries(entries, &count);

    printf("Enter the ID of the entry you wish to delete: ");
    scanf("%d", &id);
    clear_buffer();

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (entries[i].id == id) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            count--;
            printf("Entry deleted successfully.\n");
            save_entries(entries, count);
            break;
        }
    }
    if (!found) {
        printf("Entry with ID %d not found.\n", id);
    }
}

void load_entries(DiaryEntry entries[], int *count) {
    FILE *file = fopen(FILE_NAME, "r");
    *count = 0;

    if (!file) {
        *count = 0;
        return;
    }

    while (fscanf(file, "%d|%[^|]|%[^\n]\n", &entries[*count].id, entries[*count].date, entries[*count].content) != EOF) {
        (*count)++;
        if (*count >= MAX_ENTRIES) {
            break;
        }
    }
    fclose(file);
}

void save_entries(DiaryEntry entries[], int count) {
    FILE *file = fopen(FILE_NAME, "w");

    if (!file) {
        perror("Unable to open file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d|%s|%s", entries[i].id, entries[i].date, entries[i].content);
    }
    fclose(file);
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer
}