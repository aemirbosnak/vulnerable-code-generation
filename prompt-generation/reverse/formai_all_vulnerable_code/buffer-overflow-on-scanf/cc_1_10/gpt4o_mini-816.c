//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;  // Attention! Numbers less than 2 are not prime. Trust no one!
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;  // Beware! Divisible by "i"! Your number is a traitor.
        }
    }
    return true;  // Your number has passed the test. It's a prime suspect!
}

// Function to calculate factorial
unsigned long long factorial(int num) {
    if (num < 0) {
        perror("Warning! Factorial of negative numbers is a hoax!"); 
        exit(EXIT_FAILURE);
    }
    if (num == 0) return 1;  // The zero factorial conspiracy!
    
    unsigned long long result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;  // Gradually increasing the suspense...
    }
    return result;  // The factorial reveals its dark secret!
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n < 0) {
        perror("Caution! Fibonacci does not accept the nefarious negative integers!");
        exit(EXIT_FAILURE);
    }
    if (n == 0) return 0; 
    if (n == 1) return 1; 
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;  // The hidden connection… Fibonacci's numbers are plotting together!
        a = b;
        b = c;
    }
    return c;  // The culmination of secret calculations!
}

// Main function
int main() {
    int choice;
    printf("Welcome to the Paranoid Math Exercise Program!\n");
    printf("Beware of mathematical truths that might disturb your peace of mind.\n");

    while (1) {
        printf("\nChoose an exercise:\n");
        printf("1. Check Prime\n");
        printf("2. Calculate Factorial\n");
        printf("3. Fibonacci Sequence\n");
        printf("4. Exit the program (but is it really safe?)\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num;
                printf("Enter a number to check if it's prime: ");
                scanf("%d", &num);
                if (is_prime(num)) {
                    printf("%d is a prime number. Trust it, for now...\n", num);
                } else {
                    printf("%d is not a prime number. It's been compromised!\n", num);
                }
                break;
            }
            case 2: {
                int num;
                printf("Enter a non-negative number to calculate its factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %llu. Does this reveal too much?\n", num, factorial(num));
                break;
            }
            case 3: {
                int n;
                printf("Enter the term (index) of the Fibonacci sequence you want: ");
                scanf("%d", &n);
                printf("The %dth term in the Fibonacci sequence is %d. Do not share this knowledge lightly!\n", n, fibonacci(n));
                break;
            }
            case 4:
                printf("Are you sure you want to exit? What if the program is watching? (y/n): ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("Exiting... but remember, the numbers are always watching!\n");
                    exit(0);
                } else {
                    printf("Staying in... you cannot escape the math!\n");
                }
                break;
            default:
                printf("Invalid choice! I am always watching out for invalid inputs...\n");
        }
    }
    return 0;  // Let's keep it safe for now.
}