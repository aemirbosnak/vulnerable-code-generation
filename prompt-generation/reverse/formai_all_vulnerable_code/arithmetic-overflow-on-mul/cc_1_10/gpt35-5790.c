//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define PRIME 65537

int pow_mod(int x, int y, int m) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int generate_key_pair(int *public_key, int *private_key) {
    int p = 0, q = 0, n = 0, phi_n = 0, e = 0, d = 0;
    do {
        p = rand() % PRIME;
    } while (p <= 1);
    do {
        q = rand() % PRIME;
    } while (q == p || q <= 1);
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    do {
        e = rand() % phi_n;
    } while (e <= 1 || gcd(e, phi_n) != 1);
    d = pow_mod(e, phi_n - 1, phi_n);
    *public_key = e;
    *private_key = d;
    return n;
}

int encrypt(char *message, int message_len, int public_key, int n, char *encrypted_message) {
    int i;
    for (i = 0; i < message_len; i++) {
        encrypted_message[i] = pow_mod(message[i], public_key, n);
    }
    return i;
}

int decrypt(char *encrypted_message, int encrypted_message_len, int private_key, int n, char *decrypted_message) {
    int i;
    for (i = 0; i < encrypted_message_len; i++) {
        decrypted_message[i] = pow_mod(encrypted_message[i], private_key, n);
    }
    return i;
}

int main() {
    int public_key, private_key, n;
    char message[SIZE], encrypted_message[SIZE], decrypted_message[SIZE];
    printf("Welcome to the Cyberpunk RSA Public-Key Algorithm Implementation!\n");
    printf("Generating Key Pair...\n");
    n = generate_key_pair(&public_key, &private_key);
    printf("Public Key: %d\n", public_key);
    printf("Private Key: %d\n", private_key);
    printf("N: %d\n", n);
    printf("Enter the message to encrypt: ");
    fgets(message, SIZE, stdin);
    int message_len = strlen(message) - 1;
    printf("Encrypting the message...\n");
    int encrypted_message_len = encrypt(message, message_len, public_key, n, encrypted_message);
    printf("Encrypted Message: ");
    int i;
    for (i = 0; i < encrypted_message_len; i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");
    printf("Decrypting the message...\n");
    int decrypted_message_len = decrypt(encrypted_message, encrypted_message_len, private_key, n, decrypted_message);
    decrypted_message[decrypted_message_len] = '\0';
    printf("Decrypted Message: %s\n", decrypted_message);
    printf("Thank you for using the Cyberpunk RSA Public-Key Algorithm Implementation!\n");
    return 0;
}