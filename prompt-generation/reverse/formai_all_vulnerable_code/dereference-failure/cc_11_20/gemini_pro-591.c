//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Bucket {
    Node *head;
    Node *tail;
} Bucket;

int main() {
    // Create an array of integers to be sorted
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the maximum value in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create an array of buckets
    int num_buckets = max + 1;
    Bucket *buckets = (Bucket *)malloc(num_buckets * sizeof(Bucket));
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Distribute the elements of the array into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i];
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->value = arr[i];
        new_node->next = NULL;
        if (buckets[bucket_index].head == NULL) {
            buckets[bucket_index].head = new_node;
            buckets[bucket_index].tail = new_node;
        } else {
            buckets[bucket_index].tail->next = new_node;
            buckets[bucket_index].tail = new_node;
        }
    }

    // Sort the elements in each bucket
    for (int i = 0; i < num_buckets; i++) {
        Node *curr = buckets[i].head;
        while (curr != NULL) {
            Node *next = curr->next;
            while (next != NULL) {
                if (curr->value > next->value) {
                    int temp = curr->value;
                    curr->value = next->value;
                    next->value = temp;
                }
                next = next->next;
            }
            curr = curr->next;
        }
    }

    // Concatenate the sorted elements from the buckets into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        Node *curr = buckets[i].head;
        while (curr != NULL) {
            arr[index++] = curr->value;
            curr = curr->next;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory allocated for the buckets
    for (int i = 0; i < num_buckets; i++) {
        Node *curr = buckets[i].head;
        while (curr != NULL) {
            Node *next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(buckets);

    return 0;
}