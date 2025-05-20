//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<math.h>

// Function to calculate gcd of two numbers
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}

// Function to check if a number is prime
int isprime(int a)
{
    int i;
    for (i = 2; i < a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate public key
int generatePublicKey(int a)
{
    int x;
    int count = 0;
    for (x = 2; x < a; x++)
    {
        if (gcd(x, a) == 1)
        {
            count++;
            if (count == 2)
                return x;
        }
    }
}

// Function to encrypt the message
int encrypt(int msg, int publicKey, int a)
{
    int i, key = 1;
    for (i = 0; i < publicKey; i++)
    {
        key = key * msg;
        key = key % a;
    }
    return key;
}

int main()
{
    int msg, p, q, n, e, d, c, m;
    printf("Enter the message: ");
    scanf("%d", &msg);
    printf("Enter two prime numbers(p and q): ");
    scanf("%d %d", &p, &q);
    n = p * q;
    int primeCheck = isprime(p);
    primeCheck *= isprime(q);
    if (!primeCheck)
    {
        printf("Invalid input. Both numbers should be prime.\n");
        return 0;
    }
    int phi = (p - 1) * (q - 1);
    e = generatePublicKey(phi);
    int gcdCheck = gcd(e, phi);
    if (gcdCheck != 1 || e == 1)
    {
        printf("Invalid input. Public key generation failed.\n");
        return 0;
    }
    c = encrypt(msg, e, n);
    printf("Encrypted message: %d", c);
    return 0;
}