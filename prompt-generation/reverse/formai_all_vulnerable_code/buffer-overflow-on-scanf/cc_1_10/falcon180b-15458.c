//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 50
#define MAX_DATA_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} Entry;

Entry database[MAX_ENTRIES];
int num_entries = 0;

void insert_entry(char* key, char* data) {
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
            memmove(&database[i], &database[i+1], (num_entries - i - 1) * sizeof(Entry));
            num_entries--;
            return;
        }
    }
    printf("Entry not found.\n");
}

int main() {
    int choice, i;
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];

    printf("Welcome to the Database Indexing System.\n\n");
    printf("1. Insert an entry\n");
    printf("2. Search for an entry\n");
    printf("3. Delete an entry\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the key: ");
            scanf("%s", key);
            printf("Enter the data: ");
            scanf("%s", data);
            insert_entry(key, data);
            break;
        case 2:
            printf("Enter the key: ");
            scanf("%s", key);
            search_entry(key);
            break;
        case 3:
            printf("Enter the key: ");
            scanf("%s", key);
            delete_entry(key);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}