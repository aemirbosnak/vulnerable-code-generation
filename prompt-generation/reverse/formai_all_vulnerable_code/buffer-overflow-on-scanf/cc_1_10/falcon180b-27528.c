//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone_number[15];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    char name[50];
    char phone_number[15];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%s", phone_number);

    strcpy(phonebook[num_entries].name, name);
    strcpy(phonebook[num_entries].phone_number, phone_number);

    num_entries++;
}

void search_entry() {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].phone_number);
        }
    }
}

void delete_entry() {
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i + 1], (num_entries - i - 1) * sizeof(entry_t));
            num_entries--;
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("Phone Book\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}