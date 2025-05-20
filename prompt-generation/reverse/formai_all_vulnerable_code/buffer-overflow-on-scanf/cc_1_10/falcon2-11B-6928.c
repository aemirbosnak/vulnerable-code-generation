//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 100

void generateKey() {
    int key[10] = {0};
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        key[i] = rand() % 10;
    }
    printf("Generated key: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");
}

void encrypt(char* input, int inputSize, int* output, int outputSize) {
    int key[10] = {0};
    generateKey();

    int i, j;
    for (i = 0; i < inputSize; i++) {
        output[i] = (input[i] + key[i % 10]) % 10;
    }
    printf("Encrypted: ");
    for (i = 0; i < inputSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
}

void decrypt(char* input, int inputSize, int* output, int outputSize) {
    int key[10] = {0};
    generateKey();

    int i, j;
    for (i = 0; i < inputSize; i++) {
        output[i] = (input[i] + key[i % 10]) % 10;
    }
    printf("Decrypted: ");
    for (i = 0; i < inputSize; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    int output[MAX_INPUT_SIZE];
    int inputSize = 0;
    int outputSize = 0;

    printf("Enter input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    inputSize = strlen(input);

    printf("Enter output size: ");
    scanf("%d", &outputSize);

    encrypt(input, inputSize, output, outputSize);
    decrypt(output, outputSize, output, outputSize);

    return 0;
}