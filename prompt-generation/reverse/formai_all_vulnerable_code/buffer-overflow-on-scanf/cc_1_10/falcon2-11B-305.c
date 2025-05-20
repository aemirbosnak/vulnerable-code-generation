//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_SIZE 1024

typedef struct {
    int n;
    int e;
} RSAKey;

RSAKey generate_keys(int n, int e) {
    RSAKey key;
    key.n = n;
    key.e = e;
    return key;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int modulo_exponentiation(int b, int e, int m) {
    int result = 1;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * b) % m;
        }
        b = (b * b) % m;
        e /= 2;
    }
    return result;
}

int main() {
    int n;
    int e;
    printf("Enter the size of the modulus (n): ");
    scanf("%d", &n);
    printf("Enter the public exponent (e): ");
    scanf("%d", &e);

    if (!is_prime(n)) {
        printf("Error: n is not a prime number\n");
        return 1;
    }

    RSAKey key = generate_keys(n, e);
    printf("Public key (n, e): (%d, %d)\n", key.n, key.e);

    int message[MAX_MESSAGE_SIZE];
    int message_size = 0;
    printf("Enter a message to encrypt: ");
    scanf("%d", &message[message_size]);
    while (1) {
        printf("Enter another message (or 0 to stop): ");
        int c;
        scanf("%d", &c);
        if (c == 0) {
            break;
        }
        message[message_size++] = c;
    }

    int encrypted[MAX_MESSAGE_SIZE];
    int encrypted_size = 0;
    for (int i = 0; i < message_size; i++) {
        int m = message[i];
        int c = modulo_exponentiation(m, e, n);
        encrypted[encrypted_size++] = c;
    }

    printf("Encrypted message: ");
    for (int i = 0; i < encrypted_size; i++) {
        printf("%d", encrypted[i]);
    }
    printf("\n");

    RSAKey key_copy = key;
    int decrypted[MAX_MESSAGE_SIZE];
    int decrypted_size = 0;
    for (int i = 0; i < encrypted_size; i++) {
        int c = encrypted[i];
        int m = modulo_exponentiation(c, key_copy.e, n);
        decrypted[decrypted_size++] = m;
    }

    printf("Decrypted message: ");
    for (int i = 0; i < decrypted_size; i++) {
        printf("%d", decrypted[i]);
    }
    printf("\n");

    return 0;
}