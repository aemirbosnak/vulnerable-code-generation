//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // Size of each bucket for the sorting

// Node structure for linked list
struct Node {
    float value;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in a sorted manner
void insertSorted(struct Node** head_ref, float value) {
    struct Node* newNode = createNode(value);
    struct Node* current;

    // If the new node is less than the head
    if (*head_ref == NULL || (*head_ref)->value >= newNode->value) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        current = *head_ref;
        // Locate the node before the point of insertion
        while (current->next != NULL && current->next->value < newNode->value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%.2f -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to perform insertion sort on a bucket
void insertionSort(struct Node** head_ref) {
    struct Node* sorted = NULL;
    struct Node* current = *head_ref;

    // Insert each node to the sorted linked list
    while (current != NULL) {
        struct Node* next = current->next;
        insertSorted(&sorted, current->value);
        current = next;
    }
    *head_ref = sorted;
}

// Function to do bucket sort
void bucketSort(float arr[], int n) {
    // Create buckets
    struct Node** buckets = (struct Node**)malloc(BUCKET_SIZE * sizeof(struct Node*));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(BUCKET_SIZE * arr[i]); // Determine bucket index
        if (index >= BUCKET_SIZE) {
            index = BUCKET_SIZE - 1; // Last bucket
        }
        insertSorted(&buckets[index], arr[i]);
    }

    // Sort each bucket and concatenate
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i] != NULL) {
            insertionSort(&buckets[i]);
            struct Node* current = buckets[i];
            while (current != NULL) {
                arr[index++] = current->value;
                struct Node* temp = current;
                current = current->next;
                free(temp); // Free the memory
            }
            buckets[i] = NULL; // Empty the bucket
        }
    }

    free(buckets); // Free the memory for buckets
}

// Main function to test bucket sort
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    float *arr = (float*)malloc(n * sizeof(float));
    printf("Enter the elements (0.0 to 1.0): \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the allocated memory for the array
    return 0;
}