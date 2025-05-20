//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
#define KEY 0x12345678

void encrypt(char* input, char* output, int key) {
    int i, j, k;
    unsigned char temp;

    for (i = 0, j = 0; i < strlen(input); i++) {
        temp = input[i];
        for (k = 0; k < 8; k++) {
            temp = ((temp & 0x80) >> 7) | (temp << 1);
        }
        output[j++] = temp ^ key;
    }
    output[j] = '\0';
}

void decrypt(char* input, char* output, int key) {
    int i, j, k;
    unsigned char temp;

    for (i = 0, j = 0; i < strlen(input); i++) {
        temp = input[i] ^ key;
        for (k = 0; k < 8; k++) {
            temp = ((temp & 0x80) >> 7) | (temp << 1);
        }
        output[j++] = temp;
    }
    output[j] = '\0';
}

int main() {
    char input[SIZE];
    char output[SIZE];

    printf("Enter message to encrypt: ");
    scanf("%s", input);

    encrypt(input, output, KEY);

    printf("Encrypted message: %s\n", output);

    decrypt(output, output, KEY);

    printf("Decrypted message: %s\n", output);

    return 0;
}