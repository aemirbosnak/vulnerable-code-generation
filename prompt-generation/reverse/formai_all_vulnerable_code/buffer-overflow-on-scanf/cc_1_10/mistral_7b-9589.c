//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a given linked list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to print contents of a given linked list
void printList(Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Function to find size of a given linked list
int listSize(Node* node) {
    int size = 0;
    while (node != NULL) {
        size++;
        node = node->next;
    }
    return size;
}

// Bucket sort function
void bucketSort(int arr[], int n) {
    int i;
    Node** bucketArr = (Node**)malloc(n * sizeof(Node*));

    for (i = 0; i < n; i++) {
        bucketArr[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        append(bucketArr + arr[i], arr[i]);
    }

    int index = 0;
    Node* current = NULL;

    for (int i = 0; i < n; i++) {
        if (bucketArr[i] != NULL) {
            current = bucketArr[i];
            while (current != NULL) {
                arr[index++] = current->data;
                current = current->next;
            }
        }
    }
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    generateRandomNumbers(arr, n);

    printf("\nUnsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}