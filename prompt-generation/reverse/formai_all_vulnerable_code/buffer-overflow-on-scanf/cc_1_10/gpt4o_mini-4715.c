//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
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

void display_menu() {
    printf("=== Digital Diary ===\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
    printf("=====================\n");
    printf("Select an option (1-5): ");
}

void get_current_date(char *date_buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date_buffer, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full! Unable to add entry.\n");
        return;
    }
    char date[DATE_LENGTH];
    get_current_date(date);
    
    printf("Enter your diary entry: ");
    getchar();  // To consume newline from previous input
    fgets(diary[entry_count].entry, ENTRY_LENGTH, stdin);
    diary[entry_count].entry[strcspn(diary[entry_count].entry, "\n")] = '\0'; // Remove newline character
    strcpy(diary[entry_count].date, date);
    entry_count++;
    
    printf("Entry added on %s!\n", date);
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }
    printf("=== Your Diary Entries ===\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n\n", diary[i].entry);
    }
    printf("===========================\n");
}

void search_entry() {
    char search_term[ENTRY_LENGTH];
    printf("Enter a term to search: ");
    getchar(); // To consume newline from previous input
    fgets(search_term, ENTRY_LENGTH, stdin);
    search_term[strcspn(search_term, "\n")] = '\0'; // Remove newline character
    
    printf("=== Search Results ===\n");
    int found = 0;
    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].entry, search_term) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n\n", diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("No entries found containing '%s'.\n", search_term);
    }
    printf("=======================\n");
}

void delete_entry() {
    if (entry_count == 0) {
        printf("No entries to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the entry to delete (1 to %d): ", entry_count);
    scanf("%d", &index);
    
    if (index < 1 || index > entry_count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index - 1; i < entry_count - 1; i++) {
        diary[i] = diary[i + 1];
    }
    entry_count--;

    printf("Entry deleted!\n");
}

int main() {
    int option;
    while (1) {
        display_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting the Digital Diary. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}