//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_KEY_LEN 100

typedef struct entry {
    char key[MAX_KEY_LEN];
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

int binary_search(char* key) {
    int low = 0;
    int high = num_entries - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(entries[mid].key, key);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void insert(char* key, int value) {
    int pos = binary_search(key);
    if (pos == -1) {
        if (num_entries >= MAX_ENTRIES) {
            printf("Error: index is full\n");
            return;
        }
        strcpy(entries[num_entries].key, key);
        entries[num_entries].value = value;
        num_entries++;
    } else {
        entries[pos].value = value;
    }
}

int search(char* key) {
    int pos = binary_search(key);
    if (pos == -1) {
        return -1;
    } else {
        return entries[pos].value;
    }
}

int main() {
    int choice, value;
    char key[MAX_KEY_LEN];

    while (1) {
        printf("1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(key, value);
        } else if (choice == 2) {
            printf("Enter key: ");
            scanf("%s", key);
            value = search(key);
            if (value == -1) {
                printf("Key not found\n");
            } else {
                printf("Value: %d\n", value);
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}