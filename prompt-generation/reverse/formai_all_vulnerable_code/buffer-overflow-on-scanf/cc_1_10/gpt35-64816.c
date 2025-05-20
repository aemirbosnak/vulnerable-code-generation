//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 100

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} diary_entry_t;

diary_entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\nDigital Diary\n");
    printf("------------\n");
    printf("1. View entries\n");
    printf("2. Add entry\n");
    printf("3. Exit\n");
    printf("Enter option: ");
}

void view_entries() {
    printf("\nEntries\n");
    printf("-------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].date, entries[i].entry);
    }
}

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("\nDiary is full. Cannot add entry.\n");
        return;
    }

    diary_entry_t new_entry;

    printf("\nEnter date (dd/mm/yyyy): ");
    scanf("%s", new_entry.date);

    printf("Enter entry (max %d characters):\n", MAX_ENTRY_LENGTH);
    getchar();
    fgets(new_entry.entry, MAX_ENTRY_LENGTH, stdin);

    entries[num_entries] = new_entry;
    num_entries++;

    printf("\nEntry added.\n");
}

int main() {
    char option[10];

    do {
        print_menu();
        scanf("%s", option);

        switch(atoi(option)) {
            case 1:
                view_entries();
                break;
            case 2:
                add_entry();
                break;
            case 3:
                printf("\nExiting digital diary. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while(atoi(option) != 3);

    return 0;
}