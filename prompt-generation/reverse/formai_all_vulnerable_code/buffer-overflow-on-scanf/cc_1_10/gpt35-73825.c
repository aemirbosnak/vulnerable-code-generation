//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_prime(int num) {
    if(num<2)
        return 0;
    
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i == 0)
            return 0;
    }
    return 1;
}

int* generate_primes(int n) {
    int* primes = (int*)malloc(n*sizeof(int));         // allocate memory for n prime numbers
    if(primes == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    int count = 0;                                      // count of prime numbers found
    int num = 2;                                         // start with first prime number
    
    while(count<n) {
        if(is_prime(num)) {
            primes[count] = num;                        // store prime number in list
            count++;                                     // increment prime count
        }
        num++;                                          // check next number for primality
    }
    return primes;
}

int main() {
    int n;

    printf("Enter the number of primes required: ");
    scanf("%d", &n);

    int* primes = generate_primes(n);                    // generate n prime numbers
    printf("The first %d prime numbers are:\n", n);
    for(int i=0; i<n; i++) {
        printf("%d ", primes[i]);                        // print the list of prime numbers
    }
    printf("\n");

    free(primes);                                        // free the memory allocated
    return 0;
}