//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10
#define ENTRY_SIZE 100

typedef struct {
    char title[50];
    char content[ENTRY_SIZE];
    char date[20];
} Entry;

Entry diary[MAX_ENTRIES];
int current_entry = 0;

void add_entry();
void view_entry();
void delete_entry();
void print_menu();

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
                view_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    printf("Enter title: ");
    scanf("%s", diary[current_entry].title);
    printf("Enter content: ");
    scanf("%[^\n]s", diary[current_entry].content);
    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", diary[current_entry].date);

    printf("Entry added successfully.\n");
    current_entry++;
}

void view_entry() {
    if (current_entry == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Title: %s\n", diary[current_entry - 1].title);
    printf("Content: %s\n", diary[current_entry - 1].content);
    printf("Date: %s\n", diary[current_entry - 1].date);
}

void delete_entry() {
    if (current_entry == 0) {
        printf("Diary is empty.\n");
        return;
    }

    diary[current_entry - 1].title[0] = '\0';
    diary[current_entry - 1].content[0] = '\0';
    diary[current_entry - 1].date[0] = '\0';

    current_entry--;

    printf("Entry deleted successfully.\n");
}

void print_menu() {
    printf("\nDigital Diary Menu\n");
    printf("1. Add Entry\n");
    printf("2. View Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}