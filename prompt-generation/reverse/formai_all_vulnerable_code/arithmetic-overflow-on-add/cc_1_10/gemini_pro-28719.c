//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A queue is like a line of people waiting for something.
// The first person in line is the one who's been waiting the longest.
// When a new person joins the line, they go to the back.
// When it's someone's turn to be helped, they leave the line.
// We can represent a queue using an array.
// The front of the queue is the first element in the array.
// The back of the queue is the last element in the array.
// We can keep track of the size of the queue by using a counter.

// This is a struct that represents a queue.
typedef struct {
  int *items;  // An array to store the items in the queue.
  int size;    // The number of items in the queue.
  int front;   // The index of the front of the queue.
  int back;    // The index of the back of the queue.
} Queue;

// This function creates a new queue.
Queue *create_queue(int size) {
  // Allocate memory for the queue.
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (queue == NULL) {
    return NULL;
  }

  // Allocate memory for the items in the queue.
  queue->items = (int *)malloc(size * sizeof(int));
  if (queue->items == NULL) {
    free(queue);
    return NULL;
  }

  // Set the size of the queue.
  queue->size = size;

  // Set the front and back of the queue to -1.
  // This indicates that the queue is empty.
  queue->front = -1;
  queue->back = -1;

  // Return the queue.
  return queue;
}

// This function destroys a queue.
void destroy_queue(Queue *queue) {
  // Free the memory for the items in the queue.
  free(queue->items);

  // Free the memory for the queue.
  free(queue);
}

// This function enqueues an item to the queue.
bool enqueue(Queue *queue, int item) {
  // Check if the queue is full.
  if (queue->back == queue->size - 1) {
    return false;
  }

  // Increment the back of the queue.
  queue->back++;

  // Set the item at the back of the queue.
  queue->items[queue->back] = item;

  // If the front of the queue is -1, then the queue was empty.
  // Set the front of the queue to 0.
  if (queue->front == -1) {
    queue->front = 0;
  }

  // Return true.
  return true;
}

// This function dequeues an item from the queue.
int dequeue(Queue *queue) {
  // Check if the queue is empty.
  if (queue->front == -1) {
    return -1;
  }

  // Get the item at the front of the queue.
  int item = queue->items[queue->front];

  // Increment the front of the queue.
  queue->front++;

  // If the front of the queue is equal to the size of the queue, then the queue is empty.
  // Set the front and back of the queue to -1.
  if (queue->front == queue->size) {
    queue->front = -1;
    queue->back = -1;
  }

  // Return the item.
  return item;
}

// This function prints the queue.
void print_queue(Queue *queue) {
  // Check if the queue is empty.
  if (queue->front == -1) {
    printf("The queue is empty.\n");
    return;
  }

  // Print the items in the queue.
  for (int i = queue->front; i <= queue->back; i++) {
    printf("%d ", queue->items[i]);
  }

  // Print a newline.
  printf("\n");
}

// This is the main function.
int main() {
  // Create a new queue.
  Queue *queue = create_queue(5);

  // Enqueue some items to the queue.
  enqueue(queue, 1);
  enqueue(queue, 2);
  enqueue(queue, 3);
  enqueue(queue, 4);
  enqueue(queue, 5);

  // Print the queue.
  print_queue(queue);

  // Dequeue some items from the queue.
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);

  // Print the queue.
  print_queue(queue);

  // Destroy the queue.
  destroy_queue(queue);

  return 0;
}