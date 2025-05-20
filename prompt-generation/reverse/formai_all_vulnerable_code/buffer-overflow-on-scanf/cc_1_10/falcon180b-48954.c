//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 64
#define MAX_MSG_LEN 1000
#define ALPHABET_LEN 26

char alphabet[ALPHABET_LEN] = "abcdefghijklmnopqrstuvwxyz";

void generate_key(char key[], int key_len) {
    int i;
    for (i = 0; i < key_len; i++) {
        key[i] = alphabet[rand() % ALPHABET_LEN];
    }
}

void encrypt(char msg[], char key[], char encrypted_msg[]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                encrypted_msg[j] = key[(int)msg[i] - 65];
            } else {
                encrypted_msg[j] = key[(int)msg[i] - 97];
            }
            j++;
        } else {
            encrypted_msg[j] = msg[i];
            j++;
        }
    }
    encrypted_msg[j] = '\0';
}

void decrypt(char encrypted_msg[], char key[], char msg[]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_msg); i++) {
        if (isalpha(encrypted_msg[i])) {
            if (isupper(encrypted_msg[i])) {
                msg[j] = (char)((int)encrypted_msg[i] + 65);
            } else {
                msg[j] = (char)((int)encrypted_msg[i] + 97);
            }
            j++;
        } else {
            msg[j] = encrypted_msg[i];
            j++;
        }
    }
    msg[j] = '\0';
}

int main() {
    char msg[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
    char encrypted_msg[MAX_MSG_LEN];
    char decrypted_msg[MAX_MSG_LEN];
    int msg_len, key_len;

    printf("Enter message to encrypt: ");
    scanf("%s", msg);
    msg_len = strlen(msg);

    printf("Enter key length (1-64): ");
    scanf("%d", &key_len);

    if (key_len > MAX_KEY_LEN || key_len < 1) {
        printf("Invalid key length.\n");
        return 1;
    }

    generate_key(key, key_len);

    encrypt(msg, key, encrypted_msg);

    printf("Encrypted message: %s\n", encrypted_msg);

    decrypt(encrypted_msg, key, decrypted_msg);

    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}