#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* text;
} Encryptor;

Encryptor init(const char* key, const char* text) {
    Encryptor encryptor;
    encryptor.key = strdup(key);
    encryptor.text = strdup(text);
    return encryptor;
}

void print_encrypted(Encryptor encryptor) {
    char buffer[10];
    for (size_t i = 0; i < strlen(encryptor.text); i++) {
        sscanf(encryptor.text + i, "%10s", buffer);
        printf("%s", buffer);
    }
}

int main() {
    Encryptor encryption = init("secret", "Thisisasecretmessage!");
    print_encrypted(encryption);

    return 0;
}
