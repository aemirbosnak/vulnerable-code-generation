//FormAI DATASET v1.0 Category: Educational ; Style: cheerful
// Happy Learning with C!

#include<stdio.h>

int main() {
    printf("Welcome to this amazing program in C!\n");
    printf("Let's learn something new today, shall we?\n");

    // Initializing variables
    int num1, num2, sum;

    // Taking input from user
    printf("Please enter the first number: ");
    scanf("%d", &num1);
    printf("Please enter the second number: ");
    scanf("%d", &num2);

    // Adding the numbers
    sum = num1 + num2;

    // Printing the result
    printf("\nThe sum of %d and %d is %d. Happy Learning!\n", num1, num2, sum);

    // Happy Learning with loops
    int i;
    printf("Let's print the numbers from 1 to 10 using a loop.\n");
    for(i=1; i<=10; i++) {
        printf("%d ", i);
    }
    printf("Don't you feel happy already?\n");

    // Happy Learning with arrays
    int arr[5] = {1, 2, 3, 4, 5};
    int j;
    printf("Let's print the contents of an array using a loop.\n");
    for(j=0; j<5; j++) {
        printf("%d ", arr[j]);
    }
    printf("Learning is so much fun!\n");

    // Happy Learning with functions
    int x = 5, y = 2;
    int result = addNumbers(x, y);
    printf("The result of adding %d and %d using a function is %d. Keep smiling!\n", x, y, result);

    return 0;
}

// Function to add two numbers
int addNumbers(int a, int b) {
    return a + b;
}