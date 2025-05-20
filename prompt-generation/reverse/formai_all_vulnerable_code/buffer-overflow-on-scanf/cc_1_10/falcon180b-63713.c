//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>

#define MAX 1000000

int isPrime(int num) {
    int i;
    for(i=2;i<=num/2;i++) {
        if(num%i==0) {
            return 0;
        }
    }
    return 1;
}

void sieve() {
    int i,j;
    int prime[MAX] = {1};
    for(i=2;i<=MAX;i++) {
        if(prime[i] == 1) {
            for(j=i*i;j<=MAX;j+=i) {
                prime[j] = 0;
            }
        }
    }
    printf("Prime numbers less than %d:\n", MAX);
    for(i=2;i<=MAX;i++) {
        if(prime[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Enter 1 to generate prime numbers using Sieve of Eratosthenes\n");
    printf("Enter 2 to check if a number is prime\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            sieve();
            break;
        case 2:
            printf("Enter a number: ");
            int num;
            scanf("%d", &num);
            if(isPrime(num)) {
                printf("%d is prime.\n", num);
            }
            else {
                printf("%d is not prime.\n", num);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}