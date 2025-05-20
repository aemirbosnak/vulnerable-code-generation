//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100
int stack[MAX];
int top = -1;

// Function prototypes
void *push(void *arg);
void *pop(void *arg);

// Main function
int main() {
    pthread_t tid[2]; // Thread identifiers
    int ret[2]; // Thread return values
    int val;

    // Create thread for pushing elements onto stack
    ret[0] = pthread_create(&tid[0], NULL, push, NULL);
    if (ret[0] != 0) {
        printf("Error creating push thread.\n");
        exit(1);
    }

    // Wait for push thread to complete execution
    pthread_join(tid[0], NULL);

    // Create thread for popping elements from stack
    ret[1] = pthread_create(&tid[1], NULL, pop, NULL);
    if (ret[1] != 0) {
        printf("Error creating pop thread.\n");
        exit(1);
    }

    // Wait for pop thread to complete execution
    pthread_join(tid[1], NULL);

    printf("\n");

    return 0;
}

// Function for pushing elements onto stack
void *push(void *arg) {
    int val;

    while (1) {
        if (top == MAX - 1) {
            printf("Stack is full.\n");
            break;
        }

        printf("Enter a value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }

    pthread_exit(NULL);
}

// Function for popping elements from stack
void *pop(void *arg) {
    int val;

    while (1) {
        if (top == -1) {
            printf("Stack is empty.\n");
            break;
        }

        val = stack[top];
        top--;
        printf("Popped element: %d\n", val);
    }

    pthread_exit(NULL);
}