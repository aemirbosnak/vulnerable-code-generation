//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_NUMBER_LEN 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries;

void add_entry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LEN);
    scanf("%s", entries[num_entries].name);

    printf("Enter number (up to %d characters): ", MAX_NUMBER_LEN);
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void search_entry() {
    char search_name[MAX_NAME_LEN];

    printf("Enter name to search for: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n", entries[i].number);
        }
    }
}

void delete_entry() {
    char search_name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                strcpy(entries[j].name, entries[j + 1].name);
                strcpy(entries[j].number, entries[j + 1].number);
            }
            num_entries--;
            break;
        }
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");

    while (true) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Quit\n");

        int choice;
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
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}