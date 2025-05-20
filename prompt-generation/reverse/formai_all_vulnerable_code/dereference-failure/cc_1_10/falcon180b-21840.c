//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 100

// Function to push an integer onto the stack
void push(int* stack, int* top, int value) {
    if (*top >= STACK_SIZE - 1) {
        printf("Stack overflow. Cannot push %d.\n", value);
        exit(1);
    }
    *(stack + (*top)) = value;
    (*top)++;
}

// Function to pop an integer from the stack
int pop(int* stack, int* top) {
    if (*top <= 0) {
        printf("Stack underflow. No element to pop.\n");
        exit(1);
    }
    int value = *(stack + (*top - 1));
    (*top)--;
    return value;
}

// Function to display the elements in the stack
void display(int* stack, int top) {
    printf("Stack elements are: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", *(stack + i));
    }
    printf("\n");
}

// Function to move n disks from source to destination using the stack
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    int stack[STACK_SIZE];
    int top = -1;

    push(stack, &top, n);
    printf("Moving %d disks from %c to %c using %c\n", n, source, destination, auxiliary);

    while (top >= 0) {
        int currentDisk = pop(stack, &top);

        if (top == 0) {
            printf("Moved disk %d from %c to %c\n", currentDisk, source, destination);
        } else {
            push(stack, &top, currentDisk);
        }
    }
}

// Function to get user input for the number of disks
int getNumberOfDisks() {
    int numDisks;

    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    return numDisks;
}

int main() {
    srand(time(NULL));

    int numDisks = getNumberOfDisks();
    char source = 'A';
    char destination = 'C';
    char auxiliary = 'B';

    printf("Tower of Hanoi problem with %d disks\n", numDisks);
    towerOfHanoi(numDisks, source, destination, auxiliary);

    return 0;
}