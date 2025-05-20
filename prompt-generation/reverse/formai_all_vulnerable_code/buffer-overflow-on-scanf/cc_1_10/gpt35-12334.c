//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include <stdio.h>
#define MAXSIZE 5

int front = -1;
int rear = -1;
int queue[MAXSIZE];

//Function to check if the queue is empty
int is_empty() {
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

//Function to check if the queue is full
int is_full() {
    if (rear == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

//Function to insert an element in the queue
void push(int val) {
    if (is_full()) {
        printf("Queue is full\n");
        return;
    }
    else if (is_empty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = val;
}

//Function to delete an element from the queue
void pop() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }
    else if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

//Function to display the elements of the queue
void display() {
    if (is_empty()) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("The elements of the queue are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int option, val;
    do {
        printf("\n");
        printf("1. Insert an element in the queue\n");
        printf("2. Delete an element from the queue\n");
        printf("3. Display the elements of the queue\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    } while (option != 4);
    return 0;
}