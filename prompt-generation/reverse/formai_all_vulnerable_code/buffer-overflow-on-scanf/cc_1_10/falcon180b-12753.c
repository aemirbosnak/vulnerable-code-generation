//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX 10

int arr[MAX];
int top = -1;
int choice;

void push(int val) {
    if (top >= MAX - 1) {
        printf("\nStack Overflow");
        exit(0);
    }
    else {
        top++;
        arr[++top] = val;
    }
}

int pop() {
    if (top < 0) {
        printf("\nStack Underflow");
        exit(0);
    }
    else {
        int val = arr[top--];
        return val;
    }
}

void display() {
    if (top >= 0) {
        printf("\nElements in the stack are:");
        for (int i = top; i >= 0; i--) {
            printf("\n%d", arr[i]);
        }
    }
    else {
        printf("\nStack is empty");
    }
}

int main() {
    int n, val;

    printf("\nEnter the number of elements you want to push onto the stack: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        val = rand() % 100;
        push(val);
    }

    printf("\nThe elements in the stack are:");
    display();

    return 0;
}