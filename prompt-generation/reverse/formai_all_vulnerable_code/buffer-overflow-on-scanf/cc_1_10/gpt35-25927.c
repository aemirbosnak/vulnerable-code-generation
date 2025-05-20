//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAX_OPERATIONS 100

int operationCounter = 0; // Global counter for operations
double ans[MAX_OPERATIONS]; // Global array to store answers
pthread_mutex_t lock; // Global mutex lock

typedef struct {
    double op1;
    double op2;
    char operator;
    int id;
} operation; // Struct to hold each operation

void *calculate(void *op) {
    operation *myOp = (operation *) op;
    int id = myOp->id;
    if (myOp->operator == '+') {
        ans[id] = myOp->op1 + myOp->op2;
    } else if (myOp->operator == '-') {
        ans[id] = myOp->op1 - myOp->op2;
    } else if (myOp->operator == '*') {
        ans[id] = myOp->op1 * myOp->op2;
    } else if (myOp->operator == '/') {
        if (myOp->op2 == 0) {
            printf("ERROR: Division by zero\n");
            ans[id] = -1;
        } else {
            ans[id] = myOp->op1 / myOp->op2;
        }
    } else if (myOp->operator == '^') {
        ans[id] = pow(myOp->op1, myOp->op2);
    } else {
        printf("ERROR: Invalid operator\n");
        ans[id] = -1;
    }
    pthread_mutex_lock(&lock);
    operationCounter++;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_OPERATIONS]; // Array of threads
    operation ops[MAX_OPERATIONS]; // Array of operations
    int numOps = 0; // Counter for number of operations
    char choice = 'y'; // Choice variable for user to enter more operations
    pthread_mutex_init(&lock, NULL); // Initialize mutex lock

    // Loop to get user input for operations
    while (choice == 'y' && numOps < MAX_OPERATIONS) {
        printf("Enter an operation (in the format of 'operand1 operator operand2'): ");
        scanf("%lf %c %lf", &ops[numOps].op1, &ops[numOps].operator, &ops[numOps].op2);
        ops[numOps].id = numOps;

        int rc = pthread_create(&threads[numOps], NULL, calculate, (void *) &ops[numOps]);
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }

        printf("Do you want to input another operation? (y/n): ");
        scanf(" %c", &choice);
        numOps++;
    }

    // Wait for all threads to finish execution
    while (operationCounter < numOps) {}
    pthread_mutex_destroy(&lock);

    // Print out the results
    printf("Answers:\n");
    for (int i = 0; i < numOps; i++) {
        printf("Operation %d: ", i+1);
        if (ans[i] == -1) {
            printf("Error\n");
        } else {
            printf("%.2lf\n", ans[i]);
        }
    }

    // Exit
    pthread_exit(NULL);
}