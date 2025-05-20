//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 100
#define MAX_ENTRIES 1000

typedef struct {
    char key[MAX_KEY_LEN];
    int value;
} entry_t;

entry_t entries[MAX_ENTRIES];
int num_entries = 0;

void index_entry(char* key, int value) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            entries[i].value = value;
            return;
        }
    }
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Index is full.\n");
        exit(1);
    }
    strcpy(entries[num_entries].key, key);
    entries[num_entries].value = value;
    num_entries++;
}

int search_index(char* key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            return entries[i].value;
        }
    }
    return -1;
}

int main() {
    int choice;
    char key[MAX_KEY_LEN];

    while (1) {
        printf("\n");
        printf("1. Add entry\n");
        printf("2. Search entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            int value;
            scanf("%d", &value);
            index_entry(key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%s", key);
            int result = search_index(key);
            if (result == -1) {
                printf("Entry not found.\n");
            } else {
                printf("Value: %d\n", result);
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}