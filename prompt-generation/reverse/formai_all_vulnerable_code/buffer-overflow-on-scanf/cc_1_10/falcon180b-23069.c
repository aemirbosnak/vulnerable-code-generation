//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

struct entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);

    num_entries++;
    printf("Entry added.\n");
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    int index;
    printf("Enter index of entry to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    num_entries--;
    printf("Entry deleted.\n");
}

void search_entry() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int index = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Entry not found.\n");
    } else {
        printf("Name: %s\nPhone number: %s\n", phonebook[index].name, phonebook[index].phone);
    }
}

void print_entries() {
    if (num_entries == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Print entries\n5. Exit\n");
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
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}