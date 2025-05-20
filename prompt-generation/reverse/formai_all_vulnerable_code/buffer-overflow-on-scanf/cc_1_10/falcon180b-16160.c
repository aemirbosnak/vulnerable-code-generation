//Falcon-180B DATASET v1.0 Category: Educational ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Function to add an element to the queue
void enqueue(int *front, int *rear, int *queue, int size, int value) {
    if ((*rear) == (*front - 1)) {
        printf("\nQueue is full. Cannot add element. ");
        return;
    }
    else if ((*front) == -1) {
        (*front) = 0;
    }
    (*rear)++;
    queue[*rear] = value;
}

//Function to remove an element from the queue
void dequeue(int *front, int *rear, int *queue, int size) {
    if ((*front) == -1 || (*front) > (*rear)) {
        printf("\nQueue is empty. Cannot remove element. ");
        return;
    }
    else {
        (*front)++;
    }
}

//Function to display the queue
void display(int *front, int *rear, int *queue, int size) {
    int i;
    if ((*front) == -1) {
        printf("\nQueue is empty. ");
    }
    else {
        printf("\nQueue elements are: ");
        for (i = (*front); i <= (*rear); i++) {
            printf("%d ", queue[i]);
        }
    }
}

//Main function
int main() {
    int front = -1, rear = -1, choice, value, size = MAX;
    int queue[MAX];

    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n\nMENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be added: ");
                scanf("%d", &value);
                enqueue(&front, &rear, queue, size, value);
                break;
            case 2:
                dequeue(&front, &rear, queue, size);
                break;
            case 3:
                display(&front, &rear, queue, size);
                break;
            case 4:
                printf("\nExiting... ");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again. ");
        }
    }

    return 0;
}