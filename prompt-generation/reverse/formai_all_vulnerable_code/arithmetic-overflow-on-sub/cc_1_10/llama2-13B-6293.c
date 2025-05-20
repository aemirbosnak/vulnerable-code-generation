//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 100
#define MIN_NUM 1

// Function to calculate the factorial of a given number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the nth fibonacci number
int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num, n;
    float average, sum, difference;

    // Question 1: Write a program to calculate the factorial of 5
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d\n", num, factorial(num));

    // Question 2: Write a program to calculate the nth Fibonacci number
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is %d\n", n, fibonacci(n));

    // Question 3: Write a program to find the average of the first n natural numbers
    printf("Enter a number: ");
    scanf("%d", &num);
    sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
    }
    average = sum / num;
    printf("The average of the first %d natural numbers is %f\n", num, average);

    // Question 4: Write a program to find the difference between the sum of the first n natural numbers and the sum of the first n odd natural numbers
    printf("Enter a number: ");
    scanf("%d", &num);
    sum = 0;
    for (int i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }
    difference = sum - (sum / 2);
    printf("The difference between the sum of the first %d natural numbers and the sum of the first %d odd natural numbers is %f\n", num, num / 2, difference);

    return 0;
}