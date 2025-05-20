//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *input, char *key) {
    int i, j;
    char buffer[BUFFER_SIZE];

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        buffer[i] = input[i] + key[j];
    }

    for (i = 0; i < strlen(input); i++) {
        input[i] = buffer[i];
    }
}

void decrypt(char *input, char *key) {
    int i, j;
    char buffer[BUFFER_SIZE];

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (j == strlen(key)) {
            j = 0;
        }
        buffer[i] = input[i] - key[j];
    }

    for (i = 0; i < strlen(input); i++) {
        input[i] = buffer[i];
    }
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    char choice;

    printf("Enter input string: ");
    scanf("%s", input);
    printf("Enter encryption key: ");
    scanf("%s", key);

    printf("Encrypt (e) or decrypt (d)? ");
    scanf("%c", &choice);

    if (choice == 'e') {
        encrypt(input, key);
    } else if (choice == 'd') {
        decrypt(input, key);
    } else {
        printf("Invalid choice\n");
        return 1;
    }

    printf("Encrypted/decrypted string: %s\n", input);

    return 0;
}