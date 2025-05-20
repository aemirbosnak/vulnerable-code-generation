//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

void create(Node* arr, int size);
void display(Node* arr, int size);
void search(Node* arr, int size, int key);

int main() {
    Node* arr = (Node*)malloc(MAX_SIZE * sizeof(Node));
    int size = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    create(arr, size);
    printf("Array created: ");
    display(arr, size);

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    search(arr, size, key);

    free(arr);
    return 0;
}

void create(Node* arr, int size) {
    printf("Enter %d elements: ", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }
}

void display(Node* arr, int size) {
    printf("Array: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }

    printf("\n");
}

void search(Node* arr, int size, int key) {
    Node* result = (Node*)malloc(sizeof(Node));
    result->data = -1;
    result->index = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i].data == key) {
            result->data = key;
            result->index = i;
            break;
        }
    }

    if (result->data == -1) {
        printf("Key not found!\n");
    } else {
        printf("Key found at index %d.\n", result->index);
    }

    free(result);
}