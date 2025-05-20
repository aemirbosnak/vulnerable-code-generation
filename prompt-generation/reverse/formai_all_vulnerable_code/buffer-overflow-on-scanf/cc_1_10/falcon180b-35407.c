//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char name[50];
    char phone[15];
} entry_t;

void add_entry(entry_t entries[], int count) {
    printf("Enter name: ");
    scanf("%s", entries[count].name);

    printf("Enter phone number: ");
    scanf("%s", entries[count].phone);

    count++;
}

void search_entry(entry_t entries[], int count, char* name) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(entry_t entries[], int count) {
    int i;
    printf("Enter name to delete: ");
    scanf("%s", entries[count - 1].name);

    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, entries[count - 1].name) == 0) {
            memmove(&entries[i], &entries[i + 1], (count - i - 1) * sizeof(entry_t));
            count--;
            break;
        }
    }
}

int main() {
    entry_t entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        int choice;
        printf("\nPhone Book\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, count);
            break;
        case 2:
            printf("Enter name to search: ");
            char name[50];
            scanf("%s", name);
            search_entry(entries, count, name);
            break;
        case 3:
            delete_entry(entries, count);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}