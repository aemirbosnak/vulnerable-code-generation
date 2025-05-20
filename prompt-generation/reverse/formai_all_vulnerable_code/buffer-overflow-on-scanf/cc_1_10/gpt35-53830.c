//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<stdbool.h>

// Function to check if a number is prime or not
bool isPrime(int n) 
{
    if (n <= 1) 
        return false;
    for (int i = 2; i < sqrt(n); i++) 
    {
        if (n % i == 0) 
            return false;
    }
    return true;
}

// Function to find gcd of two numbers
int gcd(int a, int b) 
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to generate public key
int generatePublicKey(int q, int *e) 
{
    int n, a; 
    // Choose a random prime number between 1 and q-1
    do {
        a = rand() % (q-1) + 1;
    } while (gcd(q, a) != 1);
    // Calculate n = (q-1)*a mod q
    n = ((q-1)*a) % q;
    *e = a;
    return n;
}

// Function to encrypt message using public key
int encryptMessage(int m, int e, int n) 
{
    int c = pow(m, e);
    return c % n;
}

// Main function
int main() 
{
    int q, m, e = 0, n, c;
    printf("Enter a prime number: ");
    scanf("%d", &q);
    while (!isPrime(q))
    {
        printf("Please enter a prime number: ");
        scanf("%d", &q);
    }
    n = generatePublicKey(q, &e);
    printf("Public key is (%d, %d)\n", e, n);
    printf("Enter message to encrypt: ");
    scanf("%d", &m);
    c = encryptMessage(m, e, n);
    printf("Encrypted message is %d\n", c);
    return 0; 
}