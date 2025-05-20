//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int *public_key;
    int *private_key;
} KeyPair;

int generate_keypair(KeyPair *keypair) {
    int *public_key = (int *)malloc(MAX_SIZE * sizeof(int));
    int *private_key = (int *)malloc(MAX_SIZE * sizeof(int));

    if (public_key == NULL || private_key == NULL) {
        return -1;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        public_key[i] = rand() % 10;
        private_key[i] = rand() % 10;
    }

    keypair->public_key = public_key;
    keypair->private_key = private_key;

    return 0;
}

int encrypt(int plaintext, int *public_key) {
    int ciphertext = 0;
    int modulus = 0;

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        modulus = (public_key[i] * plaintext + modulus) % 10;
        ciphertext += modulus * (int)pow(2, i);
    }

    return ciphertext;
}

int decrypt(int ciphertext, int *private_key) {
    int plaintext = 0;
    int modulus = 0;

    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        modulus = (private_key[i] * ciphertext + modulus) % 10;
        plaintext += modulus * (int)pow(2, i);
    }

    return plaintext;
}

int main() {
    KeyPair keypair;
    int plaintext = 12345;

    generate_keypair(&keypair);

    int ciphertext = encrypt(plaintext, keypair.public_key);
    int decrypted_text = decrypt(ciphertext, keypair.private_key);

    printf("Plaintext: %d\n", plaintext);
    printf("Ciphertext: %d\n", ciphertext);
    printf("Decrypted Text: %d\n", decrypted_text);

    return 0;
}