//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdbool.h>

void printAct();
void printScene();
bool isPrime(int number);
void generatePrimeNumbers(int limit);

int main() {
    printAct();
    printScene();
    
    int limit; 
    printf("Enter the upper limit for prime number generation, dear friend: ");
    scanf("%d", &limit);
    
    printf("Behold, the prime numbers fair, up to the limit you proclaimed: %d\n", limit);
    generatePrimeNumbers(limit);
    
    return 0;
}

void printAct() {
    printf("Act I: The Birth of Primes\n");
    printf("In the realm of numbers, noble and grand,\n");
    printf("Where evens and odds take their humble stand.\n\n");
}

void printScene() {
    printf("Scene I: The Quest for the Prime\n");
    printf("Shall we venture forth, with a valorous heart,\n");
    printf("To find numbers blessed, set apart?\n\n");
}

bool isPrime(int number) {
    if (number <= 1) { 
        return false; 
    }
    if (number <= 3) { 
        return true; 
    }
    if (number % 2 == 0 || number % 3 == 0) { 
        return false; 
    }
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false; 
        }
    }
    return true; 
}

void generatePrimeNumbers(int limit) {
    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\nAlas, the primes have danced before us, in a splendorous array!\n");
}