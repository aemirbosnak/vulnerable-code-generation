//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_ADDR_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDR_LEN];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Address book is full.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    char address[MAX_ADDR_LEN];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter address: ");
    scanf("%s", address);

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].address, address);

    num_entries++;
    printf("Entry added successfully.\n");
}

void search_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Address: %s\n", entries[i].address);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nSherlock Holmes' Address Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}