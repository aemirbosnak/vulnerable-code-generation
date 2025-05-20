//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int value) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    pthread_mutex_lock(&mutex);
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    pthread_mutex_unlock(&mutex);

    printf("Enqueued value %d\n", value);
}

void dequeue() {
    struct node *temp = NULL;
    int value;

    pthread_mutex_lock(&mutex);
    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    temp = front;
    front = front->next;
    value = temp->data;
    free(temp);

    pthread_mutex_unlock(&mutex);

    printf("Dequeued value %d\n", value);
}

void *thread_enqueue(void *arg) {
    int thread_id = *(int *) arg;
    int i;

    for (i = 1; i <= 5; i++) {
        enqueue(thread_id * 10 + i);
        sleep(1);
    }

    return NULL;
}

void *thread_dequeue(void *arg) {
    int thread_id = *(int *) arg;
    int i;

    for (i = 1; i <= 5; i++) {
        dequeue();
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t thread_id[2];

    printf("Enter the number of threads to be created: ");
    scanf("%d", &i);

    if (i < 1 || i > 2) {
        printf("Invalid number of threads\n");
        return 0;
    }

    pthread_create(&thread_id[0], NULL, thread_enqueue, (void *) 1);
    pthread_create(&thread_id[1], NULL, thread_dequeue, (void *) 2);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}