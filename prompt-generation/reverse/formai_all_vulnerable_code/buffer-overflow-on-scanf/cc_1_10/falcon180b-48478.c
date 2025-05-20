//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
  int data;
  struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Queue is full\n");
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
  if (front == NULL) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int dequeue() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = front->data;
  Node* temp = front;
  front = front->next;
  free(temp);
  if (front == NULL) {
    rear = NULL;
  }
  return data;
}

int peek() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  return front->data;
}

void display() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements are:\n");
  Node* temp = front;
  while (temp!= NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice, data;
  do {
    printf("Enter your choice:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to enqueue:\n");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        data = dequeue();
        if (data!= -1) {
          printf("Dequeued data is %d\n", data);
        }
        break;
      case 3:
        data = peek();
        if (data!= -1) {
          printf("Peeked data is %d\n", data);
        }
        break;
      case 4:
        display();
        break;
      case 5:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice!= 5);
  return 0;
}