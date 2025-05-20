//Falcon-180B DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a random prime number
int generate_prime() {
    int num;
    while (true) {
        num = rand() % MAX_SIZE + 1;
        if (is_prime(num)) {
            return num;
        }
    }
}

int main() {
    int num1, num2;

    // Prompt user to input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Check if the input is valid
    if (num1 <= 0 || num2 <= 0) {
        printf("Error: Invalid input. Please enter positive integers.\n");
        return 1;
    }

    // Generate a random prime number between num1 and num2
    int prime = generate_prime();

    // Check if the prime number is within the given range
    if (prime < num1 || prime > num2) {
        printf("Error: Prime number not found in the given range.\n");
        return 1;
    }

    // Display the prime number
    printf("The prime number between %d and %d is: %d\n", num1, num2, prime);

    return 0;
}