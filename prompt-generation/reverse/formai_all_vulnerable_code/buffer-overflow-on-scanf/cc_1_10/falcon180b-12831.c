//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    printf("Enter name: ");
    scanf("%s", phonebook[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[num_entries].phone);

    num_entries++;
}

void view_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s (%s)\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Found entry:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry() {
    char name[MAX_NAME_LEN];

    printf("Enter name of entry to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < num_entries - 1; j++) {
                memcpy(&phonebook[j], &phonebook[j + 1], sizeof(entry_t));
            }

            num_entries--;

            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;

    do {
        printf("Phone Book Menu:\n");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}