//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random prime number within a range
int generate_prime(int range_start, int range_end)
{
    int num, i, flag;
    srand(time(NULL)); // Seed for random number generation
    while (1)
    {
        num = range_start + rand() % (range_end - range_start + 1); // Generate a random number within the specified range
        flag = 1;
        for (i = 2; i <= sqrt(num); i++) // Check if the number is prime
        {
            if (num % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1) // If prime, return the number
            return num;
    }
}

// Function to calculate modular exponentiation
long long modular_exp(int base, int exponent, int modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

int main()
{
    int p, q, n, e, d, phi_n, message, encrypted_msg, decrypted_msg;
    printf("Enter the range for generating prime numbers (start end): ");
    scanf("%d %d", &p, &q);

    // Generate two distinct prime numbers
    while (1)
    {
        p = generate_prime(p, q);
        q = generate_prime(p, q);
        if (p != q)
            break;
    }

    // Calculate modulus and totient function
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // Choose an e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    srand(time(NULL));
    while (1)
    {
        e = rand() % phi_n + 1;
        if (e < phi_n && e > 1)
        {
            int gcd = 1;
            for (int i = 2; i <= e && i <= phi_n; i++)
            {
                if (e % i == 0 && phi_n % i == 0)
                {
                    gcd = i;
                    break;
                }
            }
            if (gcd == 1)
                break;
        }
    }

    // Calculate d using the extended Euclidean algorithm
    int a = phi_n, b = e, t, y = 0, x = 1;
    while (b > 0)
    {
        t = b;
        b = a % b;
        a = t;
        t = y;
        y = x - (a / t) * y;
        x = t;
    }
    if (x < 0)
        x += phi_n;
    d = x;

    printf("\nPublic key: (%d, %d)", e, n);
    printf("\nPrivate key: (%d, %d)", d, n);

    printf("\nEnter the message to be encrypted (integer only): ");
    scanf("%d", &message);

    // Encrypt the message
    encrypted_msg = modular_exp(message, e, n);
    printf("\nEncrypted message: %d", encrypted_msg);

    // Decrypt the message
    decrypted_msg = modular_exp(encrypted_msg, d, n);
    printf("\nDecrypted message: %d", decrypted_msg);

    return 0;
}