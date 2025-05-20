//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket
struct bucket_node_s {
    int data;
    struct bucket_node_s *next;
};

struct bucket_s {
    struct bucket_node_s *head;
};

// Function to create a bucket
struct bucket_s *create_bucket() {
    struct bucket_s *bucket = (struct bucket_s *)malloc(sizeof(struct bucket_s));
    bucket->head = NULL;
    return bucket;
}

// Function to insert a node into a bucket
void insert_into_bucket(struct bucket_s *bucket, int data) {
    struct bucket_node_s *new_node = (struct bucket_node_s *)malloc(sizeof(struct bucket_node_s));
    new_node->data = data;
    new_node->next = bucket->head;
    bucket->head = new_node;
}

// Function to sort the elements in a bucket
void sort_bucket(struct bucket_s *bucket) {
    struct bucket_node_s *current = bucket->head;
    struct bucket_node_s *next;

    while (current != NULL) {
        next = current->next;

        while (next != NULL) {
            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

// Function to perform bucket sort
void bucket_sort(int *array, int size) {
    // Create an array of buckets
    struct bucket_s **buckets = (struct bucket_s **)malloc(sizeof(struct bucket_s *) * size);
    for (int i = 0; i < size; i++) {
        buckets[i] = create_bucket();
    }

    // Insert the elements into the appropriate buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / size;
        insert_into_bucket(buckets[bucket_index], array[i]);
    }

    // Sort the elements in each bucket
    for (int i = 0; i < size; i++) {
        sort_bucket(buckets[i]);
    }

    // Concatenate the sorted elements from the buckets
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct bucket_node_s *current = buckets[i]->head;
        while (current != NULL) {
            array[index++] = current->data;
            current = current->next;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < size; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Get the size of the array
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Get the elements of the array
    int *array = (int *)malloc(sizeof(int) * size);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Print the original array
    printf("Original array: ");
    print_array(array, size);

    // Sort the array using bucket sort
    bucket_sort(array, size);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(array, size);

    return 0;
}