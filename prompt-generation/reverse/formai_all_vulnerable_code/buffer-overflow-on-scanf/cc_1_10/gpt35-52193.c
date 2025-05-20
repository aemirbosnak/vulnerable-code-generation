//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scientific
/*
A unique C Task Scheduler program that dynamically schedules tasks based on their priority level.
This program utilizes a priority queue data structure to efficiently schedule tasks.
Written by John Doe, PhD.

Input:
- User enters the number of tasks to be scheduled
- User enters details of each task (task name, priority level, and estimated completion time)

Output:
- The program outputs the details of each task in the order they are scheduled to be executed

*/

#include <stdio.h>
#include <stdlib.h>

// Task structure definition
typedef struct task {
    char name[20];
    int priority;
    int time;
} task;

// Priority queue structure definition
typedef struct priority_queue {
    task *arr;
    int size;
    int capacity;
} priority_queue;

// Function prototypes
priority_queue *create_priority_queue(int);
void enqueue(priority_queue *, task *);
task *dequeue(priority_queue *);
void destroy_priority_queue(priority_queue *);
void swap(task *, task *);
void heapify(priority_queue *, int);

// Main function
int main() {

    int num_tasks;

    // Get number of tasks from user
    printf("Enter the number of tasks to be scheduled:\n");
    scanf("%d", &num_tasks);

    // Allocate memory for tasks and priority queue
    task *tasks = (task *) malloc(num_tasks * sizeof(task));
    priority_queue *pq = create_priority_queue(num_tasks);

    // Get details of each task from user
    for (int i = 0; i < num_tasks; i++) {
        printf("Enter details of task %d:\n", i+1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority (1-10): ");
        scanf("%d", &tasks[i].priority);
        printf("Estimated completion time (in minutes): ");
        scanf("%d", &tasks[i].time);
        enqueue(pq, &tasks[i]);
    }

    // Schedule tasks in order of priority
    printf("\nScheduled order of tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s (Priority: %d, Time: %d min)\n", i+1, dequeue(pq)->name, pq->arr[0].priority, pq->arr[0].time);
        heapify(pq, 0);
    }

    // Free memory and exit program
    destroy_priority_queue(pq);
    free(tasks);
    return 0;
}

// Function to create priority queue
priority_queue *create_priority_queue(int capacity) {
    priority_queue *pq = (priority_queue *) malloc(sizeof(priority_queue));
    pq->arr = (task *) malloc(capacity * sizeof(task));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

// Function to add task to priority queue
void enqueue(priority_queue *pq, task *t) {
    int i = pq->size;
    if (i == pq->capacity) {
        printf("Priority queue is full.\n");
        return;
    }
    pq->size++;
    pq->arr[i] = *t;
    while (i > 0 && pq->arr[(i-1)/2].priority < pq->arr[i].priority) {
        swap(&pq->arr[(i-1)/2], &pq->arr[i]);
        i = (i-1)/2;
    }
}

// Function to remove and return highest priority task from priority queue
task *dequeue(priority_queue *pq) {
    if (pq->size == 0) {
        printf("Priority queue is empty.\n");
        return NULL;
    }
    task *t = &pq->arr[0];
    pq->arr[0] = pq->arr[pq->size-1];
    pq->size--;
    heapify(pq, 0);
    return t;
}

// Function to destroy priority queue and free memory
void destroy_priority_queue(priority_queue *pq) {
    free(pq->arr);
    free(pq);
}

// Function to swap two tasks
void swap(task *a, task *b) {
    task temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain heap property while inserting or removing tasks
void heapify(priority_queue *pq, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < pq->size && pq->arr[l].priority > pq->arr[largest].priority) {
        largest = l;
    }
    if (r < pq->size && pq->arr[r].priority > pq->arr[largest].priority) {
        largest = r;
    }
    if (largest != i) {
        swap(&pq->arr[i], &pq->arr[largest]);
        heapify(pq, largest);
    }
}