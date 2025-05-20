//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[51];
    char phone[16];
} entry;

int num_entries = 0;
entry phonebook[MAX_ENTRIES];

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);

    num_entries++;
}

void delete_entry() {
    int index;

    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < num_entries) {
        num_entries--;

        for (int i = index; i < num_entries; i++) {
            strcpy(phonebook[i].name, phonebook[i + 1].name);
            strcpy(phonebook[i].phone, phonebook[i + 1].phone);
        }
    }
}

void search_entry() {
    char name[51];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhonebook\n");
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry();
            break;
        case 2:
            delete_entry();
            break;
        case 3:
            search_entry();
            break;
        case 4:
            print_entries();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}