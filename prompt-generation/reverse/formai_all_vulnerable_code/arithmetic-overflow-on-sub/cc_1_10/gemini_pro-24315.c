//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ENCRYPT 1
#define DECRYPT 0

// Structure to hold the public key
typedef struct PublicKey
{
    int n;  // Modulus
    int e;  // Public exponent
} PublicKey;

// Structure to hold the private key
typedef struct PrivateKey
{
    int n;  // Modulus
    int d;  // Private exponent
} PrivateKey;

// Function to generate a random prime number
int generatePrimeNumber(int bits)
{
    int prime = 0;
    while (1)
    {
        prime = (rand() % (int)pow(2, bits)) + (int)pow(2, bits - 1);
        if (millerRabin(prime, 20))
        {
            break;
        }
    }
    return prime;
}

// Function to perform the Miller-Rabin primality test
int millerRabin(int n, int k)
{
    int s = 0, r = 0, i = 0, j = 0, a = 0;
    while (!(n & 1))
    {
        s++;
        n >>= 1;
    }
    r = n - 1;
    for (i = 0; i < k; i++)
    {
        a = rand() % (n - 2) + 1;
        j = exponentiation(a, r, n);
        if (j != 1 && j != n - 1)
        {
            for (j = 0; j < s - 1; j++)
            {
                j = exponentiation(j, 2, n);
                if (j == 1)
                {
                    return 0;
                }
                if (j == n - 1)
                {
                    break;
                }
            }
            if (j != n - 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Function to compute the exponentiation using the square-and-multiply algorithm
int exponentiation(int base, int exponent, int modulus)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

// Function to generate a public and private key pair
void generateKeyPair(PublicKey *publicKey, PrivateKey *privateKey)
{
    int p = 0, q = 0;
    p = generatePrimeNumber(512);
    q = generatePrimeNumber(512);
    publicKey->n = p * q;
    privateKey->n = publicKey->n;
    privateKey->d = 0;
    while (1)
    {
        privateKey->d = rand() % (publicKey->n - 2) + 1;
        if (gcd(publicKey->n, privateKey->d) == 1)
        {
            break;
        }
    }
    publicKey->e = exponentiation(privateKey->d, -1, publicKey->n);
}

// Function to compute the greatest common divisor using the Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Function to encrypt a message using the RSA algorithm
int encrypt(int message, PublicKey *publicKey)
{
    return exponentiation(message, publicKey->e, publicKey->n);
}

// Function to decrypt a message using the RSA algorithm
int decrypt(int ciphertext, PrivateKey *privateKey)
{
    return exponentiation(ciphertext, privateKey->d, privateKey->n);
}

// Main function
int main()
{
    int choice = 0, message = 0, ciphertext = 0;
    PublicKey publicKey;
    PrivateKey privateKey;
    printf("Enter 1 to generate a key pair, 2 to encrypt a message, or 3 to decrypt a message: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        generateKeyPair(&publicKey, &privateKey);
        printf("Public key: n = %d, e = %d\n", publicKey.n, publicKey.e);
        printf("Private key: n = %d, d = %d\n", privateKey.n, privateKey.d);
        break;
    case 2:
        printf("Enter the message to encrypt: ");
        scanf("%d", &message);
        ciphertext = encrypt(message, &publicKey);
        printf("Encrypted message: %d\n", ciphertext);
        break;
    case 3:
        printf("Enter the ciphertext to decrypt: ");
        scanf("%d", &ciphertext);
        message = decrypt(ciphertext, &privateKey);
        printf("Decrypted message: %d\n", message);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}