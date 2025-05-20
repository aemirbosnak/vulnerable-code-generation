//FormAI DATASET v1.0 Category: Digital Diary ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

struct diary_entry { 
    int day;
    int month;
    int year;
    char content[500];
};

int num_entries = 0;
struct diary_entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }
    
    printf("Enter day, month, and year (format: dd/mm/yyyy): ");
    scanf("%d/%d/%d", &entries[num_entries].day, &entries[num_entries].month, &entries[num_entries].year);
    printf("Enter entry content (max 500 characters):\n");
    scanf(" %[^\n]", entries[num_entries].content);
    
    num_entries++;
}

void view_entry() {
    if (num_entries == 0) {
        printf("Diary is empty!\n");
        return;
    }
    
    printf("Enter entry number to view (1-%d): ", num_entries);
    int entry_num;
    scanf("%d", &entry_num);
    
    if (entry_num < 1 || entry_num > num_entries) {
        printf("Invalid entry number!\n");
        return;
    }
    
    printf("Entry #%d:\n", entry_num);
    printf("%02d/%02d/%04d\n", entries[entry_num-1].day, entries[entry_num-1].month, entries[entry_num-1].year);
    printf("%s\n", entries[entry_num-1].content);
}

void list_entries() {
    if (num_entries == 0) {
        printf("Diary is empty!\n");
        return;
    }
    
    printf("%-10s %-15s %-500s\n", "Date", "Time", "Content");
    for (int i = 0; i < num_entries; i++) {
        printf("%02d/%02d/%04d\n", entries[i].day, entries[i].month, entries[i].year);
        printf("%s\n", entries[i].content);
    }
}

int main() {
    printf("Welcome to your digital diary!\n");
    while (1) {
        printf("Options:\n");
        printf("1. Add Entry\n");
        printf("2. View Entry\n");
        printf("3. List Entries\n");
        printf("4. Quit\n");
        printf("Enter option: ");
        
        int option;
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entry();
                break;
            case 3:
                list_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}