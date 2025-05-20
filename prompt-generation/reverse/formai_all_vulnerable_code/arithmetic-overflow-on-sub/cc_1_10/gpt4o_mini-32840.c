//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct FibonacciNode {
    int value;
    struct FibonacciNode* next;
} FibonacciNode;

// Function to create a new FibonacciNode
FibonacciNode* createNode(int value) {
    FibonacciNode* newNode = (FibonacciNode*) malloc(sizeof(FibonacciNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to generate Fibonacci numbers and build linked list
FibonacciNode* generateFibonacci(int n, FibonacciNode* head) {
    if (n < 0) {
        return head;  // Base case: Return head if n is negative
    }
    if (n == 0) {
        head = createNode(0);
        head->next = generateFibonacci(n - 1, head->next);
        return head;
    }
    if (n == 1) {
        head = createNode(1);
        head->next = generateFibonacci(n - 1, head->next);
        return head;
    }

    // Recursive call
    head = generateFibonacci(n - 1, head);
    int fib_n_minus_1 = head ? head->value : 0;
    int fib_n_minus_2 = (head && head->next) ? head->next->value : 0;
    int fib_n = fib_n_minus_1 + fib_n_minus_2;

    // Create node for current Fibonacci number
    FibonacciNode* newNode = createNode(fib_n);
    newNode->next = head;
    return newNode;
}

// Function to print the linked list of Fibonacci numbers
void printFibonacciList(FibonacciNode* head) {
    FibonacciNode* current = head;
    printf("Fibonacci Sequence: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Function to calculate the sum of Fibonacci numbers in the linked list
int sumFibonacci(FibonacciNode* head) {
    int sum = 0;
    FibonacciNode* current = head;
    while (current) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

// Function to free the linked list memory
void freeFibonacciList(FibonacciNode* head) {
    FibonacciNode* current = head;
    FibonacciNode* nextNode;
    while (current) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    FibonacciNode* fibList = generateFibonacci(n - 1, NULL);
    printFibonacciList(fibList);
   
    int sum = sumFibonacci(fibList);
    printf("Sum of Fibonacci sequence: %d\n", sum);
    
    freeFibonacciList(fibList);
    return 0;
}