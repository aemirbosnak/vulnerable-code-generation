//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
/* Welcome to the "Cheerful Cryptography" program! */
/* This program implements a public-key encryption algorithm using C */

#include <stdio.h>
#include <stdlib.h>

/* Function to get user input */
int getUserInput(void)
{
    int input;
    printf("Enter a number: ");
    scanf("%d", &input);
    return input;
}

/* Function to calculate greatest common divisor */
int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* Main Function */
int main(void)
{
    printf("Welcome to Celebrate Cryptography!\n");

    /* Generate Two Random Prime Numbers */
    int p = 3;
    int q = 11;

    /* Calculate n and Euler Totient */
    int n = p * q;
    int totient = (p - 1) * (q - 1);

    /* Choose an Encryption Key (e) */
    int e = 3;
    while (gcd(e, totient) != 1)
    {
        e++;
    }

    /* Calculate Decryption Key (d) */
    int d = 0;
    int k = 1;
    while (d == 0)
    {
        int temp = (totient * k) + 1;
        if (temp % e == 0)
        {
            d = temp / e;
        }
        k++;
    }

    /* Display Public and Private Keys */
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    /* Get User Input */
    int input = getUserInput();

    /* Encrypt User Input */
    int cipher = 1;
    for (int i = 0; i < e; i++)
    {
        cipher *= input;
        cipher %= n;
    }
    printf("Encrypted Message: %d\n", cipher);

    /* Decrypt Message */
    int message = 1;
    for (int i = 0; i < d; i++)
    {
        message *= cipher;
        message %= n;
    }
    printf("Decrypted Message: %d\n", message);

    printf("Thanks for using Cheerful Cryptography!\n");

    return 0;
}