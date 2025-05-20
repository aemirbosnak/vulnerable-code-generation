//Falcon-180B DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100

void generate_key(char *key, int key_length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt(char *message, char *key, char *ciphertext, int key_length) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext[j] = 'A' + ((message[i] - 65 + key[j % key_length] - 65) % 26) + 65;
            } else {
                ciphertext[j] = 'a' + ((message[i] - 97 + key[j % key_length] - 97) % 26) + 97;
            }
        } else {
            ciphertext[j] = message[i];
        }
        j++;
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message, int key_length) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                message[j] = 'A' + (((ciphertext[i] - 65 - key[j % key_length] + 26) % 26) + 65);
            } else {
                message[j] = 'a' + (((ciphertext[i] - 97 - key[j % key_length] + 26) % 26) + 97);
            }
        } else {
            message[j] = ciphertext[i];
        }
        j++;
    }
    message[j] = '\0';
}

int main() {
    char message[1000], key[MAX_KEY_LENGTH], ciphertext[1000];
    int key_length;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter key length (maximum %d): ", MAX_KEY_LENGTH);
    scanf("%d", &key_length);

    generate_key(key, key_length);

    printf("Encrypted message: ");
    encrypt(message, key, ciphertext, key_length);
    printf("%s\n", ciphertext);

    printf("Decrypted message: ");
    decrypt(ciphertext, key, message, key_length);
    printf("%s\n", message);

    return 0;
}