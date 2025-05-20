//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[20];
};

int num_entries = 0;
struct entry phonebook[MAX_ENTRIES];

void add_entry() {
    printf("Enter the name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter the phone number: ");
    scanf("%s", phonebook[num_entries].phone);

    num_entries++;
}

void search_entry() {
    char name[50];

    printf("Enter the name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char name[50];

    printf("Enter the name to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], sizeof(struct entry) * (num_entries - i - 1));
            num_entries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

void print_entries() {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add an entry\n");
        printf("2. Search for an entry\n");
        printf("3. Delete an entry\n");
        printf("4. Print all entries\n");
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
            print_entries();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}