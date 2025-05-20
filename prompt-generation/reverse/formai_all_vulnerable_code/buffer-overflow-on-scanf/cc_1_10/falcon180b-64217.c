//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[51];
    char phone[11];
} entry;

entry phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[51];
    char phone[11];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone, phone);

    num_entries++;
}

void view_entries() {
    printf("Phonebook:\n");
    printf("Name\tPhone\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_entry() {
    char name[51];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
        }
    }
}

void delete_entry() {
    char name[51];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            num_entries--;
            printf("Entry deleted.\n");
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Search entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                view_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}