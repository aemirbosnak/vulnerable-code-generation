//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_NUM_LEN 15
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries;

void add_entry() {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);

    num_entries++;
}

void search_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Number: %s\n\n", entries[i].number);
        }
    }
}

void delete_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
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

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");

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
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}