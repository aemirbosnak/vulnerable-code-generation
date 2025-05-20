#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 100

void encrypt(char *key, char *plaintext, char *ciphertext, int *length) {
    char buffer[MAX_KEY_LENGTH];
    strcpy(buffer, key);
    strcat(buffer, plaintext);
    *ciphertext = malloc(strlen(buffer));
    strcpy(*ciphertext, buffer);
    *length = strlen(buffer);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char plaintext[1024];
    char *ciphertext;
    int length;

    printf("Enter your secret key:\n");
    scanf("%s", key);
    printf("Enter the message to encrypt:\n");
    scanf("%s", plaintext);

    encrypt(key, plaintext, &ciphertext, &length);
    printf("Your encrypted message is: %s of length %d\n", ciphertext, length);

    free(ciphertext);

    return 0;
}
