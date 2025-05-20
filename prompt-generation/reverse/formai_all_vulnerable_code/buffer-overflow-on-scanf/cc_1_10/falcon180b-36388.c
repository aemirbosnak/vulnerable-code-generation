//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX_THREADS 10
#define MAX_KEYS 1000

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} node_t;

node_t *root = NULL;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int key = *(int *) arg;
    node_t *node = root;

    while (node!= NULL) {
        pthread_mutex_lock(&lock);
        if (key < node->key) {
            node = node->left;
        } else if (key > node->key) {
            node = node->right;
        } else {
            printf("Key %d found!\n", key);
            pthread_mutex_unlock(&lock);
            return NULL;
        }
        pthread_mutex_unlock(&lock);
    }

    printf("Key %d not found.\n", key);
    return NULL;
}

int main() {
    int i, n;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int key;

        printf("Enter key %d: ", i);
        scanf("%d", &key);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, (void *) &key);
    }

    for (i = 0; i < n; i++) {
        pthread_join(NULL, NULL);
    }

    return 0;
}