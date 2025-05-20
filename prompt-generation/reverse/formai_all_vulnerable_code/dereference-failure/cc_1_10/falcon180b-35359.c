//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct for the node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Define the binary search tree
node* tree = NULL;

// Define a mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define a function to insert a node into the binary search tree
void insert_node(int data) {
    // Lock the mutex to prevent multiple threads from inserting nodes at the same time
    pthread_mutex_lock(&mutex);

    // Create a new node with the given data
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    // If the tree is empty, set the new node as the root
    if (tree == NULL) {
        tree = new_node;
    } else {
        // Traverse the tree to find the correct position for the new node
        node* curr_node = tree;
        while (curr_node!= NULL) {
            if (data < curr_node->data) {
                if (curr_node->left == NULL) {
                    curr_node->left = new_node;
                    break;
                } else {
                    curr_node = curr_node->left;
                }
            } else {
                if (curr_node->right == NULL) {
                    curr_node->right = new_node;
                    break;
                } else {
                    curr_node = curr_node->right;
                }
            }
        }
    }

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Define a function to print the binary search tree
void print_tree(node* curr_node) {
    if (curr_node!= NULL) {
        print_tree(curr_node->left);
        printf("%d ", curr_node->data);
        print_tree(curr_node->right);
    }
}

// Define a function for each thread to insert nodes into the binary search tree
void* insert_thread(void* arg) {
    // Cast the argument to an integer
    int data = *(int*) arg;

    // Insert the node into the binary search tree
    insert_node(data);

    // Print the binary search tree
    printf("Binary search tree after inserting %d nodes:\n", data);
    print_tree(tree);

    return NULL;
}

// Define the main function to create multiple threads and insert nodes into the binary search tree
int main() {
    // Create 5 threads to insert nodes into the binary search tree
    pthread_t threads[5];
    int data[5] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, insert_thread, &data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}