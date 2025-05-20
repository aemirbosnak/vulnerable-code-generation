//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct task {
    void (*func)(void *data);
    void *data;
    struct task *next;
} Task;

typedef struct task_queue {
    Task *head;
    Task *tail;
    pthread_mutex_t lock;
    pthread_cond_t cond;
} TaskQueue;

void task_queue_init(TaskQueue *q) {
    q->head = NULL;
    q->tail = NULL;
    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->cond, NULL);
}

void task_queue_destroy(TaskQueue *q) {
    Task *task;
    while ((task = q->head)!= NULL) {
        q->head = task->next;
        free(task->data);
        free(task);
    }
    pthread_mutex_destroy(&q->lock);
    pthread_cond_destroy(&q->cond);
}

void task_queue_push(TaskQueue *q, void (*func)(void *data), void *data) {
    Task *task = malloc(sizeof(Task));
    task->func = func;
    task->data = data;
    pthread_mutex_lock(&q->lock);
    if (q->tail == NULL) {
        q->head = task;
        q->tail = task;
    } else {
        q->tail->next = task;
        q->tail = task;
    }
    pthread_mutex_unlock(&q->lock);
    pthread_cond_signal(&q->cond);
}

void *task_thread(void *arg) {
    TaskQueue *q = arg;
    while (1) {
        pthread_mutex_lock(&q->lock);
        while (q->head == NULL) {
            pthread_cond_wait(&q->cond, &q->lock);
        }
        Task *task = q->head;
        q->head = task->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        pthread_mutex_unlock(&q->lock);
        task->func(task->data);
        free(task->data);
        free(task);
    }
    return NULL;
}

int main() {
    TaskQueue q;
    task_queue_init(&q);
    int count = 0;
    while (count < 10) {
        printf("Enter task %d (0 to exit):\n", count + 1);
        char input[100];
        scanf("%s", input);
        if (strcmp(input, "0") == 0) {
            break;
        }
        task_queue_push(&q, task_thread, NULL);
        count++;
    }
    task_queue_destroy(&q);
    return 0;
}