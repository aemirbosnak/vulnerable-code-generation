//Falcon-180B DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 4

void shift(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void encrypt(char *message, int *key, char *ciphertext) {
    int state[4] = {0, 0, 0, 0};
    int i, j, k, temp;
    char ch;
    for (i = 0; i < strlen(message); i++) {
        ch = tolower(message[i]);
        if (isalpha(ch)) {
            if (ch >= 'a' && ch <= 'z') {
                ch -= 'a';
            } else {
                ch -= 'A';
            }
            ch = (ch + state[2]) % 26;
            if (ch < 0) {
                ch += 26;
            }
            ch += state[0];
            if (ch > 25) {
                ch -= 26;
            }
            ciphertext[i] = ch + 'A';
        } else {
            ciphertext[i] = message[i];
        }
    }
}

void decrypt(char *ciphertext, int *key, char *message) {
    int state[4] = {0, 0, 0, 0};
    int i, j, k, temp;
    char ch;
    for (i = 0; i < strlen(ciphertext); i++) {
        ch = tolower(ciphertext[i]);
        if (isalpha(ch)) {
            if (ch >= 'a' && ch <= 'z') {
                ch -= 'a';
            } else {
                ch -= 'A';
            }
            ch = (26 - (ch - state[2])) % 26;
            if (ch < 0) {
                ch += 26;
            }
            ch -= state[0];
            if (ch < 0) {
                ch += 26;
            }
            message[i] = ch + 'A';
        } else {
            message[i] = ciphertext[i];
        }
    }
}

void generate_key(int *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void print_state(int *state) {
    printf("State: ");
    for (int i = 0; i < 4; i++) {
        printf("%d ", state[i]);
    }
    printf("\n");
}

int main() {
    char message[100];
    int key[KEY_SIZE];
    char ciphertext[100];
    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        scanf(" %c", &key[i]);
    }
    generate_key(key);
    encrypt(message, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, message);
    printf("Decrypted message: %s\n", message);
    return 0;
}