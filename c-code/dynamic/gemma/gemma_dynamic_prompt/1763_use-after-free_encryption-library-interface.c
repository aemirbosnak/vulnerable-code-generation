#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *key = "Secret key";
    char *msg = "This is a secret message";
    char *enc_msg = NULL;
    int enc_len = 0;

    enc_len = encrypt(msg, key, &enc_msg);
    if (enc_len > 0) {
        printf("Encrypted message: %s\n", enc_msg);
    } else {
        printf("Error encrypting message.\n");
    }

    free(enc_msg);
    return 0;
}

int encrypt(char *msg, char *key, char **enc_msg) {
    int msg_len = strlen(msg);
    int key_len = strlen(key);
    int enc_len = 0;
    *enc_msg = NULL;

    *enc_msg = malloc(msg_len + key_len);
    if (*enc_msg == NULL) {
        return -1;
    }

    // Implement encryption algorithm here
    memcpy(*enc_msg, msg, msg_len);
    enc_len = msg_len;

    return enc_len;
}
