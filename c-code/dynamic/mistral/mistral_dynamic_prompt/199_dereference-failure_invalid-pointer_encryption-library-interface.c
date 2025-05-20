#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char* key;
    char* data;
} Encryption;

void encrypt(Encryption* e) {
    char shift = atoi(e->key);

    for (int i = 0; e->data[i]; i++) {
        printf("%c", e->data[i] + shift);
    }
}

int main() {
    Encryption myEncryption;

    myEncryption.key = malloc(5 * sizeof(char));
    myEncryption.data = malloc(100 * sizeof(char));

    strcpy(myEncryption.key, "13");
    strcpy(myEncryption.data, "Hello, World!");

    encrypt(&myEncryption);

    free(myEncryption.key);
    free(myEncryption.data);
    return 0;
}
