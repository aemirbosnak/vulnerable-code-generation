//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *key;
    int value;
} entry_t;

entry_t data[MAX_SIZE];
int num_entries = 0;

void insert(char *key, int value) {
    if (num_entries >= MAX_SIZE) {
        printf("Error: table is full\n");
        exit(1);
    }
    data[num_entries].key = strdup(key);
    data[num_entries].value = value;
    num_entries++;
}

void search(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(data[i].key, key) == 0) {
            printf("Found %s with value %d\n", data[i].key, data[i].value);
            return;
        }
    }
    printf("Not found\n");
}

void delete(char *key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(data[i].key, key) == 0) {
            free(data[i].key);
            data[i] = data[num_entries-1];
            num_entries--;
            return;
        }
    }
    printf("Not found\n");
}

int main() {
    int choice, i;
    char key[100];
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%d", &i);
                insert(key, i);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%s", key);
                search(key);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%s", key);
                delete(key);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}