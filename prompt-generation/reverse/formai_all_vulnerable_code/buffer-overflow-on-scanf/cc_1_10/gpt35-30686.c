//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// This function generates a random prime number
int generatePrimeNumber() {
    int num, i, flag;
    srand(time(NULL));
    num = rand() % 10 + 1;
    while (1) {
        flag = 0;
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return num;
        } else {
            num = rand() % 10 + 1;
        }
    }
}

// This function generates public and private keys
void generateKeys(int *n, int *e, int *d) {
    int p, q, phi, lcm, g;
    p = generatePrimeNumber();
    q = generatePrimeNumber();
    *n = p * q;
    phi = (p - 1) * (q - 1);
    for (g = 2; g < phi; g++) {
        if ((phi % g) == 0) {
            continue;
        }
        int flag = 1;
        for (unsigned int i = 2; i < g; ++i) {
            if ((g % i) == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            *e = g;
            break;
        }
    }
    for (int i = 1; i <= phi; i++) {
        if ((i * (*e)) % phi == 1) {
            *d = i;
            break;
        }
    }
}

// This function encrypts the data using the public key
int encrypt(int message, int e, int n) {
    int cipher = 1;
    for (int i = 0; i < e; i++) {
        cipher = (cipher * message) % n;
    }
    return cipher;
}

// This function decrypts the data using the private key
int decrypt(int cipher, int d, int n) {
    int message = 1;
    for (int i = 0; i < d; i++) {
        message = (message * cipher) % n;
    }
    return message;
}

int main() {
    // Generate keys and display them
    int n, e, d;
    generateKeys(&n, &e, &d);
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    // Encrypt and decrypt the message
    int message, cipher, decrypted_message;
    printf("Enter the message: ");
    scanf("%d", &message);
    cipher = encrypt(message, e, n);
    printf("Encrypted Message: %d\n", cipher);
    decrypted_message = decrypt(cipher, d, n);
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}