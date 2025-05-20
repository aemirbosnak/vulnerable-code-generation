//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the maximum elements in the array
#define MAX 1000

// Define the number of buckets
#define BUCKETS 10

// Define the bucket structure
struct Node {
    int value;
    struct Node* next;
};

// Define the sorting function
void BucketSort(int arr[], int n) {
    // Create an array of buckets
    struct Node* bucket[BUCKETS];

    // Initialize all buckets as empty
    for (int i = 0; i < BUCKETS; ++i) {
        bucket[i] = NULL;
    }

    // Insert elements into the appropriate buckets
    for (int i = 0; i < n; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = arr[i];

        // Calculate the index of the bucket
        int index = arr[i] / BUCKETS;

        // Insert the element into the bucket in sorted order
        struct Node* current = bucket[index];
        if (current == NULL || current->value >= arr[i]) {
            newNode->next = current;
            bucket[index] = newNode;
        } else {
            while (current->next != NULL && current->next->value < arr[i]) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Copy the elements out of the buckets and back into the array
    int index = 0;
    for (int i = 0; i < BUCKETS; ++i) {
        struct Node* current = bucket[i];
        while (current != NULL) {
            arr[index++] = current->value;
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    // Declare and initialize the array
    int arr[MAX];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using Bucket Sort
    BucketSort(arr, n);

    // Print the sorted array
    printf("The sorted array is:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}