#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    char *message;
    char *encrypted;
} Encryptor;

void encrypt(Encryptor *e, char *input) {
    char encrypted[256];
    int i;

    for (i = 0; input[i] != '\0'; i++) {
        encrypted[i] = e->key[(int)input[i]];
    }
    e->encrypted = encrypted;
}

int main() {
    Encryptor myEncryptor;
    myEncryptor.key = "A\0B\0C\0D\0E\0F\0G\0H\0I\0J\0K\0L\0M\0N\0O\0P\0Q\0R\0S\0T\0U\0V\0W\0X\0Y\0Z";

    char *message = "This is a test message";

    myEncryptor.message = message;
    encrypt(&myEncryptor, message);

    printf("Encrypted message: %s\n", myEncryptor.encrypted);

    // Accessing key member that was not properly initialized
    printf("Key: %s\n", myEncryptor.key);

    return 0;
}
