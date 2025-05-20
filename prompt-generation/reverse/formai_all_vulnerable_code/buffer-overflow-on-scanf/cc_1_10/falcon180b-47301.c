//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[51];
    char phone[21];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);

    num_entries++;
}

void search_entry() {
    char search_name[51];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void delete_entry() {
    char search_name[51];
    printf("Enter name to delete: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], sizeof(entry) * (num_entries - i - 1));
            num_entries--;
            break;
        }
    }
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
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}