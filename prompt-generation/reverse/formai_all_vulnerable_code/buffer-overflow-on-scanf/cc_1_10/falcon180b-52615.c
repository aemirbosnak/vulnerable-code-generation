//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define ASCII_SIZE 128
#define KEY_SIZE 16
#define MAX_SIZE 10000

unsigned char key[KEY_SIZE] = "mysecretkey123";
unsigned char ascii[ASCII_SIZE] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?~`";

void encrypt(unsigned char* input, int length) {
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (isalpha(input[j])) {
            input[j] = ascii[(int)input[j] - 97] ^ key[i % KEY_SIZE];
            i++;
        } else {
            input[j] = input[j];
        }
    }
}

void decrypt(unsigned char* input, int length) {
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (isalpha(input[j])) {
            input[j] = ascii[(int)input[j] - 97] ^ key[i % KEY_SIZE];
            i++;
        } else {
            input[j] = input[j];
        }
    }
}

int main() {
    unsigned char input[MAX_SIZE];
    int length;

    printf("Enter the text to be encrypted: ");
    scanf("%s", input);

    length = strlen(input);

    encrypt(input, length);

    printf("Encrypted text: %s\n", input);

    decrypt(input, length);

    printf("Decrypted text: %s\n", input);

    return 0;
}