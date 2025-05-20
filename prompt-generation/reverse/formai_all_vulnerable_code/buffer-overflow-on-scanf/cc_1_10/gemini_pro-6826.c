//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100
#define BUCKET_COUNT 10

// Create a linked list node
struct node {
    int value;
    struct node *next;
};

// Create a bucket
struct bucket {
    struct node *head;
    struct node *tail;
};

// Create an array of buckets
struct bucket buckets[BUCKET_COUNT];

// Insert a value into a bucket
void insert_into_bucket(int value) {
    // Calculate the bucket index
    int bucket_index = value / (MAX_VALUE / BUCKET_COUNT);

    // Create a new node
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = NULL;

    // Insert the node into the bucket
    if (buckets[bucket_index].head == NULL) {
        buckets[bucket_index].head = new_node;
        buckets[bucket_index].tail = new_node;
    } else {
        buckets[bucket_index].tail->next = new_node;
        buckets[bucket_index].tail = new_node;
    }
}

// Sort the values in the buckets
void sort_buckets() {
    // Iterate over the buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Get the head of the bucket
        struct node *current = buckets[i].head;

        // Iterate over the nodes in the bucket
        while (current != NULL) {
            // Get the next node
            struct node *next = current->next;

            // Insert the current node into the sorted list
            struct node *prev = NULL;
            struct node *ptr = buckets[i].head;
            while (ptr != NULL && ptr->value < current->value) {
                prev = ptr;
                ptr = ptr->next;
            }
            if (prev == NULL) {
                current->next = buckets[i].head;
                buckets[i].head = current;
            } else {
                prev->next = current;
                current->next = ptr;
            }

            // Move to the next node
            current = next;
        }
    }
}

// Print the values in the buckets
void print_buckets() {
    // Iterate over the buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Get the head of the bucket
        struct node *current = buckets[i].head;

        // Iterate over the nodes in the bucket
        while (current != NULL) {
            // Print the value
            printf("%d ", current->value);

            // Move to the next node
            current = current->next;
        }
        printf("\n");
    }
}

// Free the memory allocated for the buckets
void free_buckets() {
    // Iterate over the buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // Get the head of the bucket
        struct node *current = buckets[i].head;

        // Iterate over the nodes in the bucket
        while (current != NULL) {
            // Free the node
            struct node *next = current->next;
            free(current);

            // Move to the next node
            current = next;
        }
    }
}

int main() {
    // Get the number of values to sort
    int n;
    printf("Enter the number of values to sort: ");
    scanf("%d", &n);

    // Get the values to sort
    int values[n];
    printf("Enter the values to sort: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Insert the values into the buckets
    for (int i = 0; i < n; i++) {
        insert_into_bucket(values[i]);
    }

    // Sort the values in the buckets
    sort_buckets();

    // Print the values in the buckets
    print_buckets();

    // Free the memory allocated for the buckets
    free_buckets();

    return 0;
}