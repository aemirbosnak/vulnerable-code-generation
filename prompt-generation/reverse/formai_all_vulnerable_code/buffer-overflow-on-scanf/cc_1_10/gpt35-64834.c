//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// This program generates a public-key pair using RSA algorithm.

// Function to calculate GCD of two numbers
int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate totient of a number using its prime factors
int phi(int n, int *p, int len){
    int i, ans = n;
    for(i = 0; i < len; i++){
        if(n % *(p + i) == 0){
            ans /= *(p + i);
            ans *= (*(p + i) - 1);
        }
    }
    return ans;
}

// Function to check if a number is prime
int isPrime(int n){
    int i;
    for(i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main(){
    int p, q, n, e, d, tot, i, primes[100], prime_count = 0;
    printf("Enter two prime numbers:\n");
    scanf("%d %d", &p, &q);
    if(!isPrime(p) || !isPrime(q)){
        printf("Both numbers must be prime!\n");
        exit(1);
    }
    n = p * q;
    tot = phi(n, primes, prime_count);
    printf("Possible values for e:\n");
    for(i = 2; i < tot; i++){
        if(gcd(i, tot) == 1){
            primes[prime_count] = i;
            prime_count++;
            printf("%d ", i);
        }
    }
    printf("\nEnter a value for e: ");
    scanf("%d", &e);
    if(gcd(e, tot) != 1){
        printf("Invalid value for e!\n");
        exit(1);
    }
    for(i = 1; i < tot; i++){
        int x = 1 + i * tot;
        if(x % e == 0){
            d = x / e;
            break;
        }
    }
    printf("Public-key pair: (%d, %d)\n", n, e);
    printf("Private-key pair: (%d, %d)\n", n, d);
    return 0;
}