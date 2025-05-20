//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[30];
    char number[15];
};

void add_entry(struct entry* entries, int num_entries, char* name, char* number) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(entries[num_entries].name, name);
    strcpy(entries[num_entries].number, number);
    num_entries++;
}

void delete_entry(struct entry* entries, int num_entries, char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            strcpy(entries[i].name, "");
            strcpy(entries[i].number, "");
            num_entries--;
            return;
        }
    }

    printf("Entry not found.\n");
}

void search_entry(struct entry* entries, int num_entries, char* name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    char choice;
    char name[30];
    char number[15];

    do {
        printf("1. Add entry\n2. Delete entry\n3. Search entry\n4. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                add_entry(entries, num_entries, name, number);
                break;

            case '2':
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_entry(entries, num_entries, name);
                break;

            case '3':
                printf("Enter name to search: ");
                scanf("%s", name);
                search_entry(entries, num_entries, name);
                break;

            case '4':
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}