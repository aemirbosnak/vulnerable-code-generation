//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000 // Maximum size of array
#define BUCKET_SIZE 1000 // Size of each bucket

// Node structure for creating bucket linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Create empty buckets
    struct Node** buckets = (struct Node**)malloc(BUCKET_SIZE * sizeof(struct Node*));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Insert array elements into respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKET_SIZE;
        insertAtBeginning(&buckets[bucketIndex], arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct Node* head = buckets[i];
        while (head != NULL) {
            struct Node* current = head->next;
            int key = head->data;
            while (current != NULL && current->data < key) {
                key = current->data;
                current->data = head->data;
                head->data = key;
                current = current->next;
            }
            head = head->next;
        }
    }

    // Concatenate sorted buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct Node* head = buckets[i];
        while (head != NULL) {
            arr[index++] = head->data;
            head = head->next;
        }
    }

    // Free memory
    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct Node* head = buckets[i];
        while (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(buckets);
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function - Driver code
int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements (max value = %d): ", BUCKET_SIZE * BUCKET_SIZE - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}