//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Welcome message
void welcome() {
    printf("Hello there, welcome to the wonderful world of recursion! Buckle up and get ready for a delightful adventure.\n\n");
}

// Goodbye message
void goodbye() {
    printf("\nThank you for playing with recursion! Hope you had a blast. Until next time, keep coding merrily!\n");
}

// A recursive function to calculate the factorial of a non-negative integer
int factorial(int n) {
    if (n == 0) {
        return 1;  // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1);  // Recursive case: calculate n! as n * (n-1)!
    }
}

// A recursive function to print a string backwards
void print_reverse(char *str) {
    if (*str) {  // Base case: when we reach the end of the string (null character)
        print_reverse(str + 1);  // Recursive case: print the rest of the string first
        putchar(*str);  // Then print the current character
    }
}

// A recursive function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {  // Base case: 1 and negative numbers are not prime
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {  // Check divisibility from 2 to n/2
        if (n % i == 0) {
            return 0;  // If divisible, not prime
        }
    }
    return 1;  // If no divisors found, prime
}

// A recursive function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0) {  // Base case: GCD(a, 0) = a
        return a;
    } else {
        return gcd(b, a % b);  // Recursive case: GCD(a, b) = GCD(b, a % b)
    }
}

// A recursive function to generate the Fibonacci sequence
void fibonacci(int n) {
    if (n <= 1) {  // Base case: first two Fibonacci numbers
        printf("%d ", n);
    } else {
        fibonacci(n - 1);  // Recursive case: calculate the previous Fibonacci number
        fibonacci(n - 2);  // Recursive case: calculate the Fibonacci number before that
        printf("%d ", n - 1 + n - 2);  // Print the sum of the previous two Fibonacci numbers
    }
}

int main() {
    welcome();

    // Calculate the factorial of a number
    int num;
    printf("Let's calculate the factorial of a number! Enter a non-negative integer: ");
    scanf("%d", &num);
    printf("The factorial of %d is: %d\n\n", num, factorial(num));

    // Print a string backwards
    char str[100];
    printf("Time to play with strings! Enter a string: ");
    scanf(" %[^\n]s", str);  // Read the string with spaces (to handle names with spaces)
    printf("Your string in reverse: ");
    print_reverse(str);
    printf("\n\n");

    // Check if a number is prime
    int number;
    printf("Let's check if a number is prime! Enter a number: ");
    scanf("%d", &number);
    if (is_prime(number)) {
        printf("%d is a prime number.\n\n", number);
    } else {
        printf("%d is not a prime number.\n\n", number);
    }

    // Find the greatest common divisor (GCD) of two numbers
    int a, b;
    printf("Now, let's find the greatest common divisor (GCD) of two numbers! Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("The GCD of %d and %d is: %d\n\n", a, b, gcd(a, b));

    // Generate the Fibonacci sequence
    int length;
    printf("Finally, let's generate the Fibonacci sequence! Enter the number of terms: ");
    scanf("%d", &length);
    printf("The Fibonacci sequence of length %d: ", length);
    fibonacci(length - 1);  // We print length-1 terms because the first two terms are always 0 and 1
    printf("\n\n");

    goodbye();

    return 0;
}