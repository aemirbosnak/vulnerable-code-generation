//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include <pthread.h>

    struct task {
        char* name;
        int duration;
        int priority;
        struct task* next;
    };

    struct task_queue {
        struct task* head;
        struct task* tail;
    };

    void enqueue(struct task_queue* queue, struct task* task) {
        if (queue->head == NULL) {
            queue->head = task;
            queue->tail = task;
        } else {
            queue->tail->next = task;
            queue->tail = task;
        }
    }

    struct task* dequeue(struct task_queue* queue) {
        if (queue->head == NULL) {
            return NULL;
        }
        struct task* task = queue->head;
        queue->head = queue->head->next;
        return task;
    }

    void schedule(struct task_queue* queue) {
        struct task* task = dequeue(queue);
        while (task != NULL) {
            printf("Scheduling task %s with duration %d and priority %d\n", task->name, task->duration, task->priority);
            sleep(task->duration);
            task = dequeue(queue);
        }
    }

    int main(int argc, char* argv[]) {
        struct task_queue queue;
        queue.head = NULL;
        queue.tail = NULL;

        struct task task1;
        task1.name = "Task 1";
        task1.duration = 5;
        task1.priority = 1;
        enqueue(&queue, &task1);

        struct task task2;
        task2.name = "Task 2";
        task2.duration = 10;
        task2.priority = 2;
        enqueue(&queue, &task2);

        struct task task3;
        task3.name = "Task 3";
        task3.duration = 15;
        task3.priority = 3;
        enqueue(&queue, &task3);

        schedule(&queue);

        return 0;
    }