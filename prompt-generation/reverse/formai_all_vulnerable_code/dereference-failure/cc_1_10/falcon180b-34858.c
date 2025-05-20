//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NODES 1000

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

void *thread_func(void *arg) {
    int num = *(int *) arg;
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = num;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        Node *temp = root;
        while (1) {
            if (num < temp->data) {
                if (temp->left == NULL) {
                    temp->left = new_node;
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = new_node;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }

    pthread_exit(0);
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_NODES; i++) {
        pthread_create(&threads[i % MAX_THREADS], NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Binary search tree created\n");

    return 0;
}