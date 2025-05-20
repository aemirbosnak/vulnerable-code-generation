#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    char *plaintext;
    char *ciphertext;
} Encryptor;

void generate_key(Encryptor *enc, char const *seed) {
    enc->key = (char*) malloc(256 * sizeof(char));
    strcpy(enc->key, seed);
}

void encrypt(Encryptor *enc, char const *plaintext, char *ciphertext, int len) {
    strcpy(enc->plaintext, plaintext);
    strcpy(enc->ciphertext, ciphertext);

    for (int i = 0; i < len; ++i) {
        enc->ciphertext[i] = enc->key[(int) enc->plaintext[i] % 256];
    }
}

void print_ciphertext(Encryptor *enc) {
    printf("Ciphertext: %s\n", enc->ciphertext);
}

int main() {
    Encryptor enc;
    char seed[] = "My Secret Key";
    char plaintext[] = "Attack at dawn!";
    char ciphertext[256];

    generate_key(&enc, seed);
    encrypt(&enc, plaintext, ciphertext, strlen(plaintext));
    print_ciphertext(&enc);

    // Exceed array bounds to simulate a real-world error
    encrypt(&enc, plaintext, ciphertext, strlen(plaintext) + 100);

    return 0;
}
