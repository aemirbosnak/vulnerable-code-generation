//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000


void encrypt(char* input, char* key, char* output) {
    int i, j, k;
    for(i = 0, j = 0; i < strlen(input); i++, j++) {
        if(j == strlen(key)) {
            j = 0;
        }
        output[i] = input[i] ^ key[j];
    }
    output[strlen(input)] = '\0';
}

void decrypt(char* input, char* key, char* output) {
    int i, j, k;
    for(i = 0, j = 0; i < strlen(input); i++, j++) {
        if(j == strlen(key)) {
            j = 0;
        }
        output[i] = input[i] ^ key[j];
    }
    output[strlen(input)] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];
    char key[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];

    printf("Enter the input string: ");
    scanf("%s", input);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(input, key, output);

    printf("Encrypted string: %s\n", output);

    decrypt(output, key, input);

    printf("Decrypted string: %s\n", input);

    return 0;
}