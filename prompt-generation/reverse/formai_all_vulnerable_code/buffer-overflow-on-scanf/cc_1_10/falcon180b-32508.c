//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[80];
    char phone[20];
} entry_t;

void add_entry(entry_t* entries, int count, const char* name, const char* phone) {
    if (count >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(entries[count].name, name);
    strcpy(entries[count].phone, phone);

    count++;
}

void search_entry(const entry_t* entries, int count, const char* name) {
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    add_entry(entries, count, "John Doe", "555-1234");
    add_entry(entries, count, "Jane Smith", "555-5678");

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char name[80];
            char phone[20];

            printf("Enter contact name: ");
            scanf("%s", name);

            printf("Enter contact phone number: ");
            scanf("%s", phone);

            add_entry(entries, count, name, phone);
            break;
        }

        case 2: {
            char name[80];

            printf("Enter contact name to search: ");
            scanf("%s", name);

            search_entry(entries, count, name);
            break;
        }

        case 3:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}