//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Node;

Node arr[MAX_SIZE];
int size = 0;

void insert(int data) {
    if (size == MAX_SIZE) {
        printf("Error: Array is full.\n");
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->index = size;
    arr[size] = *newNode;
    size++;
}

int binarySearch(int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].data == target) {
            return mid;
        } else if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    insert(5);
    insert(10);
    insert(15);
    insert(20);

    int target = 10;
    int result = binarySearch(target);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}