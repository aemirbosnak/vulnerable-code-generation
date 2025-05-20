//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  // Define a structure for the queue
  typedef struct {
    int *arr;
    int size;
    int front;
    int rear;
  } Queue;

  // Function to create a new queue
  Queue* createQueue(int size) {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->arr = (int*) malloc(sizeof(int) * size);
    return q;
  }

  // Function to add an element to the queue
  void enqueue(Queue *q, int element) {
    if (q->rear == q->size) {
      printf("Queue is full!\n");
      return;
    }
    q->arr[q->rear] = element;
    q->rear++;
  }

  // Function to remove an element from the queue
  int dequeue(Queue *q) {
    if (q->front == q->rear) {
      printf("Queue is empty!\n");
      return -1;
    }
    int element = q->arr[q->front];
    q->front++;
    return element;
  }

  // Function to display the queue
  void displayQueue(Queue *q) {
    printf("Queue: ");
    for (int i = q->front; i < q->rear; i++) {
      printf("%d ", q->arr[i]);
    }
    printf("\n");
  }

  // Driver code
  int main() {
    Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    int element = dequeue(q);
    printf("Dequeued element: %d\n", element);
    displayQueue(q);
    return 0;
  }