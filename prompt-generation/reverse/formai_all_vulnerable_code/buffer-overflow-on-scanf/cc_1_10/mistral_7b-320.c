//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char number[20];
} Entry;

Entry phone_book[MAX_ENTRIES];
int current_entry = 0;

void add_entry() {
    if (current_entry >= MAX_ENTRIES) {
        printf("Phone book is full! Add more entries to increase its capacity.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", phone_book[current_entry].name);
    printf("Enter number: ");
    scanf("%s", phone_book[current_entry].number);
    current_entry++;
}

void search_entry() {
    char search_name[50];
    int i;

    printf("Enter name to search for: ");
    scanf("%s", search_name);

    for (i = 0; i < current_entry; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", phone_book[i].name, phone_book[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char delete_name[50];
    int i, j;

    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    for (i = 0; i < current_entry; i++) {
        if (strcmp(phone_book[i].name, delete_name) == 0) {
            for (j = i; j < current_entry - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }
            current_entry--;
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void display_entries() {
    int i;

    if (current_entry == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Current number of entries: %d\n", current_entry);
    printf("Entries:\n");

    for (i = 0; i < current_entry; i++) {
        printf("Name: %s\nNumber: %s\n", phone_book[i].name, phone_book[i].number);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Entry\n");
        printf("2. Search Entry\n");
        printf("3. Delete Entry\n");
        printf("4. Display Entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                display_entries();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}