//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a task struct
typedef struct task {
  int id;             // Task ID
  char *name;         // Task name
  int priority;       // Task priority
  time_t start_time;  // Task start time
  time_t end_time;    // Task end time
} task;

// Define a task queue
typedef struct task_queue {
  task *tasks;       // Array of tasks
  int size;          // Number of tasks in the queue
  int capacity;      // Capacity of the queue
} task_queue;

// Create a new task queue
task_queue *create_task_queue(int capacity) {
  task_queue *queue = malloc(sizeof(task_queue));
  queue->tasks = malloc(sizeof(task) * capacity);
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

// Destroy a task queue
void destroy_task_queue(task_queue *queue) {
  free(queue->tasks);
  free(queue);
}

// Add a task to the queue
void enqueue_task(task_queue *queue, task *task) {
  if (queue->size == queue->capacity) {
    printf("Task queue is full!\n");
    return;
  }
  queue->tasks[queue->size++] = *task;
}

// Remove a task from the queue
task *dequeue_task(task_queue *queue) {
  if (queue->size == 0) {
    printf("Task queue is empty!\n");
    return NULL;
  }
  return &queue->tasks[--queue->size];
}

// Print the tasks in the queue
void print_tasks(task_queue *queue) {
  for (int i = 0; i < queue->size; i++) {
    printf("Task %d: %s (priority: %d, start: %s, end: %s)\n",
      queue->tasks[i].id,
      queue->tasks[i].name,
      queue->tasks[i].priority,
      ctime(&queue->tasks[i].start_time),
      ctime(&queue->tasks[i].end_time)
    );
  }
}

// Main function
int main() {
  // Create a task queue with a capacity of 10
  task_queue *queue = create_task_queue(10);

  // Create a few tasks
  task task1 = {
    .id = 1,
    .name = "Hack the mainframe",
    .priority = 10,
    .start_time = time(NULL),
    .end_time = time(NULL) + 600  // 10 minutes
  };

  task task2 = {
    .id = 2,
    .name = "Infiltrate the corporate HQ",
    .priority = 8,
    .start_time = time(NULL) + 300,  // 5 minutes from now
    .end_time = time(NULL) + 1200  // 20 minutes
  };

  task task3 = {
    .id = 3,
    .name = "Escape the city",
    .priority = 5,
    .start_time = time(NULL) + 900,  // 15 minutes from now
    .end_time = time(NULL) + 1800  // 30 minutes
  };

  // Add the tasks to the queue
  enqueue_task(queue, &task1);
  enqueue_task(queue, &task2);
  enqueue_task(queue, &task3);

  // Print the tasks in the queue
  print_tasks(queue);

  // Remove a task from the queue
  task *task4 = dequeue_task(queue);

  // Print the task that was removed
  printf("Removed task: %s\n", task4->name);

  // Destroy the task queue
  destroy_task_queue(queue);

  return 0;
}