//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

struct entry {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
};

void add_entry(struct entry* entries, int num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter number: ");
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry(struct entry* entries, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("%s: %s\n", entries[i].name, entries[i].number);
            return;
        }
    }
    printf("No entry found for %s\n", name);
}

void delete_entry(struct entry* entries, int num_entries, char* name) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], (num_entries - i - 1) * sizeof(struct entry));
            num_entries--;
            return;
        }
    }
    printf("No entry found for %s\n", name);
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    printf("Phone book program\n");
    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_entries >= MAX_ENTRIES) {
                    printf("Maximum entries reached\n");
                } else {
                    add_entry(entries, num_entries);
                }
                break;
            case 2:
                printf("Enter name to search: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                search_entry(entries, num_entries, name);
                break;
            case 3:
                printf("Enter name to delete: ");
                char del_name[MAX_NAME_LEN];
                scanf("%s", del_name);
                delete_entry(entries, num_entries, del_name);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}