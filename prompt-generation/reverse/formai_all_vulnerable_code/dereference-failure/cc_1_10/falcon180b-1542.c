//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void push(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void* pop(void* arg) {
    int data = 0;
    struct node* temp = head;
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        data = head->data;
        head = NULL;
    } else {
        while (temp->next->next!= NULL) {
            temp = temp->next;
        }
        data = temp->next->data;
        temp->next = NULL;
    }
    return (void*) data;
}

void* print_list(void* arg) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return NULL;
}

int main() {
    pthread_t thread_id[3];
    int thread_return[3];

    push(1);
    push(2);
    push(3);

    pthread_create(&thread_id[0], NULL, pop, NULL);
    pthread_create(&thread_id[1], NULL, pop, NULL);
    pthread_create(&thread_id[2], NULL, print_list, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(thread_id[i], (void**)&thread_return[i]);
        printf("Return value of thread %d is %d\n", i, thread_return[i]);
    }

    return 0;
}