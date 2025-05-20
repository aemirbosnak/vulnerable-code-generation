//FormAI DATASET v1.0 Category: Educational ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// Prototype for the functions
void displayMenu();
void fibonacciSeries(int);
void primeNumbers(int);
void power(int, int);

int main() {

    // Variables to store user input
    int choice, num;

    // Loop to display the menu until the user exits
    do {

        // Displays the menu to the user
        displayMenu();

        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);

        // Switch case to perform the selected operation
        switch(choice) {

            case 1:
                printf("\nEnter the value upto which the Fibonacci series should be generated: ");
                scanf("%d", &num);
                fibonacciSeries(num);
                break;
            case 2:
                printf("\nEnter the value upto which the prime numbers should be generated: ");
                scanf("%d", &num);
                primeNumbers(num);
                break;
            case 3:
                printf("\nEnter the base and exponent value separated by space: ");
                int base, exponent;
                scanf("%d %d", &base, &exponent);
                power(base, exponent);
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please enter a valid choice.\n");
        }

    } while(1);

    return 0;
}

void displayMenu() {
    // Displaying the menu to the user
    printf("\n");
    printf("************************************************\n");
    printf("***              MENU for Program            ***\n");
    printf("************************************************\n");
    printf("*** 1. Generate Fibonacci Series             ***\n");
    printf("*** 2. Generate all Prime Numbers upto N     ***\n");
    printf("*** 3. Calculate Base raised to Exponent     ***\n");
    printf("*** 4. Exit Program                          ***\n");
    printf("************************************************\n");
}

void fibonacciSeries(int limit) {
    // Variables to store the fibonacci series
    int prev = 0, current = 1, next;

    // Output the first two numbers in the series
    printf("\nFibonacci series: %d, %d, ", prev, current);

    // Generate the rest of the numbers in the series
    for(int i = 2; i < limit; i++) {
        next = prev + current;
        printf("%d, ", next);
        prev = current;
        current = next;
    }
}

void primeNumbers(int limit) {
    // Variables to check if a number is prime
    int isPrime;

    // Generate and output prime numbers up to the limit
    printf("\nPrime numbers upto %d are: ", limit);

    for(int i = 2; i <= limit; i++) {
        isPrime = 1;

        for(int j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime == 1) {
            printf("%d, ", i);
        }
    }
}

void power(int base, int exponent) {
    // Compute base raised to exponent
    int result = 1;

    for(int i = 0; i < exponent; i++) {
        result *= base;
    }

    // Output the result to the user
    printf("\n%d raised to power %d = %d\n", base, exponent, result);
}