//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to encrypt a message
int encrypt(int message, int e, int n) {
    int cipher = 1;
    for (int i = 0; i < e; i++) {
        cipher = (cipher * message) % n;
    }
    return cipher;
}

// Function to decrypt a message
int decrypt(int cipher, int d, int n) {
    int message = 1;
    for (int i = 0; i < d; i++) {
        message = (message * cipher) % n;
    }
    return message;
}

// Structure for the romantic keys
typedef struct {
    int publicKey[2];  // {e, n}
    int privateKey[2]; // {d, n}
} RomanticKey;

// Function to generate romantic keys
RomanticKey generateKeys(int p, int q) {
    RomanticKey keys;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Find e
    int e = 2; // Start with the smallest prime number
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }

    // Find d
    int d = modInverse(e, phi);

    keys.publicKey[0] = e;
    keys.publicKey[1] = n;
    keys.privateKey[0] = d;
    keys.privateKey[1] = n;
    
    return keys;
}

// Main romantic message handling
int main() {
    int p, q;
    printf("Enter the first prime number to symbolize trust (p): ");
    scanf("%d", &p);
    printf("Enter the second prime number to symbolize love (q): ");
    scanf("%d", &q);

    RomanticKey keys = generateKeys(p, q);
    
    // Display the keys
    printf("Oh, lovely hearts! Here are the keys;\n");
    printf("Public Key (e, n): (%d, %d)\n", keys.publicKey[0], keys.publicKey[1]);
    printf("Private Key (d, n): (%d, %d)\n", keys.privateKey[0], keys.privateKey[1]);

    // The romantic message
    char message[100];
    printf("Whisper your message of love (numeric format, please): ");
    scanf("%s", message);

    int cipher = encrypt(atoi(message), keys.publicKey[0], keys.publicKey[1]);
    printf("Your love encrypted is: %d\n", cipher);

    int decryptedMessage = decrypt(cipher, keys.privateKey[0], keys.privateKey[1]);
    printf("And now, the heart speaks again: %d\n", decryptedMessage);

    return 0;
}