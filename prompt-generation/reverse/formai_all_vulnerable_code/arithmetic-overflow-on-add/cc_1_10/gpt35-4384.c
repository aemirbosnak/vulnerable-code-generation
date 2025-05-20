//FormAI DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Task data structure
typedef struct _task {
    char name[50];
    int priority;
    int arrival_time;
    int deadline;
    int execution_time;
} Task;

// Task queue data structure
typedef struct _queue {
    Task* tasks;
    int front;
    int rear;
    int size;
} Queue;

// Returns true if the queue is empty
bool is_empty(Queue* queue) {
    return (queue->size == 0);
}

// Returns true if the queue is full
bool is_full(Queue* queue) {
    return (queue->size == 100);
}

// Inserts a task into the queue (priority queue implementation)
void enqueue(Queue* queue, Task* task) {
    int i;
    if (!is_full(queue)) {
        if (is_empty(queue)) {
            queue->tasks[0] = *task;
        } else {
            for (i = queue->size - 1; i >= 0; i--) {
                if (queue->tasks[i].priority <= task->priority) {
                    break;
                }
                queue->tasks[i + 1] = queue->tasks[i];
            }
            queue->tasks[i + 1] = *task;
        }
        queue->rear = (queue->rear + 1) % 100;
        queue->size++;
    }
}

// Removes the highest priority task from the queue
Task dequeue(Queue* queue) {
    Task task;
    if (!is_empty(queue)) {
        task = queue->tasks[queue->front];
        queue->front = (queue->front + 1) % 100;
        queue->size--;
    }
    return task;
}

// Returns the current timestamp
int get_time() {
    time_t now = time(NULL);
    return (int)now;
}

int main() {
    srand(time(NULL));
    
    // Create a queue for tasks (priority queue implementation)
    Queue task_queue = {
        .tasks = malloc(sizeof(Task) * 100),
        .front = 0,
        .rear = -1,
        .size = 0
    };
    
    // Create some tasks and enqueue them
    Task task1 = {
        .name = "Task 1",
        .priority = 1,
        .arrival_time = get_time(),
        .deadline = get_time() + 60,
        .execution_time = rand() % 60
    };
    enqueue(&task_queue, &task1);
    
    Task task2 = {
        .name = "Task 2",
        .priority = 2,
        .arrival_time = get_time() + 10,
        .deadline = get_time() + 70,
        .execution_time = rand() % 60
    };
    enqueue(&task_queue, &task2);
    
    Task task3 = {
        .name = "Task 3",
        .priority = 3,
        .arrival_time = get_time() + 20,
        .deadline = get_time() + 80,
        .execution_time = rand() % 60
    };
    enqueue(&task_queue, &task3);
    
    Task task4 = {
        .name = "Task 4",
        .priority = 4,
        .arrival_time = get_time() + 30,
        .deadline = get_time() + 90,
        .execution_time = rand() % 60
    };
    enqueue(&task_queue, &task4);
    
    Task task5 = {
        .name = "Task 5",
        .priority = 5,
        .arrival_time = get_time() + 40,
        .deadline = get_time() + 100,
        .execution_time = rand() % 60
    };
    enqueue(&task_queue, &task5);
    
    printf("Task queue:\n");
    int i;
    for (i = 0; i < task_queue.size; i++) {
        printf("%s\n", task_queue.tasks[i].name);
    }
    
    printf("\nRunning tasks...\n");
    int current_time = get_time();
    while (!is_empty(&task_queue)) {
        Task task = dequeue(&task_queue);
        printf("Executing task %s...\n", task.name);
        sleep(task.execution_time); // Simulate task execution
        current_time += task.execution_time;
        if (current_time > task.deadline) {
            printf("Task %s missed deadline!\n", task.name);
        } else {
            printf("Task %s completed successfully!\n", task.name);
        }
    }
    
    return 0;
}