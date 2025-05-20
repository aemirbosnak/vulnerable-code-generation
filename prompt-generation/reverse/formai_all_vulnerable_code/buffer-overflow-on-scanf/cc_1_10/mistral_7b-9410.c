//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 26
#define ALPHABET_SIZE 26

unsigned char key[KEY_SIZE];
unsigned char encrypted_message[100];
unsigned char decrypted_message[100];
unsigned char plain_message[100];

void generate_key(void);
void left_shift_array(unsigned char *array, int shift);
void encode_message(void);
void decode_message(void);
void print_message(unsigned char *message);

int main() {
    generate_key();
    strcpy(plain_message, "AlanTuringIsAGoodMan");
    encode_message();
    printf("Encrypted message: ");
    print_message(encrypted_message);
    decode_message();
    printf("Decrypted message: ");
    print_message(decrypted_message);
    return 0;
}

void generate_key(void) {
    printf("Enter a key: ");
    scanf("%s", &key);
    left_shift_array(key, 1);
}

void left_shift_array(unsigned char *array, int shift) {
    unsigned char temp;
    for (int i = 0; i < KEY_SIZE; ++i) {
        if (i == KEY_SIZE - 1) {
            array[0] = array[i];
            break;
        }
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
    for (int i = 0; i < shift; ++i) {
        left_shift_array(array, 1);
    }
}

void encode_message(void) {
    for (int i = 0; i < strlen(plain_message); ++i) {
        encrypted_message[i] = plain_message[i] ^ key[i % KEY_SIZE];
    }
}

void decode_message(void) {
    for (int i = 0; i < strlen(plain_message); ++i) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % KEY_SIZE];
    }
}

void print_message(unsigned char *message) {
    for (int i = 0; i < strlen(message); ++i) {
        printf("%c", message[i]);
    }
    printf("\n");
}