//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate gcd
int gcd(int a, int b) {
    int temp;
    while (b!= 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular inverse
int mod_inverse(int a, int m) {
    int x, y, temp;
    int g = gcd(a, m);
    if (g == 1)
        return 1;
    x = (a % m) + m;
    y = m - 1;
    while (y!= 0) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return (x % m) + m;
}

// Function to generate public and private keys
void generate_keys(int p, int q, int *public_key, int *private_key) {
    int phi_n, e, d;
    phi_n = (p - 1) * (q - 1);
    e = 2;
    while (gcd(e, phi_n)!= 1) {
        e++;
    }
    *public_key = e;
    d = mod_inverse(e, phi_n);
    *private_key = d;
}

// Function to encrypt message
int encrypt(int plaintext, int public_key, int n) {
    return (int)pow(plaintext, public_key) % n;
}

// Function to decrypt ciphertext
int decrypt(int ciphertext, int private_key, int n) {
    return (int)pow(ciphertext, private_key) % n;
}

// Main function
int main() {
    int p, q, n, public_key, private_key, plaintext, ciphertext, decrypted_text;
    printf("Enter two prime numbers p and q: ");
    scanf("%d %d", &p, &q);
    n = p * q;
    generate_keys(p, q, &public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Enter plaintext to encrypt: ");
    scanf("%d", &plaintext);
    ciphertext = encrypt(plaintext, public_key, n);
    printf("Ciphertext: %d\n", ciphertext);
    decrypted_text = decrypt(ciphertext, private_key, n);
    printf("Decrypted text: %d\n", decrypted_text);
    return 0;
}