//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 1024

typedef struct {
    char date[20];
    char content[ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entry_count = 0;

void display_menu() {
    printf("\n=====================\n");
    printf("     Digital Diary   \n");
    printf("=====================\n");
    printf("1. Add Entry\n");
    printf("2. View All Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("=====================\n");
}

void add_entry() {
    if (entry_count >= MAX_ENTRIES) {
        printf("Diary is full. You cannot add more entries.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(diary[entry_count].date, "%02d/%02d/%04d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);

    printf("Enter your diary entry: ");
    getchar(); // To consume newline character left by previous input
    fgets(diary[entry_count].content, ENTRY_LENGTH, stdin);

    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0; // Remove newline character
    entry_count++;

    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("No entries to display.\n");
        return;
    }

    printf("\n=====================\n");
    printf("      All Entries    \n");
    printf("=====================\n");

    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].content);
        printf("---------------------\n");
    }
}

void search_entry() {
    char search_term[100];
    printf("Enter a keyword to search for: ");
    getchar(); // To consume newline character left by previous input
    fgets(search_term, sizeof(search_term), stdin);
    search_term[strcspn(search_term, "\n")] = 0; // Remove newline character

    int found = 0;
    printf("\n=====================\n");
    printf("     Search Results   \n");
    printf("=====================\n");

    for (int i = 0; i < entry_count; i++) {
        if (strstr(diary[i].content, search_term) != NULL) {
            found = 1;
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            printf("---------------------\n");
        }
    }

    if (!found) {
        printf("No entries found with the keyword \"%s\".\n", search_term);
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting the Digital Diary. Have a great day!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please choose a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}