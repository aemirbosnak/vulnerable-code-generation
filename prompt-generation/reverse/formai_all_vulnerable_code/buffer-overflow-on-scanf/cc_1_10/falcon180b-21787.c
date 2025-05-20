//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *name, char *phone) {
    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].phone, phone);
    num_entries++;
}

void display_entries() {
    printf("Phone Book Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
    }
}

void search_entry(char *name) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    char name[50];
    char phone[15];

    printf("Welcome to the Phone Book!\n");

    while (1) {
        printf("\nEnter 1 to add an entry.\nEnter 2 to search for an entry.\nEnter 0 to exit.\n");
        scanf("%d", &num_entries);

        if (num_entries == 0) {
            break;
        }

        if (num_entries == 1) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter phone number: ");
            scanf("%s", phone);
            add_entry(name, phone);
        } else if (num_entries == 2) {
            printf("Enter name to search for: ");
            scanf("%s", name);
            search_entry(name);
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}