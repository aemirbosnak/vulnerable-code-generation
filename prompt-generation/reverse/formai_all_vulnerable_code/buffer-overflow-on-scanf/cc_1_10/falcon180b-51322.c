//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[32];
    char phone[16];
};

struct entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);
    num_entries++;
}

void search_entry() {
    char search_name[32];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    bool found = false;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
            found = true;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void delete_entry() {
    char delete_name[32];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);
    bool found = false;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, delete_name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], (num_entries-i-1)*sizeof(struct entry));
            num_entries--;
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

int main() {
    printf("Phone Book\n");
    while (true) {
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
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
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}