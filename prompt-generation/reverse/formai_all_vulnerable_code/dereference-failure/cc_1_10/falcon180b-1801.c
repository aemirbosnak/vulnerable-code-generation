//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

// Define a node structure
typedef struct node {
    int data;
    struct node* link;
} Node;

// Define a list structure
typedef struct list {
    Node* head;
    pthread_mutex_t lock;
} List;

// Function to create a new node with given data
Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Memory could not be allocated for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// Function to append a node to the end of the list
void append_node(List* list, int data) {
    Node* new_node = create_node(data);
    pthread_mutex_lock(&list->lock);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* temp = list->head;
        while (temp->link!= NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
    pthread_mutex_unlock(&list->lock);
}

// Function to print the list
void print_list(List* list) {
    pthread_mutex_lock(&list->lock);
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
    pthread_mutex_unlock(&list->lock);
}

int main() {
    List* my_list = (List*) malloc(sizeof(List));
    if (my_list == NULL) {
        printf("Error: Memory could not be allocated for the list.\n");
        exit(1);
    }
    my_list->head = NULL;
    pthread_mutex_init(&my_list->lock, NULL);

    // Append some nodes to the list
    append_node(my_list, 1);
    append_node(my_list, 2);
    append_node(my_list, 3);

    // Print the list
    print_list(my_list);

    // Free the memory allocated for the list
    pthread_mutex_destroy(&my_list->lock);
    free(my_list);

    return 0;
}