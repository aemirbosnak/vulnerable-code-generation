//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 1000000000
#define TRUE 1
#define FALSE 0

// Function to check if a number is prime
int is_prime(int n) {
    int i, j;
    for(i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

// Function to generate prime numbers
void generate_primes(int num) {
    int i, j, count = 0;
    int *primes = (int*)malloc(num*sizeof(int));
    for(i=2; count<num; i++) {
        if(is_prime(i)) {
            primes[count] = i;
            count++;
        }
    }
    printf("\n%d prime numbers generated:\n", count);
    for(i=0; i<count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    free(primes);
}

// Function to generate random prime numbers
void generate_random_primes(int num) {
    int i, j, count = 0;
    int *primes = (int*)malloc(num*sizeof(int));
    srand(time(NULL));
    for(i=2; count<num; i++) {
        if(is_prime(i)) {
            primes[count] = i;
            count++;
        }
    }
    printf("\n%d random prime numbers generated:\n", count);
    for(i=0; i<count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    free(primes);
}

int main() {
    int choice;
    printf("\nEnter 1 to generate %d prime numbers\n", MAX_NUM);
    printf("Enter 2 to generate %d random prime numbers\n", MAX_NUM);
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            generate_primes(MAX_NUM);
            break;
        case 2:
            generate_random_primes(MAX_NUM);
            break;
        default:
            printf("\nInvalid choice!\n");
    }
    return 0;
}