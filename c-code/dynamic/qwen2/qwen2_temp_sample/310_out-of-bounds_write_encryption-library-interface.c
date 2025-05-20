#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(const char *key, char *data, size_t length) {
    size_t key_length = strlen(key);
    for (size_t i = 0; i < length; ++i) {
        data[i] += key[i % key_length];
    }
}

int main() {
    const char *key = "secret";
    char data[26]; // Allocated buffer for 25 characters plus null terminator

    // Simulate reading sensitive data from an untrusted source
    printf("Enter data to encrypt: ");
    fgets(data, sizeof(data), stdin);

    // Encrypt the data with a hardcoded key
    encrypt(key, data, 31); // Deliberate out-of-bounds write beyond the allocated buffer

    printf("Encrypted data: %s\n", data);

    return 0;
}
