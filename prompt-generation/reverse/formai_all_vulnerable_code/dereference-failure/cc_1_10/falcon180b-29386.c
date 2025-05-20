//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void add_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void* print_list(void* arg) {
    Node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
    printf("\n");
}

int main() {
    int i;
    for (i = 1; i <= 10; i++) {
        add_node(i);
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    while (thread_count < MAX_THREADS) {
        int rc = pthread_create(&threads[thread_count], NULL, print_list, NULL);
        if (rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }
        thread_count++;
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}