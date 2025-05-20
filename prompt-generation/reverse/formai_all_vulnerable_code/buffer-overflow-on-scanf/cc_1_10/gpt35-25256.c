//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

/* Node struct for the buckets */
typedef struct node {
    int value;
    struct node* next;
} Node;

/* Bucket sort function */
void bucketSort(int arr[], int size, int num_buckets) {
    // Create num_buckets number of empty buckets
    Node* buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }

    // Place the array elements in the appropriate buckets
    for (int i = 0; i < size; i++) {
        // Determine which bucket the element belongs to
        int bucket_index = num_buckets * arr[i] / (size + 1);

        // Add the element to the beginning of the bucket's linked list
        Node* node = malloc(sizeof(Node));
        node->value = arr[i];
        node->next = buckets[bucket_index];
        buckets[bucket_index] = node;
    }

    // Sort each bucket individually using insertion sort
    for (int i = 0; i < num_buckets; i++) {
        Node* current = buckets[i];

        while (current != NULL) {
            // Insert the next node in the sorted sublist
            Node* next = current->next;
            Node** insert_ptr = &buckets[i];

            // Traverse the sorted sublist
            while (*insert_ptr != NULL && (*insert_ptr)->value < current->value) {
                insert_ptr = &((*insert_ptr)->next);
            }

            // Insert the current node at the correct position
            current->next = *insert_ptr;
            *insert_ptr = current;

            // Move to the next node to be inserted
            current = next;
        }
    }

    // Copy the sorted elements back into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }
}

/* Main function to test the bucket sort */
int main() {
    int size, num_buckets;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of buckets: ");
    scanf("%d", &num_buckets);

    bucketSort(arr, size, num_buckets);

    printf("The sorted array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}