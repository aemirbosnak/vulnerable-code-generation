//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void menu() {
    printf("\nPhone Book Menu:\n");
    printf("1. Add an entry\n");
    printf("2. Search for an entry\n");
    printf("3. Display all entries\n");
    printf("4. Exit\n");
}

void add_entry() {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    printf("\nEnter name: ");
    scanf("%s", name);
    strcpy(entries[num_entries].name, name);

    printf("Enter phone number: ");
    scanf("%s", number);
    strcpy(entries[num_entries].number, number);

    num_entries++;

    printf("\nEntry added successfully.\n");
}

void search_entry() {
    char name[MAX_NAME_LEN];

    printf("\nEnter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("\nName: %s\nPhone Number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("\nEntry not found.\n");
}

void display_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("\nName: %s\nPhone Number: %s\n", entries[i].name, entries[i].number);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];

    menu();

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            printf("\nEnter name to search: ");
            scanf("%s", name);
            search_entry();
            break;
        case 3:
            display_entries();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}