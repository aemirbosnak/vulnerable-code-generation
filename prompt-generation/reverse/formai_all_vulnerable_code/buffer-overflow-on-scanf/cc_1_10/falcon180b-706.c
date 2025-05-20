//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char phone[15];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].phone);

    num_entries++;
}

void display_entries() {
    printf("Name\tPhone Number\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].phone);
    }
}

void search_entry() {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    bool found = false;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", entries[i].name, entries[i].phone);
            found = true;
        }
    }

    if (!found) {
        printf("No entry found.\n");
    }
}

int main() {
    printf("Phone Book\n");
    while (true) {
        printf("\n1. Add entry\n2. Display entries\n3. Search entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}