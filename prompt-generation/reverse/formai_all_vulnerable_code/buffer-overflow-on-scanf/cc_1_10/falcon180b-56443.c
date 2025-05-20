//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry entries[], int size) {
    printf("Enter name: ");
    scanf("%s", entries[size].name);

    printf("Enter phone number: ");
    scanf("%s", entries[size].phone);
}

void search_entry(struct entry entries[], int size, char name[]) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(struct entry entries[], int size, char name[]) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i + 1], (size - i - 1) * sizeof(struct entry));
            size--;
            return;
        }
    }

    printf("Entry not found.\n");
}

void display_entries(struct entry entries[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int size = 0;

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Display all entries\n5. Quit\n");
        int choice;

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= MAX_ENTRIES) {
                    printf("Phone book is full.\n");
                } else {
                    add_entry(entries, size);
                    size++;
                }
                break;

            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);

                search_entry(entries, size, name);
                break;

            case 3:
                printf("Enter name to delete: ");
                char name_to_delete[50];
                scanf("%s", name_to_delete);

                delete_entry(entries, size, name_to_delete);
                break;

            case 4:
                display_entries(entries, size);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}