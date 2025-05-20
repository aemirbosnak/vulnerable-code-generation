//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 10000

/* Function declarations */
int is_prime(int n);
int gcd(int a, int b);
int generate_key();
int multiplicative_inverse(int a, int b);
int encrypt(int msg, int e, int n);
int decrypt(int cipher, int d, int n);

int main()
{
    int p, q, n, phi_n, e, d, msg, cipher, decrypted_msg;

    /* Generate two large prime numbers */
    do {
        p = generate_key();
    } while (!is_prime(p));

    do {
        q = generate_key();
    } while (!is_prime(q));

    /* Calculate n and phi(n) */
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    /* Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1 */
    do {
        e = rand() % phi_n + 1;
    } while (gcd(e, phi_n) != 1);

    /* Calculate the multiplicative inverse of e mod phi(n) */
    d = multiplicative_inverse(e, phi_n);

    /* Get the message from the user */
    printf("Enter a message to encrypt: ");
    scanf("%d", &msg);

    /* Encrypt the message using public key (e, n) */
    cipher = encrypt(msg, e, n);

    /* Display the encrypted message */
    printf("Encrypted message: %d\n", cipher);

    /* Decrypt the message using private key (d, n) */
    decrypted_msg = decrypt(cipher, d, n);

    /* Display the decrypted message */
    printf("Decrypted message: %d\n", decrypted_msg);

    return 0;
}

/* Function to check if a number is prime */
int is_prime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

/* Function to calculate GCD of two numbers */
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

/* Function to generate a random key */
int generate_key()
{
    int key;

    srand(time(NULL));
    key = rand() % MAX + 1;

    return key;
}

/* Function to calculate the multiplicative inverse of a mod b */
int multiplicative_inverse(int a, int b)
{
    int q, r, t1 = 0, t2 = 1, t;

    while (a > 0) {
        q = b / a;
        r = b - q * a;
        t = t1 - q * t2;

        b = a;
        a = r;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0)
        t1 += b;

    return t1;
}

/* Function to encrypt a message using public key (e, n) */
int encrypt(int msg, int e, int n)
{
    int cipher = 1;

    for (int i = 0; i < e; i++) {
        cipher = (cipher * msg) % n;
    }

    return cipher;
}

/* Function to decrypt a message using private key (d, n) */
int decrypt(int cipher, int d, int n)
{
    int msg = 1;

    for (int i = 0; i < d; i++) {
        msg = (msg * cipher) % n;
    }

    return msg;
}