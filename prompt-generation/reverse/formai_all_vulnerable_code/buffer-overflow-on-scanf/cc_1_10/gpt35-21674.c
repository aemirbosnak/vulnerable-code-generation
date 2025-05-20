//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>

/*
 * Utility function to determine if a number is prime
 */
int is_prime(int n) {
    int i;
    
    // case when n is equal to 1, it is not a prime
    if(n == 1) {
        return 0;
    }
    
    // check if n is divisible by any number other than 1 and itself
    for(i=2;i<=n/2;i++) {
        if(n%i == 0) {
            return 0;
        }
    }
    
    return 1;
}

/*
 * Function to generate the first n prime numbers and store them in an array
 */
void generate_primes(int n, int* primes) {
    int count = 0;
    int i=2;
    
    // keep generating primes until we have found n of them
    while(count < n) {
        if(is_prime(i)) {
            primes[count] = i;
            count++;
        }
        i++;
    }
}

int main() {
    int n;
    int primes[50];
    int i;
    
    printf("Enter the number of primes you want to generate (maximum 50): ");
    scanf("%d", &n);
    
    // make sure n is not larger than 50
    if(n > 50) {
        printf("Maximum allowed value is 50. Using 50 instead.\n");
        n = 50;
    }
    
    // generate the first n primes and store them in the primes array
    generate_primes(n, primes);
    
    // print the primes array
    printf("The first %d prime numbers are:\n", n);
    for(i=0;i<n;i++) {
        printf("%d ", primes[i]);
    }
    
    printf("\n");
    
    return 0;
}