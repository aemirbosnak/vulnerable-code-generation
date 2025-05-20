//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Linked list head
struct node* head = NULL;

// Function to add a node at the end of the list
void add_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);
    if (head == NULL) {
        head = new_node;
    }
    else {
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    pthread_mutex_unlock(&mutex);
}

// Function to delete a node with the given data
void delete_node(int data) {
    struct node* temp = head;
    struct node* prev = NULL;

    pthread_mutex_lock(&mutex);
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
    }
    else if (temp == head) {
        head = temp->next;
        free(temp);
    }
    else {
        prev->next = temp->next;
        free(temp);
    }

    pthread_mutex_unlock(&mutex);
}

// Function to print the linked list
void print_list() {
    pthread_mutex_lock(&mutex);
    struct node* temp = head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
}

int main() {
    // Add nodes to the list
    add_node(1);
    add_node(2);
    add_node(3);

    // Print the list
    print_list();

    // Delete a node
    delete_node(2);

    // Print the list again
    print_list();

    return 0;
}