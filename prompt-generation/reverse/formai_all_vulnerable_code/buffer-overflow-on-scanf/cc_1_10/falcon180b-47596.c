//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 50
#define MAX_DATA_LEN 500

typedef struct entry {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* key, char* data) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Database is full.\n");
        return;
    }

    strncpy(database[num_entries].key, key, MAX_KEY_LEN);
    strncpy(database[num_entries].data, data, MAX_DATA_LEN);
    num_entries++;
}

void search_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            printf("Data: %s\n", database[i].data);
            return;
        }
    }

    printf("Entry not found.\n");
}

void delete_entry(char* key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(database[i].key, key) == 0) {
            memset(&database[i], 0, sizeof(Entry));
            num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }

    printf("Entry not found.\n");
}

int main() {
    int choice;
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];

    do {
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter data: ");
            scanf("%s", data);
            add_entry(key, data);
            break;

        case 2:
            printf("Enter key: ");
            scanf("%s", key);
            search_entry(key);
            break;

        case 3:
            printf("Enter key: ");
            scanf("%s", key);
            delete_entry(key);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}