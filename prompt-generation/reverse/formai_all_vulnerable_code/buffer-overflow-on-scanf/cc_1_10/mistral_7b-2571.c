//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_SIZE 256

typedef struct {
    char title[100];
    char description[150];
    time_t timestamp;
} Entry;

Entry diary[MAX_ENTRIES];
int current_entry = 0;

void print_menu() {
    printf("\n---- Digital Diary ----\n");
    printf("1. Add Entry\n");
    printf("2. View Entries\n");
    printf("3. Edit Entry\n");
    printf("4. Delete Entry\n");
    printf("5. Exit\n");
}

void add_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Diary is full, cannot add entry.\n");
        return;
    }

    printf("\nEnter Title: ");
    fgets(diary[current_entry].title, sizeof(diary[current_entry].title), stdin);
    diary[current_entry].title[strcspn(diary[current_entry].title, "\n")] = '\0';

    printf("Enter Description: ");
    fgets(diary[current_entry].description, sizeof(diary[current_entry].description), stdin);
    diary[current_entry].description[strcspn(diary[current_entry].description, "\n")] = '\0';

    diary[current_entry].timestamp = time(NULL);
    current_entry++;

    printf("\nEntry added successfully.\n");
}

void view_entries() {
    if (current_entry == 0) {
        printf("No entries in the diary.\n");
        return;
    }

    printf("\n----- Entries -----\n");
    for (int i = 0; i < current_entry; i++) {
        printf("\nEntry %d\n", i+1);
        printf("Title: %s\n", diary[i].title);
        printf("Description: %s\n", diary[i].description);
        printf("Timestamp: %s", ctime(&diary[i].timestamp));
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                // To be implemented
                break;
            case 4:
                // To be implemented
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}