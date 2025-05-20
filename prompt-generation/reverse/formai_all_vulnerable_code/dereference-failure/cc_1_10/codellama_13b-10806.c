//Code Llama-13B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
// Bucket Sort Implementation in a Safe Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10

// A structure to represent a node in a linked list
typedef struct node {
    int value;
    struct node *next;
} node_t;

// A structure to represent a bucket
typedef struct bucket {
    node_t *head;
    node_t *tail;
} bucket_t;

// A function to create a new node with the given value
node_t *new_node(int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

// A function to add a node to the end of a linked list
void add_node(bucket_t *bucket, int value) {
    node_t *node = new_node(value);
    if (bucket->head == NULL) {
        bucket->head = node;
    } else {
        bucket->tail->next = node;
    }
    bucket->tail = node;
}

// A function to sort a linked list using bucket sort
void bucket_sort(bucket_t *bucket) {
    // Create an array of linked lists, each representing a bucket
    bucket_t buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Distribute the elements of the linked list into the buckets
    node_t *current = bucket->head;
    while (current != NULL) {
        int bucket_index = current->value / BUCKET_SIZE;
        add_node(&buckets[bucket_index], current->value);
        current = current->next;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        node_t *current = buckets[i].head;
        node_t *next = NULL;
        while (current != NULL) {
            next = current->next;
            if (current->value < current->next->value) {
                current->next = current->next->next;
                current->next->next = current;
            }
            current = next;
        }
    }

    // Concatenate the buckets into a single linked list
    bucket->head = NULL;
    bucket->tail = NULL;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i].head != NULL) {
            if (bucket->head == NULL) {
                bucket->head = buckets[i].head;
            } else {
                bucket->tail->next = buckets[i].head;
            }
            bucket->tail = buckets[i].tail;
        }
    }
}

int main() {
    // Create a linked list with the given elements
    int elements[] = {1, 5, 2, 3, 7, 9, 6, 4};
    bucket_t bucket;
    bucket.head = NULL;
    bucket.tail = NULL;
    for (int i = 0; i < sizeof(elements) / sizeof(elements[0]); i++) {
        add_node(&bucket, elements[i]);
    }

    // Sort the linked list using bucket sort
    bucket_sort(&bucket);

    // Print the sorted linked list
    node_t *current = bucket.head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    return 0;
}