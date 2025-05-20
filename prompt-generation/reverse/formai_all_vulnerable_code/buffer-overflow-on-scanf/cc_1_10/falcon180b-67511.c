//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_DIGITS 100
#define NUM_DIGITS 10
#define PRIME_NUMBER 31
#define BASE 10

// Function to generate prime number
int generatePrime() {
    int num = rand() % (BASE - 1) + 2;
    while (num % 2 == 0) {
        num++;
    }
    return num;
}

// Function to generate two large prime numbers
int generatePrimes() {
    int num1 = generatePrime();
    int num2 = generatePrime();
    while (num1 == num2) {
        num2 = generatePrime();
    }
    return num1, num2;
}

// Function to encrypt the message
void encrypt(int *message, int num1, int num2) {
    int i;
    for (i = 0; i < NUM_DIGITS; i++) {
        message[i] = (message[i] * num1) % num2;
    }
}

// Function to decrypt the message
void decrypt(int *message, int num1, int num2) {
    int i;
    for (i = 0; i < NUM_DIGITS; i++) {
        message[i] = (message[i] * num2) % num1;
    }
}

// Function to print the message
void printMessage(int *message, int numDigits) {
    int i;
    for (i = 0; i < numDigits; i++) {
        printf("%d", message[i]);
    }
}

int main() {
    int message[NUM_DIGITS];
    int num1, num2;
    int choice;

    // Get the message from the user
    printf("Enter the message (maximum %d digits): ", MAX_NUM_DIGITS);
    for (int i = 0; i < NUM_DIGITS; i++) {
        scanf("%d", &message[i]);
    }

    // Encrypt the message
    num1 = generatePrime();
    num2 = generatePrime();
    while (num1 == num2) {
        num2 = generatePrime();
    }
    encrypt(message, num1, num2);

    // Print the encrypted message
    printf("Encrypted message: ");
    printMessage(message, NUM_DIGITS);

    // Decrypt the message
    decrypt(message, num1, num2);

    // Print the decrypted message
    printf("\nDecrypted message: ");
    printMessage(message, NUM_DIGITS);

    return 0;
}