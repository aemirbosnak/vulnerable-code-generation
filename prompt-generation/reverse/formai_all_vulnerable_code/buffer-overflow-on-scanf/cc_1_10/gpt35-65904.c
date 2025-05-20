//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

// Function to check if a number is prime
bool is_prime(int num)
{
    int i;
    if (num <= 1) return false;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to find the multiplicative inverse of a number
int multiplicative_inverse(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

int main()
{
    int p, q, n, phi_n, e = 0, d;
    char message[1000];

    // Accepting two prime numbers from the user
    printf("Enter a prime number (p): ");
    scanf("%d", &p);
    while (!is_prime(p)) {
        printf("%d is not a prime number. Please enter a prime number: ", p);
        scanf("%d", &p);
    }

    printf("Enter another prime number (q): ");
    scanf("%d", &q);
    while (!is_prime(q) || q == p) {
        if (!is_prime(q))
            printf("%d is not a prime number. ", q);
        else
            printf("p and q should not be equal. ");
        printf("Please enter another prime number: ");
        scanf("%d", &q);
    }

    // Calculating n and phi_n
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // Finding a suitable value for e
    for (int i = 2; i < phi_n; i++) {
        if (gcd(i, phi_n) == 1) {
            e = i;
            break;
        }
    }

    // Calculating d - the multiplicative inverse of e mod phi_n
    d = multiplicative_inverse(e, phi_n);

    // Accepting message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypting the message using the public key (n, e)
    int encrypted[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        int m = (int)message[i];
        int c = (int)fmod(pow(m, e), n);
        encrypted[i] = c;
    }

    // Printing the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    // Decrypting the message using the private key (n, d)
    char decrypted[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        int c = encrypted[i];
        int m = (int)fmod(pow(c, d), n);
        decrypted[i] = (char)m;
    }

    // Printing the decrypted message
    printf("Decrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}