//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000

typedef struct entry {
    char name[51];
    char phone[21];
} Entry;

Entry phonebook[MAX_ENTRIES] = {{"", ""}};
int num_entries = 0;

void add_entry() {
    printf("Enter name (up to 50 characters): ");
    scanf("%50s", phonebook[num_entries].name);

    printf("Enter phone number (up to 20 characters): ");
    scanf("%20s", phonebook[num_entries].phone);

    num_entries++;
}

void search_entry() {
    char search_name[51] = {0};
    printf("Enter name to search: ");
    scanf("%50s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void delete_entry() {
    char search_name[51] = {0};
    printf("Enter name to delete: ");
    scanf("%50s", search_name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], sizeof(Entry) * (num_entries - i - 1));
            num_entries--;
            printf("Entry deleted.\n");
            break;
        }
    }
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Name: %s\nPhone number: %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("\nPhone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. View all entries\n");
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
                view_entries();
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