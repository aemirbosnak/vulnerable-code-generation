//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 256
#define FILENAME "diary_entries.txt"

typedef struct {
    char date[11];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int currentEntryCount = 0;

void log_error(const char *msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(EXIT_FAILURE);
}

void get_current_date(char *buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 11, "%Y-%m-%d", tm_info);
}

void load_diary() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No diary found. A new one will be created.\n");
        return;
    }
    
    while (fscanf(file, "%10s %[^\n]\n", diary[currentEntryCount].date, diary[currentEntryCount].entry) != EOF) {
        currentEntryCount++;
        if (currentEntryCount >= MAX_ENTRIES) {
            printf("Warning: Diary is full, some entries may not be loaded!\n");
            break;
        }
    }
    fclose(file);
}

void save_diary() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        log_error("Could not save diary. Check permissions.");
    }

    for (int i = 0; i < currentEntryCount; i++) {
        fprintf(file, "%s %s\n", diary[i].date, diary[i].entry);
    }
    fclose(file);
}

void add_entry() {
    if (currentEntryCount >= MAX_ENTRIES) {
        printf("Diary is full! Can't add more entries.\n");
        return;
    }
    
    char date[11];
    get_current_date(date);
    
    printf("Please write your entry (max %d characters): ", ENTRY_LENGTH - 1);
    getchar(); // To consume the remaining newline character
    if (fgets(diary[currentEntryCount].entry, ENTRY_LENGTH, stdin) == NULL) {
        log_error("Error reading entry.");
    }
    
    diary[currentEntryCount].entry[strcspn(diary[currentEntryCount].entry, "\n")] = 0; // Remove newline
    strcpy(diary[currentEntryCount].date, date);
    currentEntryCount++;
    printf("Entry added on %s.\n", date);
}

void display_entry(int index) {
    printf("Date: %s\nEntry: %s\n", diary[index].date, diary[index].entry);
}

void display_all_entries() {
    if (currentEntryCount == 0) {
        printf("Your diary is empty. Beware of the void!\n");
        return;
    }
    
    for (int i = 0; i < currentEntryCount; i++) {
        printf("Entry %d:\n", i + 1);
        display_entry(i);
    }
}

void paranoid_warning() {
    printf("Warning: Ensure that no one has accessed your diary without your knowledge!\n");
}

int main() {
    // Load existing diary entries
    load_diary();
    paranoid_warning();

    int choice;
    while (1) {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add Entry\n");
        printf("2. View All Entries\n");
        printf("3. Save and Exit\n");
        printf("4. Exit Without Saving\n");
        printf("Your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            log_error("Invalid input. Exiting.");
        }

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_all_entries();
                break;
            case 3:
                save_diary();
                printf("Diary saved. You may exit now.\n");
                return 0;
            case 4:
                printf("Exiting without saving... See you in the shadows!\n");
                return 0;
            default:
                printf("Invalid choice. Are you being watched?\n");
                break;
        }
    }

    return 0;
}