//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

//Function to find the gcd of two numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

//Function to find the public key exponent
int publicExponent(int phi)
{
    int e = 2;
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    return e;
}

//Function to find the private key exponent
int privateExponent(int e, int phi)
{
    int d = 0;
    int x1 = 0;
    int x2 = 1;
    int q = 0;
    int r = 0;
    int temp = phi;

    //Extended Euclidean algorithm
    while (e > 0)
    {
        q = phi / e;
        r = phi % e;
        x1 = x2 - q * d;
        phi = e;
        e = r;
        x2 = d;
        d = x1;
    }

    //To make sure d is positive
    if (x2 < 0)
        x2 += temp;

    return x2;
}

//RSA encryption function
int encryption(int m, int e, int n)
{
    int c = 1;

    for (int i = 0; i < e; i++)
        c = (c * m) % n;

    return c;
}

//RSA decryption function
int decryption(int c, int d, int n)
{
    int m = 1;

    for (int i = 0; i < d; i++)
        m = (m * c) % n;

    return m;
}

int main()
{
    int p = 61;
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = publicExponent(phi);
    int d = privateExponent(e, phi);

    int message;
    printf("Enter the message to be encrypted: ");
    scanf("%d", &message);

    int encrypted = encryption(message, e, n);
    printf("The encrypted message is: %d\n", encrypted);

    int decrypted = decryption(encrypted, d, n);
    printf("The decrypted message is: %d\n", decrypted);

    return 0;
}