#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption library function with a buffer overflow vulnerability
void encrypt(char* input, char* output, int key) {
    int len = strlen(input);
    if (len > 50) {
        printf("Input length too long for encryption.\n");
        return;
    }

    strcpy(output, "Your encrypted message: ");
    strcat(output, input);
    strcat(output, " - Encryption key: ");
    char buf[6];
    sprintf(buf, "%d", key);
    strcat(output, buf);
}

int main() {
    char userInput[100];
    int key;

    printf("Enter a message to encrypt (max 50 chars): ");
    fgets(userInput, 100, stdin);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    char encrypted[200];
    encrypt(userInput, encrypted, key);

    printf("\nEncrypted message: %s\n", encrypted);
    return 0;
}
