//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

// Recursive function to calculate the factorial of a number
int factorial(int num) {
    if (num == 1 || num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

// Recursive function to print Fibonacci sequence
void fibonacci(int num, int i) {
    if (i == 0) {
        printf("%d ", i);
        fibonacci(num, i + 1);
    }
    else if (i == num) {
        printf("%d ", i);
    }
    else {
        int sum = 0;
        int prev1 = 0, prev2 = 1;
        for (int j = 1; j < i; j++) {
            sum = prev1 + prev2;
            prev1 = prev2;
            prev2 = sum;
        }
        printf("%d ", sum);
        fibonacci(num, i + 1);
    }
}

// Recursive function to check if a number is a palindrome
int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    else if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    }
    else {
        return 0;
    }
}

int main() {
    int n, choice;
    char str[100];

    printf("Enter choice:\n");
    printf("1. Calculate factorial\n");
    printf("2. Print Fibonacci sequence\n");
    printf("3. Check if a string is palindrome\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("Enter a number: ");
        scanf("%d", &n);
        printf("%d! = %d", n, factorial(n));
        break;

    case 2:
        printf("Enter the number of terms: ");
        scanf("%d", &n);
        fibonacci(n, 0);
        break;

    case 3:
        printf("Enter a string: ");
        scanf("%s", str);
        if (isPalindrome(str, 0, strlen(str) - 1)) {
            printf("%s is a palindrome", str);
        }
        else {
            printf("%s is not a palindrome", str);
        }
        break;

    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}