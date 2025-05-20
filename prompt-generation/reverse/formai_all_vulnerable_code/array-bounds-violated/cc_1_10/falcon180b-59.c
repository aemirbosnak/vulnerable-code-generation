//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int key;
    int value;
} hash_pair;

hash_pair hash_table[MAX_SIZE];

int hash_function(int key) {
    return key % MAX_SIZE;
}

void insert_hash(int key, int value) {
    int index = hash_function(key);
    hash_pair pair = {key, value};
    hash_table[index] = pair;
}

int search_hash(int key) {
    int index = hash_function(key);
    hash_pair pair = hash_table[index];
    if (pair.key == key) {
        return pair.value;
    } else {
        return -1;
    }
}

void delete_hash(int key) {
    int index = hash_function(key);
    hash_pair pair = hash_table[index];
    if (pair.key == key) {
        hash_table[index] = (hash_pair) {0, 0};
    }
}

int main() {
    srand(time(NULL));
    int choice, key, value;

    do {
        printf("1. Insert\n2. Search\n3. Delete\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert_hash(key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search_hash(key);
                if (value!= -1) {
                    printf("Value: %d\n", value);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete_hash(key);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(1);

    return 0;
}