//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to swap two numbers without using a third variable
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse a given string
void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to check if a given number is prime
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int num1, num2;
    char str[100];

    // Taking input from user
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    printf("Enter a string: ");
    scanf("%s", str);

    // Swapping the values of num1 and num2
    swap(&num1, &num2);

    // Reversing the given string
    reverseString(str);

    // Checking if the second number is prime
    if (isPrime(num2))
        printf("%d is a prime number.\n", num2);
    else
        printf("%d is not a prime number.\n", num2);

    // Printing the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}