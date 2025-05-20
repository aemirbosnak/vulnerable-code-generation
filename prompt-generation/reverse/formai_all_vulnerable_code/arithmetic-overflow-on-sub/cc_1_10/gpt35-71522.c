//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Function to find the GCD of two numbers
int gcd(int a, int b) {
    int temp;
    while(b!=0) {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for(i=2;i<num;i++) {
        if(num%i==0)
            return 0;
    }
    return 1;
}

int main() {
    int p, q, n, e=2, d, totient, i;

    // Select two prime numbers
    printf("Enter first prime number: ");
    scanf("%d",&p);
    while(!isPrime(p)) {
        printf("Invalid input! Please enter a prime number: ");
        scanf("%d", &p);
    }
    printf("Enter second prime number: ");
    scanf("%d",&q);
    while(!isPrime(q)) {
        printf("Invalid input! Please enter a prime number: ");
        scanf("%d", &q);
    }

    // Calculate n
    n=p*q;

    // Calculate totient
    totient=(p-1)*(q-1);

    // Select the public key e
    for(i=2;i<totient;i++) {
        if(gcd(i,totient)==1) {
            e=i;
            break;
        }
    }

    // Calculate the private key d
    i=1;
    while(1) {
        if((i*totient+1)%e==0) {
            d=(i*totient+1)/e;
            break;
        }
        i++;
    }

    printf("Public key is (%d,%d)\n",n,e);
    printf("Private key is (%d,%d)\n",n,d);

    return 0;
}