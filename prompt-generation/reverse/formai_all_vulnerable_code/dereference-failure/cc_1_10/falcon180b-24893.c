//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NODES 100

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

void* delete_node(void* arg) {
    int data = *(int*) arg;
    Node* temp = head;
    Node* prev = NULL;

    pthread_mutex_lock(&lock);
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        pthread_mutex_unlock(&lock);
        return NULL;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    pthread_mutex_unlock(&lock);
    free(temp);

    return NULL;
}

void* print_list(void* arg) {
    pthread_mutex_lock(&lock);
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_NODES; i++) {
        pthread_create(&threads[i % MAX_THREADS], NULL, add_node, (void*) &i);
    }

    for (i = 0; i < MAX_NODES; i++) {
        pthread_create(&threads[i % MAX_THREADS], NULL, delete_node, (void*) &i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}