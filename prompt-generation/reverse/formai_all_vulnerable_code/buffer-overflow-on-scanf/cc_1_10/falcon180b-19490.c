//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[20];
};

int num_entries = 0;
struct entry phone_book[MAX_ENTRIES];

void add_entry(char *name, char *phone) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Phone book is full.\n");
        return;
    }

    strcpy(phone_book[num_entries].name, name);
    strcpy(phone_book[num_entries].phone, phone);

    num_entries++;
}

void search_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phone_book[i].name, phone_book[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            memset(&phone_book[i], 0, sizeof(struct entry));
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

void print_entries() {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

int main() {
    char choice;
    char name[50];
    char phone[20];

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            scanf(" %s", name);
            printf("Enter phone: ");
            scanf(" %s", phone);
            add_entry(name, phone);
            break;

        case '2':
            printf("Enter name: ");
            scanf(" %s", name);
            search_entry(name);
            break;

        case '3':
            printf("Enter name: ");
            scanf(" %s", name);
            delete_entry(name);
            break;

        case '4':
            print_entries();
            break;

        case '5':
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}