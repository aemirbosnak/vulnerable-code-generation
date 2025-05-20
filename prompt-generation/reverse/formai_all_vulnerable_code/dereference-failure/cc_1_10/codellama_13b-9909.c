//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a node in the memory pool
typedef struct {
    void* data;
    struct node* next;
} node;

// Struct for the memory pool
typedef struct {
    node* head;
    node* tail;
    int size;
} pool;

// Function to allocate a new node in the memory pool
void* pool_alloc(pool* p, size_t size) {
    // Allocate a new node
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        return NULL;
    }

    // Set the data and next pointers
    new_node->data = malloc(size);
    new_node->next = NULL;

    // Add the new node to the pool
    if (p->head == NULL) {
        p->head = new_node;
    } else {
        p->tail->next = new_node;
    }
    p->tail = new_node;
    p->size++;

    // Return the data pointer
    return new_node->data;
}

// Function to free a node in the memory pool
void pool_free(pool* p, void* data) {
    // Find the node to free
    node* curr = p->head;
    while (curr != NULL) {
        if (curr->data == data) {
            break;
        }
        curr = curr->next;
    }

    // Check if the node was found
    if (curr == NULL) {
        printf("Error: Node not found\n");
        return;
    }

    // Free the node
    free(curr->data);
    curr->data = NULL;

    // Remove the node from the pool
    if (curr == p->head) {
        p->head = curr->next;
    } else {
        node* prev = p->head;
        while (prev->next != curr) {
            prev = prev->next;
        }
        prev->next = curr->next;
    }
    free(curr);
    curr = NULL;
    p->size--;
}

int main() {
    // Create a new memory pool
    pool* p = malloc(sizeof(pool));
    p->head = NULL;
    p->tail = NULL;
    p->size = 0;

    // Allocate some memory from the pool
    void* data1 = pool_alloc(p, 10);
    void* data2 = pool_alloc(p, 20);
    void* data3 = pool_alloc(p, 30);

    // Use the memory
    memcpy(data1, "Hello, World!", 13);
    memcpy(data2, "Hello, Again!", 14);
    memcpy(data3, "Goodbye, World!", 15);

    // Free some memory
    pool_free(p, data1);
    pool_free(p, data3);

    // Use the memory again
    memcpy(data1, "Hello, Again!", 14);
    memcpy(data3, "Hello, Once More!", 17);

    // Free the rest of the memory
    pool_free(p, data2);

    // Clean up
    free(p);
    p = NULL;

    return 0;
}