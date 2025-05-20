//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_LENGTH 256

typedef struct {
    char title[ENTRY_LENGTH];
    char description[ENTRY_LENGTH];
    char date[11];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\nDigital Diary\n");
    printf("------------------\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add entry.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", diary[num_entries].title);

    printf("Enter description: ");
    scanf("%[^\n]s", diary[num_entries].description);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", diary[num_entries].date);

    num_entries++;
}

void view_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index. Cannot view entry.\n");
        return;
    }

    printf("\nEntry %d:\n", index + 1);
    printf("Title: %s\n", diary[index].title);
    printf("Description: %s\n", diary[index].description);
    printf("Date: %s\n", diary[index].date);
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index. Cannot delete entry.\n");
        return;
    }

    int i;
    for (i = index; i < num_entries - 1; i++) {
        diary[i] = diary[i + 1];
    }

    num_entries--;
}

int main() {
    int choice;
    int index;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                view_entry(index);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                delete_entry(index);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}