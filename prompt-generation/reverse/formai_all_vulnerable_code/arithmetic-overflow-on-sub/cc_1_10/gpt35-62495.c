//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number is prime
int isPrime(int num){
    if(num == 2 || num == 3){
        return 1;
    }
    if(num == 1 || num % 2 == 0){
        return 0;
    }
    for(int i = 3; i * i <= num; i += 2){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int i, numPrimes, primeCount = 0;
    int min, max, range;

    // Seed the random number generator
    srand(time(NULL));

    printf("Enter the minimum value for range: ");
    scanf("%d", &min);
    printf("Enter the maximum value for range: ");
    scanf("%d", &max);

    range = max - min + 1;

    printf("\nCalculating prime numbers in range [%d,%d]...\n\n", min, max);

    // Allocate array for storing prime numbers
    int *primeArray = malloc(range * sizeof(int));

    // Generate random numbers and check if they are prime
    for(i = 0; i < range; i++){
        int randNum = rand() % range + min;
        if(isPrime(randNum)){
            primeArray[primeCount] = randNum;
            primeCount++;
        }
    }

    // Print out the prime numbers found
    printf("Found %d prime numbers in range [%d,%d]:\n\n", primeCount, min, max);
    for(i = 0; i < primeCount; i++){
        printf("%d ", primeArray[i]);
    }
    printf("\n\n");

    // Free memory used by prime array
    free(primeArray);

    return 0;
}