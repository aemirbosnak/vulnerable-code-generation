//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 1000000 // 1 million integers

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function declarations
void init_heap(Node** heap);
void insert_node(Node** heap, int data);
int extract_min(Node** heap);
void print_heap(Node* heap);

int main() {
    srand(time(NULL));

    Node* heap = NULL;
    init_heap(&heap);

    int choice;
    while (1) {
        printf("\n");
        printf("1. Insert element\n");
        printf("2. Extract minimum element\n");
        printf("3. Print heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert_node(&heap, data);
                break;
            }
            case 2: {
                int min_data = extract_min(&heap);
                if (min_data == -1)
                    printf("Heap is empty.\n");
                else
                    printf("Extracted minimum element is %d.\n", min_data);
                break;
            }
            case 3: {
                print_heap(heap);
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}

// Initializes an empty heap
void init_heap(Node** heap) {
    *heap = NULL;
}

// Inserts a new node with the given data into the heap
void insert_node(Node** heap, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error. Cannot allocate more memory.\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = (*heap);
    (*heap) = new_node;
}

// Extracts and returns the minimum element from the heap
int extract_min(Node** heap) {
    if (*heap == NULL)
        return -1;

    Node* min_node = (*heap);
    (*heap) = (*heap)->next;

    int min_data = min_node->data;
    free(min_node);

    return min_data;
}

// Prints the current state of the heap
void print_heap(Node* heap) {
    if (heap == NULL) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Current heap:\n");
    while (heap!= NULL) {
        printf("%d ", heap->data);
        heap = heap->next;
    }
    printf("\n");
}