//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64
#define ROUNDS 64

void expand_key(char *key, int key_size, char *expanded_key) {
    int i, j;
    char temp[KEY_SIZE * 2];
    for (i = 0; i < key_size; i++) {
        temp[i] = key[i];
        temp[i + key_size] = key[i];
    }
    for (i = key_size * 2; i < KEY_SIZE * 2; i++) {
        temp[i] = 'A';
    }
    for (i = 0; i < KEY_SIZE * 2; i++) {
        expanded_key[i] = temp[i];
    }
}

void encrypt(char *plain_text, char *expanded_key, char *cipher_text) {
    int i, j, k;
    char temp[BLOCK_SIZE];

    for (i = 0; i < strlen(plain_text); i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < strlen(plain_text); j++) {
            temp[j] = plain_text[i + j];
        }
        for (j = 0; j < BLOCK_SIZE; j++) {
            k = (int) temp[j] + (int) expanded_key[j];
            if (k > 'Z') {
                k -= 26;
            } else if (k < 'A') {
                k += 26;
            }
            cipher_text[i + j] = k;
        }
    }
}

int main() {
    char plain_text[1000], expanded_key[KEY_SIZE * 2], cipher_text[1000];
    int key_size;

    printf("Enter the key size (must be a multiple of 8 and less than or equal to 16): ");
    scanf("%d", &key_size);

    if (key_size % 8!= 0 || key_size > 16) {
        printf("Invalid key size.\n");
        return 1;
    }

    printf("Enter the key: ");
    scanf("%s", plain_text);

    expand_key(plain_text, key_size, expanded_key);
    encrypt(plain_text, expanded_key, cipher_text);

    printf("Plain text: %s\n", plain_text);
    printf("Expanded key: %s\n", expanded_key);
    printf("Cipher text: %s\n", cipher_text);

    return 0;
}