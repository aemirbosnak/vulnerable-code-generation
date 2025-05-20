//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define ROUNDS 10

int expanded_key[44];

const int s_box[16][16] = {
        {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76},
        {0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0},
        {0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15},
        {0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75},
        {0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84},
        {0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF},
        {0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8},
        {0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2},
        {0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73},
        {0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB},
        {0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79},
        {0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08},
        {0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A},
        {0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E},
        {0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF},
        {0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16}
};

const int rcon[11] = {0x00000000, 0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000};

void key_expansion(unsigned char* key);

void block_xor(unsigned char* data, const unsigned char* value);

void sub_bytes(unsigned char* data);

void shift_rows(unsigned char* data);

void mix_columns(unsigned char* data);

void aes_encrypt(unsigned char* block);

int main() {
    unsigned char message[256] = "Hello, world! This is a test message.";
    unsigned char key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    int message_len = strlen(message);

    key_expansion(key);

    printf("Message: %s\n", message);

    // Pad the message
    int padding = BLOCK_SIZE - (message_len % BLOCK_SIZE);
    if (padding < BLOCK_SIZE) {
        for (int i = message_len; i < message_len + padding; i++) {
            message[i] = padding;
        }
    }
    message_len += padding;
    message[message_len] = '\0';

    for (int i = 0; i < message_len; i += BLOCK_SIZE) {
        aes_encrypt(message + i);
    }

    printf("Encrypted message: ");
    for (int i = 0; i < message_len; i++) {
        printf("%02x", message[i]);
    }
    printf("\n");

    return 0;
}

void key_expansion(unsigned char* key) {
    int i, j;
    unsigned char temp[4];

    // Copy the first 16 bytes of the key into the expanded key
    for (i = 0; i < 4; i++) {
        expanded_key[i] = (key[4*i] << 24) | (key[4*i+1] << 16) | (key[4*i+2] << 8) | key[4*i+3];
    }

    for (i = 4; i < 44; i++) {
        // Copy the previous word to the temp variable
        for (j = 0; j < 4; j++) {
            temp[j] = (expanded_key[(i-1)*4 + j] >> 24) & 0xff;
        }

        // Rotate the word
        unsigned char x = temp[0];
        temp[0] = temp[1];
        temp[1] = temp[2];
        temp[2] = temp[3];
        temp[3] = x;

        // Apply the S-Box to each byte
        for (j = 0; j < 4; j++) {
            temp[j] = s_box[temp[j] >> 4][temp[j] & 0x0f];
        }

        // XOR the Rcon value with the first byte
        temp[0] ^= rcon[i/4];

        // Compute the new expanded key value and store it
        for (j = 0; j < 4; j++) {
            expanded_key[i*4 + j] = expanded_key[(i-4)*4 + j] ^ ((temp[j] << 24) & 0xff000000);
        }
    }
}

void block_xor(unsigned char* data, const unsigned char* value) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        data[i] ^= value[i];
    }
}

void sub_bytes(unsigned char* data) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        data[i] = s_box[data[i] >> 4][data[i] & 0x0f];
    }
}

void shift_rows(unsigned char* data) {
    // Do not shift row 0
    // Shift row 1
    unsigned char temp = data[1];
    data[1] = data[5];
    data[5] = data[9];
    data[9] = data[13];
    data[13] = temp;

    // Shift row 2
    temp = data[2];
    data[2] = data[10];
    data[10] = temp;
    temp = data[6];
    data[6] = data[14];
    data[14] = temp;

    // Shift row 3
    temp = data[15];
    data[15] = data[11];
    data[11] = data[7];
    data[7] = data[3];
    data[3] = temp;
}

void mix_columns(unsigned char* data) {
    unsigned char temp[BLOCK_SIZE];
    memcpy(temp, data, BLOCK_SIZE);

    data[0] = (unsigned char) ((2*temp[0] ^ 3*temp[1] ^ 1*temp[2] ^ 1*temp[3]) & 0xff);
    data[1] = (unsigned char) ((1*temp[0] ^ 2*temp[1] ^ 3*temp[2] ^ 1*temp[3]) & 0xff);
    data[2] = (unsigned char) ((1*temp[0] ^ 1*temp[1] ^ 2*temp[2] ^ 3*temp[3]) & 0xff);
    data[3] = (unsigned char) ((3*temp[0] ^ 1*temp[1] ^ 1*temp[2] ^ 2*temp[3]) & 0xff);

    data[4] = (unsigned char) ((2*temp[4] ^ 3*temp[5] ^ 1*temp[6] ^ 1*temp[7]) & 0xff);
    data[5] = (unsigned char) ((1*temp[4] ^ 2*temp[5] ^ 3*temp[6] ^ 1*temp[7]) & 0xff);
    data[6] = (unsigned char) ((1*temp[4] ^ 1*temp[5] ^ 2*temp[6] ^ 3*temp[7]) & 0xff);
    data[7] = (unsigned char) ((3*temp[4] ^ 1*temp[5] ^ 1*temp[6] ^ 2*temp[7]) & 0xff);

    data[8] = (unsigned char) ((2*temp[8] ^ 3*temp[9] ^ 1*temp[10] ^ 1*temp[11]) & 0xff);
    data[9] = (unsigned char) ((1*temp[8] ^ 2*temp[9] ^ 3*temp[10] ^ 1*temp[11]) & 0xff);
    data[10] = (unsigned char) ((1*temp[8] ^ 1*temp[9] ^ 2*temp[10] ^ 3*temp[11]) & 0xff);
    data[11] = (unsigned char) ((3*temp[8] ^ 1*temp[9] ^ 1*temp[10] ^ 2*temp[11]) & 0xff);

    data[12] = (unsigned char) ((2*temp[12] ^ 3*temp[13] ^ 1*temp[14] ^ 1*temp[15]) & 0xff);
    data[13] = (unsigned char) ((1*temp[12] ^ 2*temp[13] ^ 3*temp[14] ^ 1*temp[15]) & 0xff);
    data[14] = (unsigned char) ((1*temp[12] ^ 1*temp[13] ^ 2*temp[14] ^ 3*temp[15]) & 0xff);
    data[15] = (unsigned char) ((3*temp[12] ^ 1*temp[13] ^ 1*temp[14] ^ 2*temp[15]) & 0xff);
}

void aes_encrypt(unsigned char* block) {
    int i;
    unsigned char data[BLOCK_SIZE];

    // Copy the input data into the data buffer
    memcpy(data, block, BLOCK_SIZE);

    // XOR the first block with the expanded key
    block_xor(data, (unsigned char*) &expanded_key[0]);

    // Perform the specified number of rounds
    for (i = 1; i <= ROUNDS; i++) {
        sub_bytes(data);
        shift_rows(data);
        if (i < ROUNDS) {
            mix_columns(data);
        }
        block_xor(data, (unsigned char*) &expanded_key[i*4]);
    }

    // Copy the data buffer back to the original block
    memcpy(block, data, BLOCK_SIZE);
}