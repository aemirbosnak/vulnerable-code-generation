//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

//function to check if a number is prime
int is_prime(int num)
{
    int i;
    for(i = 2; i <= sqrt(num); i++)
    {
        if(num%i == 0)
            return FALSE;
    }
    return TRUE;
}

//function to generate random prime number
int generate_prime()
{
    int num;
    srand(time(NULL));
    do
    {
        num = rand()%100;
    }while(!is_prime(num));
    return num;
}

//function to calculate greatest common divisor
int gcd(int a, int b)
{
    int gcd;
    for(int i = 1; i <= a && i <= b; i++)
    {
        if(a%i == 0 && b%i == 0)
            gcd = i;
    }
    return gcd;
}

//function to generate public key
int generate_public_key(int p, int q)
{
    int n = p*q;
    int phi = (p-1)*(q-1);
    int e;
    //e must be co-prime with phi and less than phi
    srand(time(NULL));
    do
    {
        e = rand()%phi;
    }while(gcd(e,phi) != 1);
    return e;
}

//function to generate private key
int generate_private_key(int p, int q, int e)
{
    int n = p*q;
    int phi = (p-1)*(q-1);
    int d, i = 1;
    while(TRUE)
    {
        if(((i*phi)+1)%e == 0)
        {
            d = ((i*phi)+1)/e;
            break;
        }
        i++;
    }
    return d;
}

int main()
{
    int p, q, n, phi, e, d;
    printf("Public Key Algorithm\n\n");
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);
    n = p*q;
    phi = (p-1)*(q-1);
    printf("\nCalculating public key and private key...\n");
    printf("Generating random prime numbers...\n");
    printf("p = %d\nq = %d\n", p, q);
    printf("\nGenerating public key...\n");
    e = generate_public_key(p, q);
    printf("e = %d\n", e);
    printf("\nGenerating private key...\n");
    d = generate_private_key(p, q, e);
    printf("d = %d\n\n", d);
    printf("Public key is (%d, %d)\n", e, n);
    printf("Private key is (%d, %d)\n", d, n);
    return 0;
}