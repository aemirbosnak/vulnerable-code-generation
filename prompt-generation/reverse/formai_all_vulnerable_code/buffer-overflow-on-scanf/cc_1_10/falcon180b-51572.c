//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void add_entry() {
    printf("Enter name (max %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", entries[num_entries].name);
    printf("Enter number (max %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", entries[num_entries].number);
    num_entries++;
}

void search_entry() {
    printf("Enter name to search: ");
    char search_name[MAX_NAME_LEN];
    scanf("%s", search_name);
    printf("Results:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", entries[i].name, entries[i].number);
        }
    }
}

void delete_entry() {
    printf("Enter name to delete: ");
    char delete_name[MAX_NAME_LEN];
    scanf("%s", delete_name);
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].name, delete_name) == 0) {
            memmove(&entries[i], &entries[i + 1], (num_entries - i - 1) * sizeof(Entry));
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                search_entry();
                break;
            case 3:
                delete_entry();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}