//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

struct entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

void add_entry(struct entry* entries, int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry(struct entry* entries, int num_entries) {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\n", entries[i].name);
            printf("Phone number: %s\n", entries[i].number);
        }
    }
}

void delete_entry(struct entry* entries, int num_entries) {
    printf("Enter name to delete: ");
    scanf("%s", entries[num_entries].name);
    strcpy(entries[num_entries].name, "");
    strcpy(entries[num_entries].number, "");
    num_entries--;
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        int choice;
        printf("\n1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_entry(entries, num_entries);
            break;
        case 2:
            search_entry(entries, num_entries);
            break;
        case 3:
            delete_entry(entries, num_entries);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}