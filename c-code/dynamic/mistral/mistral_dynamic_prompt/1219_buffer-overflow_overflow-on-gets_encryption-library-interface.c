#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void encrypt(char *input) {
    char key[] = "SECRET_KEY";
    char encrypted[BUFFER_SIZE];

    for (int i = 0; input[i]; i++) {
        encrypted[i] = input[i] ^ key[i % strlen(key)];
    }

    encrypted[strlen(input)] = '\0';
}

int main(int argc, char *argv[]) {
    char userInput[BUFFER_SIZE];
    printf("Enter the message to encrypt:\n");
    gets(userInput);

    encrypt(userInput);
    printf("Encrypted message: %s\n", userInput);

    return 0;
}
