#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define KEY_SIZE 100
#define BLOCK_SIZE 1024

typedef struct {
    char name[20];
    char key[KEY_SIZE];
} Key;

void encode(Key*, char*);
void decode(Key*, char*);

int main() {
    Key my_key = {"My Secret Key", ""};
    char input[BLOCK_SIZE], output[BLOCK_SIZE];

    printf("Enter data to encrypt:\n");
    scanf("%s", input);

    encode(&my_key, input);
    printf("Encrypted data:\n%s\n", output);

    printf("Enter data to decrypt:\n");
    scanf("%s", input);
    decode(&my_key, input);
    printf("Decrypted data:\n%s\n", output);

    return 0;
}

void encode(Key* key, char* data) {
    int i, j;
    for (i = 0, j = KEY_SIZE - 1; i < strlen(data); i++, j--) {
        key->key[j] = key->key[j] + data[i];
        if (key->key[j] > 255) key->key[j] -= 256;
    }
    key->key[0] = strlen(data);
}

void decode(Key* key, char* data) {
    int i, j;
    for (i = key->key[0] - 1, j = 0; i >= 0; i--, j++) {
        data[j] = data[j] - key->key[i];
        if (data[j] < 0) data[j] += 256;
    }
}
