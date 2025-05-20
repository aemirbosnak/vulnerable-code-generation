//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Define a bucket node structure
struct bucket_node {
    int value;
    struct bucket_node *next;
};

// Define a bucket structure
struct bucket {
    struct bucket_node *head;
    struct bucket_node *tail;
};

// Initialize an empty bucket
void init_bucket(struct bucket *bucket) {
    bucket->head = NULL;
    bucket->tail = NULL;
}

// Add a value to a bucket
void add_to_bucket(struct bucket *bucket, int value) {
    struct bucket_node *node = (struct bucket_node*) malloc(sizeof(struct bucket_node));
    node->value = value;
    node->next = NULL;
    
    if (bucket->head == NULL) {
        // If the bucket is empty, set head and tail to the new node
        bucket->head = node;
        bucket->tail = node;
    } else {
        // Otherwise, append the new node to the tail
        bucket->tail->next = node;
        bucket->tail = node;
    }
}

// Remove and return the first value from a bucket
int remove_from_bucket(struct bucket *bucket) {
    if (bucket->head == NULL) {
        // If the bucket is empty, return -1
        return -1;
    } else {
        // Otherwise, remove and return the value from the head
        struct bucket_node *node = bucket->head;
        int value = node->value;
        bucket->head = node->next;
        free(node);
        return value;
    }
}

// Bucket sort function
void bucket_sort(int arr[], int n) {
    // Initialize an array of empty buckets
    struct bucket *buckets = (struct bucket*) malloc(n * sizeof(struct bucket));
    for (int i = 0; i < n; i++) {
        init_bucket(&buckets[i]);
    }
    
    // Add each element to the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / 10;
        add_to_bucket(&buckets[bucket_index], arr[i]);
    }
    
    // Copy the elements from the buckets back to the input array
    int index = 0;
    for (int i = 0; i < n; i++) {
        while (buckets[i].head != NULL) {
            arr[index++] = remove_from_bucket(&buckets[i]);
        }
    }
    
    // Free memory used by the buckets
    free(buckets);
}

int main() {
    int arr[MAX];
    int n;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}