//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to calculate the greatest common divisor of two numbers */
int gcd(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Function to check if a number is prime or not */
int is_prime(int num)
{
    int i;
    for(i = 2; i <= (int)sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

/* Function to generate a random prime number between 2 and n */
int generate_prime(int n)
{
    int num;
    while(1)
    {
        num = rand() % (n - 2) + 2; /* generate a random number between 2 and n */
        if(is_prime(num))
        {
            return num;
        }
    }
}

/* Function to calculate the public and private keys */
void calculate_keys(int *e, int *d, int *n)
{
    int p, q, phi, gcd_val;

    /* generate two random prime numbers */
    p = generate_prime(1000);
    q = generate_prime(1000);
    
    /* calculate n = pq */
    *n = p * q;
    
    /* calculate phi(n) = (p-1)(q-1) */
    phi = (p - 1) * (q - 1);
    
    /* choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1 */
    *e = rand() % (phi - 2) + 2;
    gcd_val = gcd(*e, phi);
    while(gcd_val != 1)
    {
        *e = rand() % (phi - 2) + 2;
        gcd_val = gcd(*e, phi);
    }
    
    /* calculate d such that ed ≡ 1 (mod phi(n)) */
    int k = 1;
    while(1)
    {
        *d = (k * phi + 1) / (*e);
        if((*d) * (*e) == k * phi + 1)
        {
            return;
        }
        k++;
    }
}

int main()
{
    int e, d, n;
    calculate_keys(&e, &d, &n);
    printf("Public key: %d, %d\n", e, n);
    printf("Private key: %d, %d\n", d, n);
    return 0;
}