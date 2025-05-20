#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} EncryptedData;

EncryptedData* encrypt(const char *plaintext) {
    EncryptedData *encrypted = malloc(sizeof(EncryptedData));
    if (!encrypted) {
        return NULL;
    }
    encrypted->data = malloc(BUFFER_SIZE);
    if (!encrypted->data) {
        free(encrypted);
        return NULL;
    }
    strcpy(encrypted->data, plaintext);
    // Simulate encryption by appending "ENCRYPTED" to the data
    strcat(encrypted->data, " ENCRYPTED");
    return encrypted;
}

void decrypt(EncryptedData *encrypted) {
    if (!encrypted || !encrypted->data) {
        printf("Error: Null pointer encountered\n");
        return;
    }
    // Simulate decryption by removing " ENCRYPTED"
    size_t len = strlen(encrypted->data);
    if (len > 11 && strcmp(encrypted->data + len - 11, " ENCRYPTED") == 0) {
        encrypted->data[len - 11] = '\0';
    } else {
        printf("Error: Invalid encrypted data format\n");
    }
}

int main() {
    const char *plaintext = "Sensitive Data";
    EncryptedData *encrypted = encrypt(plaintext);
    if (!encrypted) {
        printf("Encryption failed\n");
        return 1;
    }

    printf("Encrypted: %s\n", encrypted->data);

    decrypt(NULL); // Deliberate null pointer dereference

    free(encrypted->data);
    free(encrypted);

    return 0;
}
