//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>

// Function to print a string in reverse order
void reverse(char* str) {
    int i, j;
    char temp;

    for (i = strlen(str) - 1, j = 0; i >= j; i--, j++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Recursive function to calculate factorial of a number
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate the sum of digits in a number
int sumOfDigits(int num) {
    int sum = 0;

    while (num!= 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

// Recursive function to check if a string is a palindrome
int isPalindrome(char* str) {
    int i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i]!= str[j])
            return 0;
    }

    return 1;
}

// Main function
int main() {
    char str[100];
    int num, sum = 0, i;

    // Get input from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string and print it
    reverse(str);
    printf("\nReversed string: %s\n", str);

    // Calculate the factorial of a number
    printf("Enter a number: ");
    scanf("%d", &num);
    sum = factorial(num);
    printf("\nFactorial of %d is %d\n", num, sum);

    // Calculate the sum of digits in a number
    printf("Enter a number: ");
    scanf("%d", &num);
    sum = sumOfDigits(num);
    printf("\nSum of digits in %d is %d\n", num, sum);

    // Check if a string is a palindrome
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str))
        printf("\n%s is a palindrome\n", str);
    else
        printf("\n%s is not a palindrome\n", str);

    return 0;
}