//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int id;
    char name[50];
    int age;
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries >= MAX_ENTRIES) {
        printf("Database is full!\n");
        return;
    }

    Entry new_entry;

    printf("Enter ID: ");
    scanf("%d", &new_entry.id);

    printf("Enter name: ");
    scanf("%s", new_entry.name);

    printf("Enter age: ");
    scanf("%d", &new_entry.age);

    entries[num_entries++] = new_entry;

    printf("Entry added!\n");
}

void print_entry(Entry entry) {
    printf("ID: %d\n", entry.id);
    printf("Name: %s\n", entry.name);
    printf("Age: %d\n", entry.age);
}

void list_entries() {
    if (num_entries == 0) {
        printf("Database is empty!\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i+1);
        print_entry(entries[i]);
    }
}

void search_entry() {
    if (num_entries == 0) {
        printf("Database is empty!\n");
        return;
    }

    int search_id;

    printf("Enter ID to search for: ");
    scanf("%d", &search_id);

    for (int i = 0; i < num_entries; i++) {
        if (entries[i].id == search_id) {
            printf("Entry found:\n");
            print_entry(entries[i]);
            return;
        }
    }

    printf("Entry not found!\n");
}

void delete_entry() {
    if (num_entries == 0) {
        printf("Database is empty!\n");
        return;
    }

    int delete_id;

    printf("Enter ID to delete: ");
    scanf("%d", &delete_id);

    for (int i = 0; i < num_entries; i++) {
        if (entries[i].id == delete_id) {
            for (int j = i; j < num_entries-1; j++) {
                entries[j] = entries[j+1];
            }
            num_entries--;
            printf("Entry deleted!\n");
            return;
        }
    }

    printf("Entry not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add entry\n");
        printf("2. List entries\n");
        printf("3. Search entry\n");
        printf("4. Delete entry\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                list_entries();
                break;
            case 3:
                search_entry();
                break;
            case 4:
                delete_entry();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}