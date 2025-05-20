//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned long e;
    unsigned long n;
} PublicKey;

typedef struct {
    unsigned long d;
    unsigned long n;
} PrivateKey;

// Function to calculate gcd
unsigned long gcd(unsigned long a, unsigned long b) {
    while (b != 0) {
        unsigned long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular exponentiation
unsigned long mod_exp(unsigned long base, unsigned long exp, unsigned long mod) {
    unsigned long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            result = (result * base) % mod;
        }
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

// Function to find modulo inverse using Extended Euclidean Algorithm
unsigned long mod_inverse(unsigned long a, unsigned long m) {
    unsigned long m0 = m;
    unsigned long y = 0;
    unsigned long x = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        unsigned long q = a / m;
        unsigned long t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) {
        x += m0;
    }

    return x;
}

// Function to generate keys
void generate_keys(PublicKey *pub_key, PrivateKey *priv_key, unsigned long p, unsigned long q) {
    // Calculate n
    pub_key->n = p * q;
    
    // Calculate phi(n)
    unsigned long phi = (p - 1) * (q - 1);
    
    // Choose e
    pub_key->e = 3; // For simplicity, using a small prime
    while (gcd(pub_key->e, phi) != 1) {
        pub_key->e++;
    }
    
    // Calculate d
    priv_key->d = mod_inverse(pub_key->e, phi);
    priv_key->n = pub_key->n;
}

// Function to encrypt a message
unsigned long encrypt(PublicKey pub_key, unsigned long message) {
    return mod_exp(message, pub_key.e, pub_key.n);
}

// Function to decrypt a message
unsigned long decrypt(PrivateKey priv_key, unsigned long cipher) {
    return mod_exp(cipher, priv_key.d, priv_key.n);
}

int main() {
    unsigned long p, q, message;

    // User configurable input
    printf("Enter first prime (p): ");
    scanf("%lu", &p);
    printf("Enter second prime (q): ");
    scanf("%lu", &q);
    printf("Enter message to encrypt (as a number): ");
    scanf("%lu", &message);

    if (p * q <= message) {
        printf("Message should be less than the product of p and q.\n");
        return 1;
    }

    PublicKey pub_key;
    PrivateKey priv_key;

    // Generate keys
    generate_keys(&pub_key, &priv_key, p, q);
    
    // Encrypt the message
    unsigned long cipher = encrypt(pub_key, message);
    printf("Encrypted message: %lu\n", cipher);

    // Decrypt the message
    unsigned long decrypted_message = decrypt(priv_key, cipher);
    printf("Decrypted message: %lu\n", decrypted_message);

    return 0;
}