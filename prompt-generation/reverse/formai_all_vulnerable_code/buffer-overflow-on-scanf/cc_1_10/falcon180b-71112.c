//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_SIZE 100

typedef struct {
    char data[MAX_ENTRY_SIZE];
    int key;
} Entry;

Entry database[MAX_ENTRIES];
int num_entries = 0;

void insert_entry(char* data, int key) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Database is full.\n");
        return;
    }

    strncpy(database[num_entries].data, data, MAX_ENTRY_SIZE);
    database[num_entries].key = key;
    num_entries++;
}

void search_entry(int key) {
    for (int i = 0; i < num_entries; i++) {
        if (database[i].key == key) {
            printf("Entry found: %s\n", database[i].data);
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice, key;

    while (1) {
        printf("Cyberpunk Database System\n");
        printf("1. Insert entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%[^\n]", database[num_entries].data);
                printf("Enter key: ");
                scanf("%d", &key);
                insert_entry(database[num_entries].data, key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search_entry(key);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}