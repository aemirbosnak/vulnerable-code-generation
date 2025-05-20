//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_NUM_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry(void) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phonebook is full. Cannot add more entries.\n");
        return;
    }

    printf("Enter name: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    printf("Enter phone number: ");
    char phone[MAX_NUM_LEN];
    scanf("%s", phone);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);

    num_entries++;

    printf("Entry added successfully.\n");
}

void search_entry(void) {
    printf("Enter name to search: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
            break;
        }
    }
}

void delete_entry(void) {
    printf("Enter name to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");

            printf("Entry deleted successfully.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main(void) {
    char choice;

    do {
        printf("\nPhonebook\n");
        printf("------------------------\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            add_entry();
            break;
        case '2':
            search_entry();
            break;
        case '3':
            delete_entry();
            break;
        case '4':
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice!= '4');

    return 0;
}