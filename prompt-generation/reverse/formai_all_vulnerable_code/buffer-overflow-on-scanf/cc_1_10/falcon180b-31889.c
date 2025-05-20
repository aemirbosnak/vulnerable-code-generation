//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to add a node at the end of a linked list
void addNode(Node** head, int data) {
    Node* node = newNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        *head = node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / n;
    Node** buckets = (Node**)malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / bucketSize;
        addNode(&buckets[bucketIndex], arr[i]);
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = buckets[i];
        while (temp!= NULL) {
            arr[index++] = temp->data;
            temp = temp->next;
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printList((Node*)arr);
    return 0;
}