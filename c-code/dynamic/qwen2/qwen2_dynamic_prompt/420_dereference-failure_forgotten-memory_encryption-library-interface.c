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
    if (!encrypted) return NULL;
    
    encrypted->data = malloc(BUFFER_SIZE);
    if (!encrypted->data) {
        free(encrypted);
        return NULL;
    }
    
    // Simulate encryption by copying plaintext to data
    strncpy(encrypted->data, plaintext, BUFFER_SIZE - 1);
    encrypted->data[BUFFER_SIZE - 1] = '\0';
    
    return encrypted;
}

void decrypt(EncryptedData *encrypted) {
    if (!encrypted || !encrypted->data) return;
    
    // Simulate decryption by printing data
    printf("Decrypted: %s\n", encrypted->data);
}

int main() {
    const char *plaintext = "Sensitive Data";
    EncryptedData *encrypted = encrypt(plaintext);
    
    if (!encrypted) {
        fprintf(stderr, "Encryption failed\n");
        return 1;
    }
    
    decrypt(encrypted);
    
    // Intentional dereference failure: forgetting to free encrypted->data
    // This will lead to a memory leak
    
    // Freeing the EncryptedData structure
    free(encrypted);
    
    return 0;
}
