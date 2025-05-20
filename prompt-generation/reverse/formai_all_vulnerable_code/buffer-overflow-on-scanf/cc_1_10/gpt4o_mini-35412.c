//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIARY_SIZE 100
#define ENTRY_SIZE 512

struct DiaryEntry {
    char date[11]; // Format: YYYY-MM-DD
    char content[ENTRY_SIZE];
};

int entry_count = 0;
struct DiaryEntry diary[DIARY_SIZE];

void add_entry() {
    if (entry_count >= DIARY_SIZE) {
        printf("Diary full! Can't add more entries.\n");
        return;
    }

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%10s", diary[entry_count].date);
    getchar(); // To clear the newline character from the buffer

    printf("Enter your diary entry:\n");
    fgets(diary[entry_count].content, ENTRY_SIZE, stdin);
    
    // Remove newline character from the content
    diary[entry_count].content[strcspn(diary[entry_count].content, "\n")] = 0;  
    
    entry_count++;
    printf("Entry added successfully!\n");
}

void view_entries() {
    if (entry_count == 0) {
        printf("Your diary is empty! No entries to show.\n");
        return;
    }
    
    printf("\n--- Your Diary Entries ---\n");
    for (int i = 0; i < entry_count; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Entry: %s\n", diary[i].content);
        printf("-------------------------\n");
    }
}

void search_entry() {
    char search_date[11];
    printf("Enter date to search (YYYY-MM-DD): ");
    scanf("%10s", search_date);
    
    int found = 0;
    printf("\n--- Search Results for %s ---\n", search_date);
    for (int i = 0; i < entry_count; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("Date: %s\n", diary[i].date);
            printf("Entry: %s\n", diary[i].content);
            printf("-------------------------\n");
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries found for the date %s.\n", search_date);
    }
}

void display_menu() {
    printf("\n--- Welcome to Your Digital Diary ---\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    while (1) {
        display_menu();
        scanf("%d", &option);
        getchar(); // To clear the newline character from the buffer

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
                printf("Thank you for using the Digital Diary! Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    }
    
    return 0;
}