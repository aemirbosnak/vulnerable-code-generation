//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* add_node(void* arg) {
    int data = *(int*) arg;
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&lock);
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* remove_node(void* arg) {
    int data = *(int*) arg;
    Node* prev = NULL;
    Node* curr = head;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node with data %d not found\n", data);
        return NULL;
    }

    if (prev == NULL) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);

    return NULL;
}

void* print_list(void* arg) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return NULL;
}

int main() {
    pthread_t add_thread, remove_thread, print_thread;

    pthread_create(&add_thread, NULL, add_node, (void*) 5);
    pthread_create(&remove_thread, NULL, remove_node, (void*) 5);
    pthread_create(&print_thread, NULL, print_list, NULL);

    pthread_join(add_thread, NULL);
    pthread_join(remove_thread, NULL);
    pthread_join(print_thread, NULL);

    return 0;
}