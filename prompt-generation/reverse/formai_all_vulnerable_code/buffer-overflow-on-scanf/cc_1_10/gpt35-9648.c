//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate gcd of two numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to generate a random prime number
int generatePrimeNum()
{
    int n;
    printf("Enter a number (greater than 1) to find the closest prime number\n");
    scanf("%d", &n);

    // Find the closest prime number
    int isPrime = 0;
    while (!isPrime)
    {
        isPrime = 1;
        n++;

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
    }

    return n;
}

// Function to find a coprime of a number using gcd
int getCoprime(int phi)
{
    int e;
    while (1)
    {
        e = rand() % phi + 2;
        if (gcd(e, phi) == 1)
            return e;
    }
}

// Function to calculate modulo inverse of a number using extended euclidean algorithm
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// Encrypt plaintext message using public key
void encryptMessage(char *msg, int len, int e, int n)
{
    int *cipher = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
    {
        // Convert char to int using ASCII value
        int m = (int)msg[i];

        // Encrypt by taking the m to the power of e mod n
        cipher[i] = (int)fmod(pow(m, e), n);

        printf("%d ", cipher[i]);
    }
    printf("\n");

    // Free allocated memory
    free(cipher);
}

// Decrypt ciphertext message using private key
void decryptMessage(int *cipher, int len, int d, int n)
{
    char *msg = (char *)malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
    {
        // Decrypt by taking the cipher to the power of d mod n
        int m = (int)fmod(pow(cipher[i], d), n);

        // Convert int to char using ASCII value
        msg[i] = (char)m;

        printf("%c", msg[i]);
    }
    printf("\n");

    // Free allocated memory
    free(msg);
}

// main function
int main()
{
    printf("**** RSA PUBLIC KEY ALGORITHM ****\n");

    // Generate two random prime numbers
    int p = generatePrimeNum();
    int q = generatePrimeNum();

    // Calculate n
    int n = p * q;

    // Calculate phi
    int phi = (p - 1) * (q - 1);

    // Get a coprime of phi as the public key (e)
    int e = getCoprime(phi);

    // Calculate the private key (d)
    int d = modInverse(e, phi);

    // Print the public and private key
    printf("\nPublic key (e, n): (%d, %d)", e, n);
    printf("\nPrivate key (d, n): (%d, %d)\n\n", d, n);

    // Encrypt a message using the public key
    char msg[100];
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]%*c", msg);

    int len = strlen(msg);
    printf("\nEncrypted message: ");
    encryptMessage(msg, len, e, n);

    // Decrypt the ciphertext using the private key
    int cipher[100];
    for (int i = 0; i < len; i++)
        scanf("%d", &cipher[i]);

    printf("Decrypted message: ");
    decryptMessage(cipher, len, d, n);

    return 0;
}