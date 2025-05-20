//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to calculate gcd of two numbers
int gcd(int a, int b) {
    int temp;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// Function to check if a number is prime
int isPrime(int n) {
    int i;

    if (n == 2 || n == 3) {
        return 1;
    }

    if (n == 1 || n % 2 == 0) {
        return 0;
    }

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to generate a random prime number
int generateRandomPrimeNumber(int min, int max) {
    int num = generateRandomNumber(min, max);

    while (!isPrime(num)) {
        num = generateRandomNumber(min, max);
    }

    return num;
}

// Function to calculate the modular multiplicative inverse
int getModularMultiplicativeInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to generate public and private keys
void generateKeys(int p, int q, int *e, int *d, int *n) {
    int phi = (p - 1) * (q - 1);
    *n = p * q;

    do {
        *e = generateRandomNumber(2, phi - 1);
    } while (gcd(*e, phi) != 1);

    *d = getModularMultiplicativeInverse(*e, phi);
}

int main() {
    srand(time(NULL));
    int p, q, e, d, n, plaintext, ciphertext;
    char choice;

    printf("Welcome to the Public-Key Algorithm Implementation\n");

    do {
        printf("Enter two prime numbers (p and q): ");
        scanf("%d %d", &p, &q);

        if (!isPrime(p) || !isPrime(q)) {
            printf("Invalid input, please enter prime numbers only.\n");
            continue;
        }

        generateKeys(p, q, &e, &d, &n);

        printf("Public key: (%d, %d)\n", n, e);
        printf("Private key: (%d, %d)\n", n, d);

        printf("Enter a plaintext integer: ");
        scanf("%d", &plaintext);

        ciphertext = ((long int) plaintext * plaintext) % n;

        printf("Ciphertext: %d\n", ciphertext);

        printf("Do you want to encrypt another plaintext? (y/n) ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");

    return 0;
}