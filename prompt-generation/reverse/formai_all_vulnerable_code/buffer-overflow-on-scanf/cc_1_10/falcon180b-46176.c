//Falcon-180B DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_MSG_LEN 1000

void generate_key(char key[], int key_len) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < key_len; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt(char msg[], char key[], int key_len) {
    int i, j;
    for (i = 0, j = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                msg[i] = 'A' + (msg[i] - 'A' + j) % 26;
            } else {
                msg[i] = 'a' + (msg[i] - 'a' + j) % 26;
            }
        }
        j = (j + key[i % key_len]) % key_len;
    }
}

void decrypt(char msg[], char key[], int key_len) {
    int i, j;
    for (i = 0, j = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                msg[i] = 'A' + (msg[i] - 'A' - j + 26) % 26;
            } else {
                msg[i] = 'a' + (msg[i] - 'a' - j + 26) % 26;
            }
        }
        j = (j - key[i % key_len] + 26) % key_len;
    }
}

int main() {
    char msg[MAX_MSG_LEN], key[MAX_KEY_LEN];
    int msg_len, key_len;

    printf("Enter message length (<= %d): ", MAX_MSG_LEN - 1);
    scanf("%d", &msg_len);
    printf("Enter message: ");
    scanf("%s", msg);

    printf("Enter key length (<= %d): ", MAX_KEY_LEN - 1);
    scanf("%d", &key_len);
    generate_key(key, key_len);

    encrypt(msg, key, key_len);
    printf("Encrypted message: %s\n", msg);

    decrypt(msg, key, key_len);
    printf("Decrypted message: %s\n", msg);

    return 0;
}