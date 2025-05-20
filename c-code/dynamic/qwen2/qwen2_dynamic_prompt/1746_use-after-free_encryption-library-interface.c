#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} EncryptionKey;

EncryptionKey* create_key(const char *key) {
    EncryptionKey *key_struct = (EncryptionKey*)malloc(sizeof(EncryptionKey));
    if (key_struct == NULL) {
        return NULL;
    }
    key_struct->data = (char*)malloc(BUFFER_SIZE);
    if (key_struct->data == NULL) {
        free(key_struct);
        return NULL;
    }
    strncpy(key_struct->data, key, BUFFER_SIZE - 1);
    key_struct->data[BUFFER_SIZE - 1] = '\0';
    return key_struct;
}

void destroy_key(EncryptionKey *key) {
    if (key != NULL) {
        free(key->data);
        free(key);
    }
}

void encrypt_data(const EncryptionKey *key, char *data) {
    if (key == NULL || data == NULL) {
        return;
    }
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] ^= key->data[i % strlen(key->data)];
    }
}

int main() {
    EncryptionKey *key = create_key("secret");
    if (key == NULL) {
        fprintf(stderr, "Failed to create encryption key\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    printf("Enter data to encrypt: ");
    fgets(buffer, sizeof(buffer), stdin);

    encrypt_data(key, buffer);
    printf("Encrypted data: %s\n", buffer);

    // Use after free vulnerability
    char *ptr = key->data;
    destroy_key(key);
    key = NULL;

    // Exploit the use after free
    strcpy(ptr, "Exploited");

    printf("Data after free: %s\n", ptr);

    return 0;
}
