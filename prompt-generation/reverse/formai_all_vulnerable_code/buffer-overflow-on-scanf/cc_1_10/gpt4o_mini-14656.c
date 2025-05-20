//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 1000

void printWelcomeMessage() {
    printf("*******************************\n");
    printf("*     Retro Prime Number       *\n");
    printf("*     Generator Program        *\n");
    printf("*******************************\n\n");
}

void printPrimeNumbers(int limit) {
    printf("The prime numbers up to %d are:\n", limit);
    
    for (int num = 2; num <= limit; num++) {
        bool isPrime = true;
        
        for (int divisor = 2; divisor * divisor <= num; divisor++) {
            if (num % divisor == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

void printGoodbyeMessage() {
    printf("\nThank you for using the Retro Prime Number Generator!\n");
    printf("*******************************\n");
}

int main() {
    int userLimit;
    
    printWelcomeMessage();

    printf("Enter the upper limit for prime number generation (up to %d): ", MAX_NUM);
    scanf("%d", &userLimit);

    if (userLimit < 2 || userLimit > MAX_NUM) {
        printf("Invalid input! Please enter a number between 2 and %d.\n", MAX_NUM);
    } else {
        printPrimeNumbers(userLimit);
        printGoodbyeMessage();
    }
    
    return 0;
}