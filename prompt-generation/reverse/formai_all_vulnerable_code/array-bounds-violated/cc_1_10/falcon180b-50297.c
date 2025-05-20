//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    int value;
} pair;

pair arr[MAX_SIZE];
int size = 0;

int hash(int key) {
    return key % MAX_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    int i = 0;

    while (arr[index].key!= key && arr[index].key!= -1) {
        index = (index + 1) % MAX_SIZE;
        i++;
    }

    if (arr[index].key == -1) {
        arr[index] = (pair) {key, value};
        size++;
    } else {
        arr[index].value = value;
    }
}

int search(int key) {
    int index = hash(key);
    int i = 0;

    while (arr[index].key!= key && arr[index].key!= -1) {
        index = (index + 1) % MAX_SIZE;
        i++;
    }

    if (arr[index].key == key) {
        return arr[index].value;
    } else {
        return -1;
    }
}

int main() {
    int choice, key, value;

    printf("Enter 1 to insert a key-value pair\n");
    printf("Enter 2 to search for a key\n");
    printf("Enter 3 to exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key: ");
                scanf("%d", &key);
                printf("Enter the value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%d", &key);
                int result = search(key);

                if (result == -1) {
                    printf("Key not found\n");
                } else {
                    printf("Value: %d\n", result);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}