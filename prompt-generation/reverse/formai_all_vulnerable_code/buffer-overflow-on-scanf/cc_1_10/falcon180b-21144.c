//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void print_entry(int index) {
    printf("Name: %s\n", entries[index].name);
    printf("Phone number: %s\n", entries[index].number);
}

void search_entry() {
    char search_name[MAX_NAME_SIZE];

    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            print_entry(i);
        }
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");

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
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}