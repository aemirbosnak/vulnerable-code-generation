//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdbool.h>

bool isFibonacci(int num)
{
    int a = 0, b = 1, c = 0;
    
    while (c < num) {
        c = a + b;
        a = b;
        b = c;
    }
    
    if (c == num) {
        return true;
    }
    
    return false;
}

void printFibonacci(int n)
{
    int a = 0, b = 1, c = 0;
    
    printf("Fibonacci sequence up to %d:\n", n);
    
    while (c < n) {
        if (isFibonacci(c)) {
            printf("%d\t*\n", c); // Mark Fibonacci numbers
        } else {
            printf("%d\n", c);
        }
        c = a + b;
        a = b;
        b = c;
    }
    
    printf("\n");
}

int main(void)
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Invalid input\n");
        return 1;
    }
    printFibonacci(num);
    return 0;
}