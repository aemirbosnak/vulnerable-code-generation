//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[51];
    char phone[16];
};

int count = 0;
struct entry phonebook[MAX_ENTRIES];

void add_entry() {
    if (count == MAX_ENTRIES) {
        printf("Phonebook is full.\n");
        return;
    }

    char name[51];
    char phone[16];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(phonebook[count].name, name);
    strcpy(phonebook[count].phone, phone);

    count++;
    printf("Entry added successfully.\n");
}

void search_entry() {
    char name[51];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char name[51];

    printf("Enter name to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}