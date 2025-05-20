//Gemma-7B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRIME 1000

int prime_sieve(int n);
int gen_prime_key(int n);
int encrypt(int n, int key);
int decrypt(int n, int key);

int main()
{
    int n, key, choice;

    printf("Welcome to the Quantum Cryptograph Machine!\n");
    printf("Please select an option:\n");
    printf("1. Generate Prime Key\n");
    printf("2. Encrypt Message\n");
    printf("3. Decrypt Message\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the desired key length: ");
            scanf("%d", &n);
            key = gen_prime_key(n);
            printf("Your prime key is: %d\n", key);
            break;
        case 2:
            printf("Enter the message: ");
            scanf("%s", n);
            printf("Enter the key: ");
            scanf("%d", &key);
            int encrypted_message = encrypt(n, key);
            printf("Your encrypted message is: %d\n", encrypted_message);
            break;
        case 3:
            printf("Enter the encrypted message: ");
            scanf("%d", &n);
            printf("Enter the key: ");
            scanf("%d", &key);
            int decrypted_message = decrypt(n, key);
            printf("Your decrypted message is: %s\n", decrypted_message);
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}

int prime_sieve(int n)
{
    int primes[n];
    primes[0] = primes[1] = 1;

    for (int i = 2; i < n; i++)
    {
        for (int j = i; j <= n && primes[j] == 0; j++)
        {
            primes[j] = 1;
        }
    }

    return primes[n];
}

int gen_prime_key(int n)
{
    return prime_sieve(n);
}

int encrypt(int n, int key)
{
    return (n * key) % MAX_PRIME;
}

int decrypt(int n, int key)
{
    return (key * n) % MAX_PRIME;
}