//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry entries[], int *num_entries) {
    printf("Enter name: ");
    scanf("%s", entries[*num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[*num_entries].phone);
    (*num_entries)++;
}

void search_entry(struct entry entries[], int num_entries, char search_name[]) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nPhone number: %s\n", entries[i].name, entries[i].phone);
        }
    }
}

void delete_entry(struct entry entries[], int *num_entries) {
    printf("Enter name to delete: ");
    char search_name[50];
    scanf("%s", search_name);
    int i;
    for (i = 0; i < *num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(struct entry) * (*num_entries - i - 1));
            (*num_entries)--;
            break;
        }
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    while (num_entries < MAX_ENTRIES) {
        int choice;
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, &num_entries);
                break;
            case 2:
                printf("Enter name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                search_entry(entries, num_entries, search_name);
                break;
            case 3:
                delete_entry(entries, &num_entries);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}