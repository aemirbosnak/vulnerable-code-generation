//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[51];
    char number[16];
} entry;

void add_entry(entry entries[], int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);

    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);

    num_entries++;
}

void search_entry(entry entries[], int num_entries, char name[]) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(entry entries[], int num_entries, char name[]) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(entry) * (num_entries - i - 1));
            num_entries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    entry phonebook[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_entries >= MAX_ENTRIES) {
                printf("Phone book is full.\n");
            } else {
                add_entry(phonebook, num_entries);
                num_entries++;
            }
            break;

        case 2:
            printf("Enter name to search: ");
            char name[51];
            scanf("%s", name);

            search_entry(phonebook, num_entries, name);
            break;

        case 3:
            printf("Enter name to delete: ");
            char del_name[51];
            scanf("%s", del_name);

            delete_entry(phonebook, num_entries, del_name);
            break;

        case 4:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}