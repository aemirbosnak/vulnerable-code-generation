//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_NODES 100
#define MAX_THREADS 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = create_node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    Node* head = NULL;
    int count = 0;

    srand(time(NULL) + thread_id);

    while (count < 10) {
        int random_data = rand() % 100;
        push(&head, random_data);
        count++;
        sleep(1);
    }

    printf("Thread %d finished\n", thread_id);
    print_list(head);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    Node* head = NULL;

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}