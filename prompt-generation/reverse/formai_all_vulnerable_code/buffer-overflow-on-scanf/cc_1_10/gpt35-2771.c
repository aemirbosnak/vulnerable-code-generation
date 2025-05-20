//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function to generate prime numbers
int isPrime(int n)
{
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void generateKeys(int p, int q)
{
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (e < phi)
    {
        if (isPrime(e) && (e != p) && (e != q))
        {
            break;
        }
        e++;
    }

    int k = 2;
    int d = (1 + (k * phi)) / e;

    printf("Public Key : { %d, %d }\n", e, n);
    printf("Private Key : { %d, %d }\n", d, n);
}

int main()
{
    int p, q;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    if (!isPrime(p) || !isPrime(q))
    {
        printf("Invalid input! Both numbers should be prime.\n");
        exit(0);
    }

    generateKeys(p, q);

    return 0;
}