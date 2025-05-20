//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry* entries, int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].phone);
    printf("Entry added.\n");
}

void delete_entry(struct entry* entries, int num_entries) {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(struct entry) * (num_entries - i - 1));
            num_entries--;
            printf("Entry deleted.\n");
            break;
        }
    }
}

void search_entry(struct entry* entries, int num_entries) {
    printf("Enter name to search: ");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Phone number: %s\n", entries[i].phone);
        }
    }
}

void print_entries(struct entry* entries, int num_entries) {
    printf("Name\t\tPhone\n");
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("\nPhone Book Menu\n");
        printf("1. Add entry\n");
        printf("2. Delete entry\n");
        printf("3. Search entry\n");
        printf("4. Print all entries\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Phone book is full. Cannot add more entries.\n");
                } else {
                    add_entry(entries, num_entries);
                    num_entries++;
                }
                break;
            case 2:
                delete_entry(entries, num_entries);
                break;
            case 3:
                search_entry(entries, num_entries);
                break;
            case 4:
                print_entries(entries, num_entries);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}