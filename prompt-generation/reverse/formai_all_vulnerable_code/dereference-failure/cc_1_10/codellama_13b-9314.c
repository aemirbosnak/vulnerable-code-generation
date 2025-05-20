//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 256
#define KEY_SPACE 256

char* encrypt(char* msg, char* key) {
    int msg_len = strlen(msg);
    int key_len = strlen(key);
    int i, j;
    char* encrypted_msg = (char*)malloc(msg_len + 1);

    for (i = 0, j = 0; i < msg_len; i++, j++) {
        if (j == key_len) j = 0;
        encrypted_msg[i] = msg[i] + key[j];
    }

    return encrypted_msg;
}

char* decrypt(char* msg, char* key) {
    int msg_len = strlen(msg);
    int key_len = strlen(key);
    int i, j;
    char* decrypted_msg = (char*)malloc(msg_len + 1);

    for (i = 0, j = 0; i < msg_len; i++, j++) {
        if (j == key_len) j = 0;
        decrypted_msg[i] = msg[i] - key[j];
    }

    return decrypted_msg;
}

int main() {
    char* msg = "Hello, World!";
    char* key = "My Secret Key";
    char* encrypted_msg = encrypt(msg, key);
    char* decrypted_msg = decrypt(encrypted_msg, key);

    printf("Original message: %s\n", msg);
    printf("Encrypted message: %s\n", encrypted_msg);
    printf("Decrypted message: %s\n", decrypted_msg);

    free(encrypted_msg);
    free(decrypted_msg);

    return 0;
}