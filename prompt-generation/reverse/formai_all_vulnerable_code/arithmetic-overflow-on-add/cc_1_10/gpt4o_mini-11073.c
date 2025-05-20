//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 500
#define DATE_LENGTH 11

typedef struct {
    char date[DATE_LENGTH];
    char entry[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void display_menu() {
    printf("\nWelcome to the Digital Diary\n");
    printf("1. Add a New Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Cannot add more entries.\n");
        return;
    }

    printf("Enter your diary entry (max %d characters): ", ENTRY_LENGTH);
    getchar(); // Clear the newline left by previous input
    fgets(diary[entry_count].entry, ENTRY_LENGTH, stdin);
    diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = 0; // Remove newline

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(diary[entry_count].date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    entry_count++;
    printf("Diary entry added on %s.\n", diary[entry_count - 1].date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries found in your diary.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entry_count; i++) {
        printf("[%d] Date: %s\n", i + 1, diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
}

void search_entries() {
    char keyword[ENTRY_LENGTH];
    printf("Enter keyword to search in diary entries: ");
    getchar(); // Clear the newline left by previous input
    fgets(keyword, ENTRY_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // Remove newline

    int found = 0;
    printf("\nSearch Results for '%s':\n", keyword);
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].entry, keyword) != NULL) {
            printf("[%d] Date: %s\n", i + 1, diary[i].date);
            printf("Entry: %s\n\n", diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found with the keyword '%s'.\n", keyword);
    }
}

int main() {
    int option;

    while (1) {
        display_menu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input! Please enter a number between 1 and 4.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (option) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("Exiting the Digital Diary. Take care of your thoughts!\n");
                exit(0);
            default:
                printf("Invalid option! Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;
}