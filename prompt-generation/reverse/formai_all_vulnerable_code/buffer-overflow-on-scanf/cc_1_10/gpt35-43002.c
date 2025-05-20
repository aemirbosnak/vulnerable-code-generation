//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Stack {
  struct Node* top;
  int size;
} Stack;

typedef struct Queue {
  struct Node* front;
  struct Node* rear;
  int size;
} Queue;

void initializeStack(Stack* stack) {
  stack->top = NULL;
  stack->size = 0;
}

int isEmptyStack(Stack* stack) {
  return stack->size == 0;
}

Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void push(Stack* stack, int data) {
  Node* newNode = createNode(data);
  newNode->next = stack->top;
  stack->top = newNode;
  stack->size++;
}

void pop(Stack* stack) {
  if (isEmptyStack(stack)) {
    printf("Stack is empty\n");
    return;
  }
  Node* topNode = stack->top;
  stack->top = topNode->next;
  free(topNode);
  stack->size--;
}

void initializeQueue(Queue* queue) {
  queue->front = queue->rear = NULL;
  queue->size = 0;
}

int isEmptyQueue(Queue* queue) {
  return queue->size == 0;
}

void enqueue(Queue* queue, int data) {
  Node* newNode = createNode(data);
  if (isEmptyQueue(queue)) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
  queue->size++;
}

void dequeue(Queue* queue) {
  if (isEmptyQueue(queue)) {
    printf("Queue is empty\n");
    return;
  }
  Node* frontNode = queue->front;
  queue->front = frontNode->next;
  free(frontNode);
  queue->size--;
}

int main() {
  srand(time(NULL));
  int option, data;
  Stack stack;
  Queue queue;
  Stack* pstack = &stack;
  Queue* pqueue = &queue;
  initializeStack(pstack);
  initializeQueue(pqueue);

  printf("Welcome to the Surrealist Data Structures Program!\n");

  while (1) {
    printf("\nPlease select an option from the following menu:\n");
    printf("1. Push to Stack\n");
    printf("2. Pop from Stack\n");
    printf("3. Enqueue to Queue\n");
    printf("4. Dequeue from Queue\n");
    printf("5. Exit\n");
    printf("Option: ");
    scanf("%d", &option);
    
    if (option == 1) {
      data = rand() % 100;
      push(pstack, data);
      printf("\nPushed %d to stack", data);
    } else if (option == 2) {
      pop(pstack);
    } else if (option == 3) {
      data = rand() % 100;
      enqueue(pqueue, data);
      printf("\nEnqueued %d to queue", data);
    } else if (option == 4) {
      dequeue(pqueue);
    } else if (option == 5) {
      break;
    } else {
      printf("\nInvalid option. Please try again.");
    }
  }

  printf("\nThank you for using the Surrealist Data Structures Program!\n");

  return 0;
}