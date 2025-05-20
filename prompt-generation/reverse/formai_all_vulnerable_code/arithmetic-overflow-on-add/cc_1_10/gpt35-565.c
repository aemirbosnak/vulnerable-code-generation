//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int isPrime(int num)
{
    if (num == 1)
        return 0; 
    int i;
    for (i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int generateKey(int *public_key, int *private_key)
{
    srand(time(NULL));
    int prime1, prime2;
    int n, phi_n, e, d;
    do
    {
        prime1 = rand() % 50 + 1;
    } while (!isPrime(prime1));
    do
    {
        prime2 = rand() % 50 + 1;
    } while (!isPrime(prime2));
    n = prime1 * prime2;
    phi_n = (prime1 - 1) * (prime2 - 1);
    do
    {
        e = rand() % (phi_n - 2) + 2;
    } while (gcd(e, phi_n) != 1);
    do
    {
        d = rand() % (phi_n - 2) + 2;
    } while ((d * e) % phi_n != 1);
    *public_key = e;
    *private_key = d;
    return n;
}

int powermod(int num, int exp, int mod)
{
    int result = 1;
    num = num % mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * num) % mod;
        exp = exp >> 1;
        num = (num * num) % mod;
    }
    return result;
}

int main()
{
    int public_key, private_key;
    int n = generateKey(&public_key, &private_key);
    printf("Public key: %d\nPrivate key: %d\nN: %d\n", public_key, private_key, n);
    int num;
    printf("Enter a number to encrypt: ");
    scanf("%d", &num);
    int encrypted_num = powermod(num, public_key, n);
    printf("Encrypted number: %d\n", encrypted_num);
    int decrypted_num = powermod(encrypted_num, private_key, n);
    printf("Decrypted number: %d\n", decrypted_num);
    return 0;
}