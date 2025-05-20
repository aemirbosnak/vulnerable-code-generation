//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 10
#define BUCKET_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int hashFunction(int key, int numBuckets) {
    return key % numBuckets;
}

void bucketSort(int arr[], int size) {
    Node** buckets = (Node**)calloc(MAX_BUCKETS, sizeof(Node*));
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = hashFunction(arr[i], MAX_BUCKETS);
        insertNode(&buckets[bucketIndex], arr[i]);
    }

    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }

    free(buckets);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}