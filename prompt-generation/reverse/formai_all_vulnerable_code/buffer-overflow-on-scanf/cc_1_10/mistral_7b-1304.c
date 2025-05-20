//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define KEY_SIZE 32
#define MESSAGE_SIZE 100
#define BLOCK_SIZE 4
#define MASK 0xF0

char key[KEY_SIZE];
char message[MESSAGE_SIZE];
char encrypted_message[MESSAGE_SIZE];
int i, j, k;

void generate_key(void) {
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void xor_encrypt(void) {
    for (i = 0; i < MESSAGE_SIZE; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            for (k = 0; k < CHAR_BIT; k++) {
                if (message[i + j] != '\0') {
                    encrypted_message[i + j] =
                        (char) (message[i + j] ^ key[(i + j) % KEY_SIZE] >> k & MASK);
                }
            }
        }
    }
}

void print_message(char* msg) {
    printf("%s", msg);
}

int main(void) {
    generate_key();
    printf("Enter your secret message: ");
    scanf("%s", message);

    xor_encrypt();

    printf("\nEncrypted message: ");
    print_message(encrypted_message);

    return 0;
}