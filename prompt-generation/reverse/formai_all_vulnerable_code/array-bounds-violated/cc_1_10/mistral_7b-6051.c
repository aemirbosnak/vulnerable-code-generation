//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define ROUNDS 10

void generate_key(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] = rand() & 0xFF;
    }
}

void xor_bytes(unsigned char *a, unsigned char *b, int length) {
    for (int i = 0; i < length; ++i) {
        a[i] ^= b[i];
    }
}

void rotate_left(unsigned char *bytes, int length, int shifts) {
    for (int i = shifts; i < length; ++i) {
        unsigned char temp = bytes[i];
        for (int j = i - shifts; j < i; ++j) {
            bytes[j] = bytes[j + 1];
        }
        bytes[i] = temp;
    }
}

void encrypt_block(unsigned char *plaintext, unsigned char *key) {
    unsigned char left_half[BLOCK_SIZE / 2];
    unsigned char right_half[BLOCK_SIZE / 2];

    for (int i = 0; i < BLOCK_SIZE / 2; ++i) {
        left_half[i] = plaintext[i * 2];
        right_half[i] = plaintext[i * 2 + 1];
    }

    for (int round = 0; round < ROUNDS; ++round) {
        unsigned char temp[BLOCK_SIZE];

        xor_bytes(left_half, right_half, BLOCK_SIZE / 2);
        xor_bytes(left_half, key, BLOCK_SIZE / 2);

        rotate_left(left_half, BLOCK_SIZE / 2, 1);
        rotate_left(right_half, BLOCK_SIZE / 2, 1);

        xor_bytes(left_half, right_half, BLOCK_SIZE / 2);

        memcpy(temp, left_half, BLOCK_SIZE / 2);
        memcpy(&left_half[BLOCK_SIZE / 4], &right_half[BLOCK_SIZE / 4], BLOCK_SIZE / 4);
        memcpy(&right_half[BLOCK_SIZE / 4], temp, BLOCK_SIZE / 4);
    }

    for (int i = 0; i < BLOCK_SIZE; ++i) {
        plaintext[i] = left_half[i];
    }
}

void encrypt_message(unsigned char *message, unsigned char *key) {
    int message_length = strlen((char *) message);
    unsigned char encrypted_block[BLOCK_SIZE];

    for (int block_index = 0; block_index < message_length; block_index += BLOCK_SIZE) {
        int block_length = (block_index + BLOCK_SIZE < message_length) ? BLOCK_SIZE : message_length - block_index;
        memcpy(encrypted_block, &message[block_index], block_length);
        encrypt_block(encrypted_block, key);
        memcpy(&message[block_index], encrypted_block, block_length);
    }
}

int main() {
    srand(time(NULL));

    unsigned char plaintext[100] = "This is a secret message.";
    unsigned char key[KEY_SIZE];
    generate_key(key);

    printf("Plaintext: %s\n", plaintext);

    encrypt_message(plaintext, key);

    printf("Ciphertext: ");
    for (int i = 0; i < strlen((char *) plaintext); ++i) {
        printf("%.2X ", plaintext[i]);
    }
    printf("\n");

    return 0;
}