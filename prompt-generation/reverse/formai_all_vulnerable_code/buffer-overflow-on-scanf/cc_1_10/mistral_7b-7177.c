//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char description[50];
    char date[20];
} Entry;

Entry diary[MAX_ENTRIES];
int current_entry = 0;

void save_entry(Entry *entry) {
    strcpy(diary[current_entry].title, entry->title);
    strcpy(diary[current_entry].description, entry->description);
    strcpy(diary[current_entry].date, __DATE__);
    current_entry++;
}

void load_entry(int index) {
    printf("\nTitle: %s\n", diary[index].title);
    printf("Description: %s\n", diary[index].description);
    printf("Date: %s\n", diary[index].date);
}

void display_menu() {
    printf("\nDigital Diary Menu:\n");
    printf("1. Add new entry\n");
    printf("2. View an entry\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");
}

int main() {
    char title[50];
    char description[50];

    Entry new_entry = {0};

    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                strcpy(new_entry.title, title);
                printf("Enter description: ");
                scanf("%s", description);
                strcpy(new_entry.description, description);
                save_entry(&new_entry);
                printf("Entry added successfully!\n");
                break;
            case 2:
                if (current_entry > 0) {
                    load_entry(current_entry - 1);
                } else {
                    printf("No entries to view.\n");
                }
                break;
            case 3:
                if (current_entry > 0) {
                    current_entry--;
                    printf("Entry deleted successfully!\n");
                } else {
                    printf("No entries to delete.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}