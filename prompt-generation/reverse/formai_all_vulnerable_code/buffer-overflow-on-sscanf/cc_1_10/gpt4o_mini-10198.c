//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 1024

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    DiaryEntry new_entry;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Get the current date
    snprintf(new_entry.date, sizeof(new_entry.date), "%d-%02d-%02d",
             t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    printf("Enter your diary entry (max %d characters): ", MAX_LENGTH);
    getchar(); // Clear the buffer
    fgets(new_entry.content, sizeof(new_entry.content), stdin);
    
    // Remove newline character
    size_t len = strlen(new_entry.content);
    if (len > 0 && new_entry.content[len - 1] == '\n') {
        new_entry.content[len - 1] = '\0';
    }

    diary[entry_count++] = new_entry;
    printf("Entry added successfully for the date: %s\n", new_entry.date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No diary entries found!\n");
        return;
    }
    
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].content);
    }
}

void save_entries() {
    FILE *file = fopen("diary.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < entry_count; i++) {
        fprintf(file, "Date: %s\n", diary[i].date);
        fprintf(file, "Entry: %s\n\n", diary[i].content);
    }
    
    fclose(file);
    printf("Entries saved successfully to diary.txt\n");
}

void load_entries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No previous diary found, starting a fresh diary.\n");
        return;
    }

    char line[512];
    while (fgets(line, sizeof(line), file) && entry_count < MAX_ENTRIES) {
        sscanf(line, "Date: %s", diary[entry_count].date);
        fgets(diary[entry_count].content, sizeof(diary[entry_count].content), file);
        entry_count++;
    }
    
    fclose(file);
    printf("Diary loaded with %d entries.\n", entry_count);
}

void display_menu() {
    printf("\n--- C Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Save Entries\n");
    printf("4. Load Entries\n");
    printf("5. Exit\n");
    printf("------------------------\n");
}

int main() {
    load_entries();
    int choice;
    
    while (1) {
        display_menu();
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
                load_entries();
                break;
            case 5:
                save_entries(); // Save before exit
                printf("Exiting the diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}