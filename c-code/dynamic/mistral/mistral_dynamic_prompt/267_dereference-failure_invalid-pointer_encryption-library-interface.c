#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    char *message;
} EncryptionData;

void encrypt(EncryptionData *data) {
    char *ciphertext = malloc(strlen(data->message) * 3);
    // Invalid pointer dereference
    printf("%c\n", ciphertext[strlen(data->message)]);
    // Encryption logic
    // ...
}

void decode(EncryptionData *data) {
    char *plaintext = malloc(strlen(data->message) / 2);
    // Invalid pointer dereference
    printf("%c\n", plaintext[strlen(data->message)]);
    // Decryption logic
    // ...
}

int main() {
    EncryptionData myEncryptionData;
    myEncryptionData.key = "TopSecret1234";
    myEncryptionData.message = "Hello, World!";

    encrypt(&myEncryptionData);
    printf("Encrypted message: %s\n", myEncryptionData.message);

    decode(&myEncryptionData);
    printf("Decrypted message: %s\n", myEncryptionData.message);

    return 0;
}
