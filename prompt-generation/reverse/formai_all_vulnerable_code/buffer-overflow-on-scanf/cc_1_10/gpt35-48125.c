//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int month;
    int year;
    char text[200];
} diary_entry;

void print_menu(void);
int get_choice(void);
void add_entry(diary_entry *entry, int *entry_count);
void view_entries(diary_entry *entry, int entry_count);
void search_entries(diary_entry *entry, int entry_count);
void delete_entry(diary_entry *entry, int *entry_count);

int main(void) {
    int choice;
    diary_entry entries[MAX_ENTRIES];
    int entry_count = 0;
    
    printf("Welcome to your Digital Diary!\n");
    
    do {
        print_menu();
        choice = get_choice();
        
        switch (choice) {
            case 1:
                add_entry(&entries[entry_count], &entry_count);
                break;
            case 2:
                view_entries(entries, entry_count);
                break;
            case 3:
                search_entries(entries, entry_count);
                break;
            case 4:
                delete_entry(entries, &entry_count);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}

void print_menu(void) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Quit\n");
}

int get_choice(void) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void add_entry(diary_entry *entry, int *entry_count) {
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &entry->day, &entry->month, &entry->year);
    printf("Enter your entry:\n");
    getchar();
    fgets(entry->text, 200, stdin);
    (*entry_count)++;
    printf("Entry added successfully!\n");
}

void view_entries(diary_entry *entry, int entry_count) {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    
    printf("All entries:\n");
    
    for (int i = 0; i < entry_count; i++) {
        printf("%d/%d/%d: %s\n", entry[i].day, entry[i].month, entry[i].year, entry[i].text);
    }
}

void search_entries(diary_entry *entry, int entry_count) {
    if (entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    
    char query[200];
    int found = 0;
    
    printf("Enter your search query: ");
    getchar();
    fgets(query, 200, stdin);
    
    for (int i = 0; i < entry_count; i++) {
        if (strstr(entry[i].text, query)) {
            printf("%d/%d/%d: %s\n", entry[i].day, entry[i].month, entry[i].year, entry[i].text);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No entries match that query.\n");
    }
}

void delete_entry(diary_entry *entry, int *entry_count) {
    if (*entry_count == 0) {
        printf("No entries found.\n");
        return;
    }
    
    int index_to_delete;
    printf("Enter the index of the entry to delete: ");
    scanf("%d", &index_to_delete);
    
    if (index_to_delete < 0 || index_to_delete >= *entry_count) {
        printf("Invalid index.\n");
        return;
    }
    
    for (int i = index_to_delete; i < *entry_count - 1; i++) {
        entry[i] = entry[i+1];
    }
    
    (*entry_count)--;
    
    printf("Entry deleted successfully!\n");
}