//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(char* input, char* output) {
    int i, j;
    char temp[BLOCK_SIZE];
    for (i = 0; i < strlen(input); i += BLOCK_SIZE) {
        strncpy(temp, input + i, BLOCK_SIZE);
        temp[BLOCK_SIZE] = '\0';
        for (j = 0; j < strlen(temp); j++) {
            if (isalpha(temp[j])) {
                if (isupper(temp[j])) {
                    temp[j] = (temp[j] - 'A' + 'a') ^ KEY[j % strlen(KEY)];
                } else {
                    temp[j] = (temp[j] - 'a' + 'A') ^ KEY[j % strlen(KEY)];
                }
            } else {
                temp[j] = temp[j];
            }
        }
        strncat(output, temp, BLOCK_SIZE);
    }
}

void decrypt(char* input, char* output) {
    int i, j;
    char temp[BLOCK_SIZE];
    for (i = 0; i < strlen(input); i += BLOCK_SIZE) {
        strncpy(temp, input + i, BLOCK_SIZE);
        temp[BLOCK_SIZE] = '\0';
        for (j = 0; j < strlen(temp); j++) {
            if (isalpha(temp[j])) {
                if (isupper(temp[j])) {
                    temp[j] = (temp[j] - 'A' + 'a') ^ KEY[j % strlen(KEY)];
                } else {
                    temp[j] = (temp[j] - 'a' + 'A') ^ KEY[j % strlen(KEY)];
                }
            } else {
                temp[j] = temp[j];
            }
        }
        strncat(output, temp, BLOCK_SIZE);
    }
}

int main() {
    char input[1000], output[1000];
    printf("Enter the text to encrypt:\n");
    scanf("%s", input);
    encrypt(input, output);
    printf("Encrypted text: %s\n", output);
    printf("Enter the encrypted text to decrypt:\n");
    scanf("%s", input);
    decrypt(input, output);
    printf("Decrypted text: %s\n", output);
    return 0;
}