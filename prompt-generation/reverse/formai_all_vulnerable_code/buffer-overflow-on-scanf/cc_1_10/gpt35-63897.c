//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PRIME_RANGE 1000 // Upper limit of prime number range
#define PUBL_KEY 23 // Public key for encryption

// Function to generate random prime number from range
int genPrime() {
    int num, isPrime;
    do {
        num = (rand() % PRIME_RANGE) + 1;
        isPrime = 1;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    } while (!isPrime);
    return num;
}

// Function to generate RSA keys
void genRSAKeys(int *pubKey, int *privKey, int *modulus) {
    srand(time(NULL)); // Seed random number generator with current time
    int p, q, n, phi, e, d;
    p = genPrime();
    q = genPrime();
    n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        e = (rand() % (phi - 1)) + 1;
    } while (fmod(phi, e) == 0); // Choose e such that gcd(phi, e) = 1
    for (int k = 1;; k++) {
        if ((phi * k + 1) % e == 0) { // Calculate d such that e * d = 1 (mod phi)
            d = (phi * k + 1) / e;
            break;
        }
    }
    *pubKey = e;
    *privKey = d;
    *modulus = n;
}

// Function to encrypt message using RSA algorithm
int rsaEncrypt(int message, int pubKey, int modulus) {
    int cipher = 1;
    for (int i = 0; i < pubKey; i++) {
        cipher = (cipher * message) % modulus;
    }
    return cipher;
}

// Function to decrypt message using RSA algorithm
int rsaDecrypt(int cipher, int privKey, int modulus) {
    int message = 1;
    for (int i = 0; i < privKey; i++) {
        message = (message * cipher) % modulus;
    }
    return message;
}

int main() {
    int pubKey, privKey, modulus;
    genRSAKeys(&pubKey, &privKey, &modulus);
    printf("Public key: %d\n", pubKey);
    printf("Private key: %d\n", privKey);
    printf("Modulus: %d\n", modulus);
    int message, cipher, decrypted;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message);
    cipher = rsaEncrypt(message, pubKey, modulus);
    printf("Encrypted message: %d\n", cipher);
    printf("Decrypting...\n");
    decrypted = rsaDecrypt(cipher, privKey, modulus);
    printf("Decrypted message: %d\n", decrypted);
    return 0;
}