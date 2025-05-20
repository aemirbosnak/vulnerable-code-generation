//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    int size;
    char *input;
} crypt_t;

char *encrypt(crypt_t *crypt) {
    char *output = malloc(strlen(crypt->input) + 1);
    int i = 0;
    for (i = 0; i < strlen(crypt->input); i++) {
        if (crypt->input[i] >= 'a' && crypt->input[i] <= 'z') {
            output[i] = (char) (((crypt->input[i] - 'a' + crypt->key) % 26) + 'a');
        } else if (crypt->input[i] >= 'A' && crypt->input[i] <= 'Z') {
            output[i] = (char) (((crypt->input[i] - 'A' + crypt->key) % 26) + 'A');
        } else {
            output[i] = crypt->input[i];
        }
    }
    output[strlen(crypt->input)] = '\0';
    return output;
}

int main() {
    crypt_t crypt;
    char *input;
    char *output;
    int i;

    printf("Enter the key: ");
    scanf("%d", &crypt.key);

    printf("Enter the message: ");
    scanf("%s", input);

    crypt.size = strlen(input);
    crypt.input = input;

    output = encrypt(&crypt);

    printf("Encrypted message: ");
    for (i = 0; i < crypt.size; i++) {
        printf("%c", output[i]);
    }

    free(output);
    return 0;
}