//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: mind-bending
#include <stdio.h>

void mysticPrint(int n);
void numSeeker(int start, int n, int sum);
int factorial(int n);
int fibonacci(int n);

void mysticPrint(int n) {
    if (n < 1) {
        printf("🌀 Enter a positive integer to harness the mystic powers of recursion! 🌀\n");
        return;
    }

    if (n == 1) {
        printf("The mystical number is: 1\n");
    } else {
        printf("Connecting to the mystic realm...\n");
        mysticPrint(n - 1);
        printf("Unveiling the mystical number: %d\n", n);
    }
}

void numSeeker(int start, int n, int sum) {
    if (start > n) {
        printf("🚪 The total sum of mystical numbers from 1 to %d is: %d\n", n, sum);
        return;
    } else {
        numSeeker(start + 1, n, sum + start);
    }
}

int factorial(int n) {
    if (n < 0) {
        printf("🌀 Factorial is not defined for negative numbers.\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n < 0) {
        printf("📜 The Fibonacci sequence does not cater to negativity.\n");
        return -1;
    }
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int choice, n;

    printf("🔮 Welcome to the Mystic Recursive Realm! 🔮\n");
    printf("Select your mystical pursuit:\n");
    printf("1. Unleash the Mystic Numbers (Print 1 to N)\n");
    printf("2. Seek the Sum of Mystic Numbers (1 to N)\n");
    printf("3. Calculate the Factorial of a Mystic Number (N!)\n");
    printf("4. Journey into Fibonacci Mysteries (Fibonacci of N)\n");
    printf("Choose your path (1-4): ");
    scanf("%d", &choice);

    // Situation: User selects a path
    switch(choice) {
        case 1:
            printf("🌌 Enter a mystical number N: ");
            scanf("%d", &n);
            mysticPrint(n);
            break;
        
        case 2:
            printf("🔑 Enter a mystical limit N for the sum: ");
            scanf("%d", &n);
            numSeeker(1, n, 0);
            break;
        
        case 3:
            printf("✨ Enter a mystical number N to find its factorial: ");
            scanf("%d", &n);
            int fact = factorial(n);
            if (fact != -1) {
                printf("✨ The factorial of %d is: %d\n", n, fact);
            }
            break;
        
        case 4:
            printf("💫 Enter a mystical position N to reveal Fibonacci: ");
            scanf("%d", &n);
            int fib = fibonacci(n);
            if (fib != -1) {
                printf("💖 The Fibonacci number at position %d is: %d\n", n, fib);
            }
            break;
        
        default:
            printf("❌ Invalid choice, cosmic traveler! Return to contemplate your choices.\n");
    }

    printf("🌠 Thank you for visiting the Mystic Recursive Realm! Return soon! 🌠\n");
    return 0;
}