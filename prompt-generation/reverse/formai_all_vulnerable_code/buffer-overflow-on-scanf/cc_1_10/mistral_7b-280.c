//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 10
#define DATA_LENGTH 25

void generate_key(unsigned char *key);
unsigned char xor_byte(unsigned char byte, unsigned char key_byte);
void generate_binary_sequence(unsigned char *binary_sequence, unsigned char *key);
void xor_data(unsigned char *data, unsigned char *binary_sequence);

int main() {
    unsigned char key[KEY_LENGTH];
    unsigned char data[DATA_LENGTH];
    unsigned char binary_sequence[KEY_LENGTH];

    srand(time(NULL));

    generate_key(key);
    printf("Key: ");
    for (int i = 0; i < KEY_LENGTH; ++i)
        printf("%02x ", key[i]);
    printf("\n");

    printf("Enter data (25 bytes): ");
    for (int i = 0; i < DATA_LENGTH; ++i)
        scanf("%hhu", &data[i]);

    generate_binary_sequence(binary_sequence, key);
    xor_data(data, binary_sequence);

    printf("Encrypted data: ");
    for (int i = 0; i < DATA_LENGTH; ++i)
        printf("%02x ", data[i]);
    printf("\n");

    return 0;
}

void generate_key(unsigned char *key) {
    for (int i = 0; i < KEY_LENGTH; ++i)
        key[i] = rand() % 256;
}

unsigned char xor_byte(unsigned char byte, unsigned char key_byte) {
    return byte ^ key_byte;
}

void generate_binary_sequence(unsigned char *binary_sequence, unsigned char *key) {
    for (int i = 0; i < KEY_LENGTH; ++i) {
        binary_sequence[i] = (xor_byte(i, key[i]) % 2) ? '1' : '0';
    }
}

void xor_data(unsigned char *data, unsigned char *binary_sequence) {
    for (int i = 0; i < DATA_LENGTH; ++i) {
        for (int j = 0; j < KEY_LENGTH; ++j) {
            data[i] = xor_byte(data[i], binary_sequence[j]);
        }
    }
}