//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100

typedef struct
{
    long int p;
    long int q;
    long int n;
    long int z;
    long int d;
    long int e;
}Key;

long int gcd(long int a, long int b)
{
    while(a!=b)
    {
        if(a>b)
        {
            return gcd(a-b, b);
        }
        else
        {
            return gcd(a, b-a);
        }
    }
    return a;
}

long int encrypt(long int M, long int e, long int n)
{
    long int c = 1;
    for(int i = 0; i < e; i++)
    {
        c = (c*M)%n;
    }
    return c;
}

long int decrypt(long int C, long int d, long int n)
{
    long int m = 1;
    for(int i = 0; i < d; i++)
    {
        m = (m*C)%n;
    }
    return m;
}

int isPrime(long int n)
{
    if(n<=1 || n==4)
    {
        return 0;
    }
    else if(n<=3)
    {
        return 1;
    }
    long int i = 2;
    while(i<=sqrt(n))
    {
        if(n%i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

long int generatePrime()
{
    long int n;
    time_t t;
    srand((unsigned) time(&t));
    n = rand() % MAX + 1;
    while(!isPrime(n))
    {
        n = rand() % MAX + 1;
    }
    return n;
}

void generateKeys(Key *k)
{
    k->p = generatePrime();
    k->q = generatePrime();
    k->n = k->p*k->q;
    k->z = (k->p-1)*(k->q-1);
    k->e = 2;
    while(k->e<k->z)
    {
        if(gcd(k->e, k->z) == 1)
        {
            break;
        }
        else
        {
            k->e++;
        }
    }
    k->d = 2;
    while(k->d<k->z)
    {
        if((k->e*k->d)%k->z == 1)
        {
            break;
        }
        else
        {
            k->d++;
        }
    }
}

int main()
{
    Key k;
    generateKeys(&k);
    long int M, C, d, n;
    printf("Enter the message you want to encrypt: ");
    scanf("%ld", &M);
    C = encrypt(M, k.e, k.n);
    printf("The encrypted message is: %ld\n", C);
    printf("Enter the message you want to decrypt: ");
    scanf("%ld", &C);
    M = decrypt(C, k.d, k.n);
    printf("The decrypted message is: %ld\n", M);
    return 0;
}