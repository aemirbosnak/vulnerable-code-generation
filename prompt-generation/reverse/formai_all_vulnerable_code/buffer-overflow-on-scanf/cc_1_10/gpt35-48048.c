//FormAI DATASET v1.0 Category: Digital Diary ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int month;
    int year;
    char entry[256];
} DiaryEntry;

int num_entries = 0;

DiaryEntry entries[MAX_ENTRIES];

void print_menu() {
    printf("Welcome to your Digital Diary!\n");
    printf("1. Add an entry\n");
    printf("2. View all entries\n");
    printf("3. Exit\n");
}

void add_entry() {
    if(num_entries < MAX_ENTRIES) {
        DiaryEntry entry;
        printf("Please enter the year (yyyy): ");
        scanf("%d", &entry.year);
        printf("Please enter the month (mm): ");
        scanf("%d", &entry.month);
        printf("Please enter the day (dd): ");
        scanf("%d", &entry.day);
        printf("Please enter your entry: \n");
        getchar();
        fgets(entry.entry, sizeof(entry.entry), stdin);
        entries[num_entries++] = entry;
    } else {
        printf("You have reached the maximum number of entries!\n");
    }
}

void view_entries() {
    for(int i=0; i<num_entries; i++) {
        printf("Date: %02d/%02d/%d\n", entries[i].day, entries[i].month, entries[i].year);
        printf("Entry: %s", entries[i].entry);
    }
}

int main() {
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}