//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

// Function to calculate the factorial of a number using recursion
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case
    }
    return n * factorial(n - 1); // Recursive case
}

// Function to find the greatest common divisor (GCD) using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case
    }
    return gcd(b, a % b); // Recursive case
}

// Function to compute Fibonacci series up to n terms using recursion
void fibonacci(int n, int a, int b) {
    if (n > 0) {
        printf("%d ", a); // Print current Fibonacci number
        fibonacci(n - 1, b, a + b); // Recursive call to get next Fibonacci number
    }
}

// Function to reverse a string using recursion
void reverseString(char *str, int start, int end) {
    if (start < end) {
        char temp = str[start]; // Temporarily store char at start
        str[start] = str[end]; // Swap characters
        str[end] = temp; // Swap characters
        reverseString(str, start + 1, end - 1); // Recursive call for next pair
    }
}

// Function to calculate the power of a number using recursion
double power(double base, int exp) {
    if (exp == 0) {
        return 1; // Base case
    } else if (exp < 0) {
        return 1 / power(base, -exp); // Handling negative exponent
    }
    return base * power(base, exp - 1); // Recursive case
}

// Function to print all permutations of a string using recursion
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str); // Print the permutation
    } else {
        for (int i = l; i <= r; i++) {
            // Swap to create a new permutation
            char temp = str[l];
            str[l] = str[i];
            str[i] = temp;

            // Recursion for the next index
            permute(str, l + 1, r);

            // Backtrack (undo the swap)
            temp = str[l];
            str[l] = str[i];
            str[i] = temp;
        }
    }
}

int main() {
    int choice, n, a, b;
    double base;
    char str[100];

    printf("Choose an operation:\n");
    printf("1. Factorial\n");
    printf("2. GCD\n");
    printf("3. Fibonacci Series\n");
    printf("4. Reverse String\n");
    printf("5. Power Calculation\n");
    printf("6. Permutations of a String\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &n);
            printf("Factorial of %d is %llu\n", n, factorial(n));
            break;
        case 2:
            printf("Enter two integers to find GCD: ");
            scanf("%d %d", &a, &b);
            printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
            break;
        case 3:
            printf("Enter number of terms for Fibonacci series: ");
            scanf("%d", &n);
            printf("Fibonacci series: ");
            fibonacci(n, 0, 1);
            printf("\n");
            break;
        case 4:
            printf("Enter a string to reverse: ");
            scanf("%s", str);
            reverseString(str, 0, strlen(str) - 1);
            printf("Reversed string: %s\n", str);
            break;
        case 5:
            printf("Enter base and exponent: ");
            scanf("%lf %d", &base, &n);
            printf("%.2lf^%d = %.2lf\n", base, n, power(base, n));
            break;
        case 6:
            printf("Enter a string to find permutations: ");
            scanf("%s", str);
            printf("Permutations of the string:\n");
            permute(str, 0, strlen(str) - 1);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}