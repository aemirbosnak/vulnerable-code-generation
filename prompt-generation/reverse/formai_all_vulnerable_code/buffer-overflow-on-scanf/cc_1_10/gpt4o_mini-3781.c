//GPT-4o-mini DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 256

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    char content[MAX_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int entries_count = 0;

void get_current_date(char *date_buffer) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);
    strftime(date_buffer, 11, "%Y-%m-%d", tm_info);
}

void add_entry() {
    if (entries_count >= MAX_ENTRIES) {
        printf("Diary full! Cannot add more entries.\n");
        return;
    }

    char date[11];
    get_current_date(date);
    
    printf("Today is %s. Write your entry: ", date);
    getchar(); // clear newline from previous input
    fgets(diary[entries_count].content, MAX_LENGTH, stdin);
    
    // Remove newline character
    diary[entries_count].content[strcspn(diary[entries_count].content, "\n")] = '\0'; 

    strcpy(diary[entries_count].date, date);
    entries_count++;
    printf("Entry added!\n");
}

void view_entries() {
    if (entries_count == 0) {
        printf("You have no entries in your diary.\n");
        return;
    }

    printf("\nYour Diary Entries:\n");
    for (int i = 0; i < entries_count; i++) {
        printf("[%d] %s: %s\n", i + 1, diary[i].date, diary[i].content);
    }
}

void search_entry() {
    char search_date[11];
    printf("Enter the date to search for (YYYY-MM-DD): ");
    scanf("%10s", search_date);
    
    int found = 0;
    for (int i = 0; i < entries_count; i++) {
        if (strcmp(diary[i].date, search_date) == 0) {
            printf("Found your entry on %s: %s\n", diary[i].date, diary[i].content);
            found = 1;
        }
    }

    if (!found) {
        printf("No entries found for the date %s.\n", search_date);
    }
}

void delete_entry() {
    int entry_num;
    printf("Enter the entry number to delete: ");
    scanf("%d", &entry_num);

    if (entry_num <= 0 || entry_num > entries_count) {
        printf("Invalid entry number!\n");
        return;
    }

    // Shift entries to remove the selected one
    for (int i = entry_num - 1; i < entries_count - 1; i++) {
        diary[i] = diary[i + 1];
    }

    entries_count--;
    printf("Entry %d deleted!\n", entry_num);
}

void display_menu() {
    printf("\n~~~ Welcome to Your Magical Diary ~~~\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Search Entry by Date\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        
        printf("Choose an option: ");
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
                delete_entry();
                break;
            case 5:
                printf("Thank you for visiting your magical diary. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}