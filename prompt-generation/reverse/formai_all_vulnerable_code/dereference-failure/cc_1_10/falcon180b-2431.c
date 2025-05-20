//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

sem_t lock;

void insert(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        Node *current = root;

        while (1) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void *insert_thread(void *param) {
    int data = *(int *) param;

    sem_wait(&lock);
    insert(data);
    sem_post(&lock);

    return NULL;
}

int search(int data) {
    Node *current = root;

    while (current!= NULL) {
        if (data == current->data) {
            return 1;
        } else if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return 0;
}

void *search_thread(void *param) {
    int data = *(int *) param;

    sem_wait(&lock);
    int result = search(data);
    sem_post(&lock);

    if (result == 1) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return NULL;
}

int main() {
    int i;

    sem_init(&lock, 0, 1);

    for (i = 1; i <= 10; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, insert_thread, (void *) &i);
    }

    for (i = 1; i <= 10; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, search_thread, (void *) &i);
    }

    for (i = 0; i < 20; i++) {
        pthread_join(NULL, NULL);
    }

    return 0;
}