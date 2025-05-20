//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

// Function to calculate factorial recursively
int factorial(int n) {
    if (n < 0) {
        printf("Surprised! Factorial of a negative number is undefined!\n");
        return -1; // Error case
    }
    if (n == 0) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

// Function to check if a number is prime recursively
int is_prime(int n, int i) {
    if (n <= 1) return 0; // 0 and 1 are not prime
    if (i * i > n) return 1; // No divisors found
    if (n % i == 0) {
        printf("Surprise! %d is not a prime number because it is divisible by %d.\n", n, i);
        return 0; // Found a divisor
    }
    return is_prime(n, i + 1); // Check next divisor
}

// Function to print Fibonacci series recursively
void fibonacci(int n1, int n2, int count, int max_count) {
    if (count == max_count) return; // Base case
    printf("%d ", n1);
    fibonacci(n2, n1 + n2, count + 1, max_count); // Recursive case
}

// Function to calculate the greatest common divisor (GCD) recursively
int gcd(int a, int b) {
    if (b == 0) {
        printf("Surprise! GCD is %d\n", a);
        return a; // Base case
    }
    return gcd(b, a % b); // Recursive case
}

// Function to reverse a string recursively
void reverse_string(const char* str, int index, int len) {
    if (index >= len) return; // Base case
    reverse_string(str, index + 1, len); // Recursive case
    putchar(str[index]); // Print when unwinding
}

int main() {
    int choice, num, factorial_result;
    
    printf("Welcome to the Surprised Recursive Program!\n");
    printf("Choose an option:\n");
    printf("1: Calculate Factorial\n");
    printf("2: Check Prime\n");
    printf("3: Generate Fibonacci Series\n");
    printf("4: Calculate GCD\n");
    printf("5: Reverse a String\n");
    printf("6: Exit\n");
    
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input a number for factorial calculation: ");
                scanf("%d", &num);
                factorial_result = factorial(num);
                if (factorial_result != -1) {
                    printf("Factorial of %d is %d.\n", num, factorial_result);
                }
                break;
            case 2:
                printf("Input a number to check if it is prime: ");
                scanf("%d", &num);
                if (is_prime(num, 2)) {
                    printf("Surprise! %d is a prime number!\n", num);
                }
                break;
            case 3:
                printf("Generating Fibonacci Series (10 numbers): ");
                fibonacci(0, 1, 0, 10); // Start with 0 and 1, print 10 numbers
                printf("\n");
                break;
            case 4:
                {
                    int a, b;
                    printf("Input two numbers to find their GCD: ");
                    scanf("%d %d", &a, &b);
                    gcd(a, b);
                }
                break;
            case 5:
                {
                    char str[100];
                    printf("Input a string to reverse: ");
                    scanf("%s", str);
                    printf("Reversed String: ");
                    reverse_string(str, 0, strlen(str));
                    printf("\n");
                }
                break;
            case 6:
                printf("Exiting the Surprised Program! Bye!\n");
                return 0;
            default:
                printf("Surprise! Invalid choice! Please try again.\n");
        }
    }

    return 0;
}