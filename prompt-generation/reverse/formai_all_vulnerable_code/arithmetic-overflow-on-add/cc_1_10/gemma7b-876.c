//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *msg, *key, *enc_msg;
    int msg_len, key_len, enc_len;

    // Dynamic memory allocation for message, key, and encrypted message
    msg = malloc(1024);
    key = malloc(1024);
    enc_msg = malloc(1024);

    // Get the message length, key length, and message
    printf("Enter the message length: ");
    scanf("%d", &msg_len);

    printf("Enter the key length: ");
    scanf("%d", &key_len);

    printf("Enter the message: ");
    scanf("%s", msg);

    // Encrypt the message
    enc_len = encrypt(msg, key, msg_len, key_len, enc_msg);

    // Print the encrypted message
    printf("The encrypted message is: ");
    printf("%s", enc_msg);

    // Free the memory allocated for message, key, and encrypted message
    free(msg);
    free(key);
    free(enc_msg);

    return 0;
}

int encrypt(char *msg, char *key, int msg_len, int key_len, char *enc_msg) {
    int i, j, k, enc_len = 0;

    // Calculate the encrypted message length
    enc_len = msg_len + key_len - 1;

    // Allocate memory for the encrypted message
    enc_msg = malloc(enc_len);

    // Encrypt the message
    for (i = 0; i < msg_len; i++) {
        for (j = 0; j < key_len; j++) {
            k = (msg[i] - 97) ^ (key[j] - 97);
            enc_msg[enc_len] = k + 97;
            enc_len++;
        }
    }

    return enc_len;
}