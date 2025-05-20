//FormAI DATASET v1.0 Category: Queue ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // set constant size of queue

int queue[SIZE];  // declare queue array
int front = -1, rear = -1;  // initialize front and rear indexes as -1

// function to check if the queue is empty
int is_empty() {
  if (front == -1 && rear == -1) {  // if front and rear are -1, the queue is empty
    return 1;
  } else {
    return 0;
  }
}

// function to check if the queue is full
int is_full() {
  if (rear == SIZE - 1) {  // if rear index is equal to size-1, the queue is full
    return 1;
  } else {
    return 0;
  }
}

// function to add an item to the queue
void enqueue(int item) {
  if (is_full()) {  // if queue is full, display message
    printf("\nOops! The queue is full, cannot add any more items.\n");
  } else {
    if (is_empty()) {  // if queue is empty, update front index
      front = 0;
    }
    rear++;  // increment rear index
    queue[rear] = item;  // add item to queue
    printf("\nYay! %d was added to the queue.\n", item);
  }
}

// function to remove an item from the queue
void dequeue() {
  if (is_empty()) {  // if queue is empty, display message
    printf("\nOops! The queue is empty, cannot remove any items.\n");
  } else if (front == rear) {  // if only one item is left in queue, reset front and rear indexes
    printf("\nHurray! %d was removed from the queue.\n", queue[front]);
    front = rear = -1;
  } else {  // otherwise, remove item and update front index
    printf("\nHurray! %d was removed from the queue.\n", queue[front]);
    front++;
  }
}

// function to display the items in the queue
void display() {
  if (is_empty()) {  // if queue is empty, display message
    printf("\nOops! The queue is empty, cannot display any items.\n");
  } else {  // otherwise, display all items in the queue
    printf("\nCurrent queue items: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

int main() {
  int choice, item;

  do {
    // display menu and get user's choice
    printf("\n\n** HAPPY QUEUE **\n");
    printf("1. Add an item to the queue\n");
    printf("2. Remove an item from the queue\n");
    printf("3. Display the items in the queue\n");
    printf("4. Exit\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter the item you want to add: ");
        scanf("%d", &item);
        enqueue(item);  // add item to queue
        break;
      case 2:
        dequeue();  // remove item from queue
        break;
      case 3:
        display();  // display all items in queue
        break;
      case 4:
        printf("\nThank you for using Happy Queue! Have a nice day! :)\n");
        exit(0);  // exit program
      default:
        printf("\nInvalid choice! Please choose again.\n");
    }
  } while (1);  // repeat until user chooses to exit

  return 0;
}