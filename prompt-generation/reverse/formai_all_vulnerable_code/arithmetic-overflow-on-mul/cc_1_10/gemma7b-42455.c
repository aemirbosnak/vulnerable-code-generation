//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 23

long powmod(long a, long b, long n)
{
    long result = 1;
    long exp = b;

    while (exp)
    {
        if (exp % 2 == 0)
        {
            result *= a * a % n;
            exp /= 2;
        }
        else
        {
            result *= a;
            exp--;
        }
    }

    return result;
}

long prim(long n)
{
    for (long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    long p = prim(MOD);
    long g = powmod(2, p - 2, MOD);

    long msg = 13;
    long enc_msg = powmod(g, msg, MOD);
    long dec_msg = powmod(g, enc_msg, MOD);

    printf("Original message: %ld\n", msg);
    printf("Encrypted message: %ld\n", enc_msg);
    printf("Decrypted message: %ld\n", dec_msg);

    return 0;
}