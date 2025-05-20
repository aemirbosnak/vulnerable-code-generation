//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    int value;
} KeyValue;

int hash(int key) {
    return key % MAX_SIZE;
}

void insert(KeyValue* table, int key, int value) {
    int index = hash(key);
    KeyValue* pair = table + index;

    while (pair->key!= -1) {
        if (pair->key == key) {
            pair->value = value;
            return;
        }
        pair++;
    }

    pair->key = key;
    pair->value = value;
}

int search(KeyValue* table, int key) {
    int index = hash(key);
    KeyValue* pair = table + index;

    while (pair->key!= -1) {
        if (pair->key == key) {
            return pair->value;
        }
        pair++;
    }

    return -1;
}

int main() {
    KeyValue* table = (KeyValue*) malloc(MAX_SIZE * sizeof(KeyValue));

    for (int i = 0; i < MAX_SIZE; i++) {
        table[i].key = -1;
    }

    int choice, key, value;

    do {
        printf("Enter your choice:\n");
        printf("1. Insert\n2. Search\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key:\n");
                scanf("%d", &key);
                printf("Enter value:\n");
                scanf("%d", &value);
                insert(table, key, value);
                break;
            case 2:
                printf("Enter key:\n");
                scanf("%d", &key);
                value = search(table, key);
                if (value == -1) {
                    printf("Key not found.\n");
                } else {
                    printf("Value: %d\n", value);
                }
                break;
            case 3:
                free(table);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}