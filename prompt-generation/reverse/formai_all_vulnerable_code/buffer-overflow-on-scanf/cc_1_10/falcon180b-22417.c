//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10

typedef struct {
    int key[KEY_SIZE];
    int state[KEY_SIZE];
} RC4;

void init_rc4(RC4 *rc4, const char *key) {
    int i, j, k;
    char key_buf[KEY_SIZE];

    for (i = 0; i < KEY_SIZE; i++) {
        key_buf[i] = key[i] & 0xff;
    }

    for (i = 0; i < KEY_SIZE; i++) {
        rc4->key[i] = key_buf[i];
    }

    for (i = 0; i < KEY_SIZE; i++) {
        j = (rc4->key[i] & 0xff) % KEY_SIZE;
        k = 0;

        while (k < i) {
            j = (j + rc4->key[k] + i) % KEY_SIZE;
            k++;
        }

        rc4->state[i] = j;
    }
}

void rc4_encrypt(RC4 *rc4, char *data, int len) {
    int i, j, k;
    char state_buf[KEY_SIZE];

    for (i = 0; i < len; i++) {
        j = (rc4->state[i % KEY_SIZE] & 0xff) % KEY_SIZE;
        k = 0;

        while (k < i) {
            j = (j + rc4->key[k] + i) % KEY_SIZE;
            k++;
        }

        rc4->state[i % KEY_SIZE] = j;

        data[i] ^= rc4->state[(rc4->state[i % KEY_SIZE] + rc4->key[i % KEY_SIZE]) % KEY_SIZE];
    }
}

void rc4_decrypt(RC4 *rc4, char *data, int len) {
    rc4_encrypt(rc4, data, len);
}

int main() {
    char key[KEY_SIZE];
    char data[BLOCK_SIZE];
    RC4 rc4;

    printf("Enter encryption key (up to %d bytes):\n", KEY_SIZE - 1);
    scanf("%s", key);

    init_rc4(&rc4, key);

    printf("Enter data to encrypt/decrypt:\n");
    scanf("%s", data);

    rc4_encrypt(&rc4, data, strlen(data));

    printf("Encrypted data:\n%s\n", data);

    rc4_decrypt(&rc4, data, strlen(data));

    printf("Decrypted data:\n%s\n", data);

    return 0;
}