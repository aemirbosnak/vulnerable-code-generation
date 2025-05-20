//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

// Recursive addition function
int recursiveAddition(int x, int y) {
    // Base case: if y is 0, simply return x
    if (y == 0) {
        return x;
    }
    // Recursive case: add 1 to x and decrement y
    else {
        return recursiveAddition(x + 1, y - 1);
    }
}

// Recursive multiplication function
int recursiveMultiplication(int x, int y) {
    // Base case: if y is 0, simply return 0
    if (y == 0) {
        return 0;
    }
    // Recursive case: add x to the result of multiplying x and y-1
    else {
        return x + recursiveMultiplication(x, y - 1);
    }
}

//Recursive division function
int recursiveDivision(int x, int y) {
    // Base case: If y is 1, return x
    if(y == 1) {
        return x;
    }
    // Base case: if x is less than y, return 0
    if(x < y) {
        return 0;
    }
    // Recursive case: Subtract y from x and recursively divide the new result by y
    else {
        return 1 + recursiveDivision(x - y, y);
    }
}

int main() {
    int x, y;
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);

    printf("The sum of %d and %d is: %d\n", x, y, recursiveAddition(x, y));
    printf("The product of %d and %d is: %d\n", x, y, recursiveMultiplication(x, y));
    printf("The quotient of %d and %d is: %d\n", x, y, recursiveDivision(x, y));

    return 0;
}