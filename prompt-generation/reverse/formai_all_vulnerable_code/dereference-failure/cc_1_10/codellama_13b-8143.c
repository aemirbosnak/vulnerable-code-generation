//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
/*
 *  Image Steganography in C - Sherlock Holmes Style
 *  by @<Your Name>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_MESSAGE_LEN 1000

void encrypt_message(char *message, char *key) {
    int i, j, k;
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *encrypted_message = malloc(message_len + 1);

    for (i = 0, j = 0, k = 0; i < message_len; i++) {
        if (j == key_len) j = 0;
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = ((message[i] - 'A' + key[j] - 'A') % 26) + 'A';
            } else {
                encrypted_message[i] = ((message[i] - 'a' + key[j] - 'a') % 26) + 'a';
            }
            j++;
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt_message(char *message, char *key) {
    int i, j, k;
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *decrypted_message = malloc(message_len + 1);

    for (i = 0, j = 0, k = 0; i < message_len; i++) {
        if (j == key_len) j = 0;
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = ((message[i] - key[j] + 26) % 26) + 'A';
            } else {
                decrypted_message[i] = ((message[i] - key[j] + 26) % 26) + 'a';
            }
            j++;
        } else {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char key[] = "THE FIVE SLENDER HORSES COME OUT AT DAWN";

    encrypt_message(message, key);
    decrypt_message(message, key);

    return 0;
}