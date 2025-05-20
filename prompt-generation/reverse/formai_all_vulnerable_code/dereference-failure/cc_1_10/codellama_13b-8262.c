//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a queue node
typedef struct queueNode {
  int value;
  struct queueNode *next;
} QueueNode;

// Define a structure for a queue
typedef struct queue {
  QueueNode *front;
  QueueNode *rear;
} Queue;

// Function to create a new queue
Queue* createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

// Function to add an element to the queue
void enqueue(Queue *queue, int value) {
  QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
  newNode->value = value;
  newNode->next = NULL;

  if (queue->front == NULL) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

// Function to remove an element from the queue
int dequeue(Queue *queue) {
  if (queue->front == NULL) {
    return -1;
  }

  QueueNode *temp = queue->front;
  int value = temp->value;
  queue->front = temp->next;
  free(temp);
  return value;
}

// Function to check if the queue is empty
bool isEmpty(Queue *queue) {
  return (queue->front == NULL);
}

// Function to print the queue
void printQueue(Queue *queue) {
  QueueNode *current = queue->front;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Create a new queue
  Queue *queue = createQueue();

  // Enqueue some elements
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Dequeue some elements
  printf("Dequeued: %d\n", dequeue(queue));
  printf("Dequeued: %d\n", dequeue(queue));
  printf("Dequeued: %d\n", dequeue(queue));

  // Check if the queue is empty
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
  } else {
    printf("Queue is not empty\n");
  }

  // Print the queue
  printQueue(queue);

  // Dequeue all remaining elements
  while (!isEmpty(queue)) {
    printf("Dequeued: %d\n", dequeue(queue));
  }

  return 0;
}