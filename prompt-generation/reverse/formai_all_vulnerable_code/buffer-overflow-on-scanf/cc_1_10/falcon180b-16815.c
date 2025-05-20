//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[50];
    char phone[15];
};

void add_entry(struct entry* entries, int* count) {
    printf("Enter name: ");
    scanf("%s", entries[*count].name);
    printf("Enter phone number: ");
    scanf("%s", entries[*count].phone);
    (*count)++;
}

void search_entry(struct entry* entries, int count, char* name) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
            return;
        }
    }
    printf("Entry not found.\n");
}

void delete_entry(struct entry* entries, int* count) {
    printf("Enter name to delete: ");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(entries[i].name, name) == 0) {
            memmove(&entries[i], &entries[i+1], sizeof(struct entry) * (*count - i - 1));
            (*count)--;
            return;
        }
    }
    printf("Entry not found.\n");
}

void print_entries(struct entry* entries, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n", entries[i].name, entries[i].phone);
    }
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int count = 0;

    while (count < MAX_ENTRIES) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(entries, &count);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                search_entry(entries, count, name);
                break;
            case 3:
                delete_entry(entries, &count);
                break;
            case 4:
                print_entries(entries, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}