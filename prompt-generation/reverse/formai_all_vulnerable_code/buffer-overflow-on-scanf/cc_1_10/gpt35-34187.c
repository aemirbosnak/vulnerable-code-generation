//FormAI DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *data, char *key) {
    int data_length = strlen(data);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < data_length; ++i, ++j) {
        if (j == key_length)
            j = 0;
        data[i] ^= key[j];
    }
}

void decrypt(char *data, char *key) {
    encrypt(data, key);
}

int main() {
    char data[1000];
    char key[100];

    printf("Enter the data you want to encrypt: ");
    fgets(data, 1000, stdin);
    printf("Enter the encryption key: ");
    fgets(key, 100, stdin);

    int choice;
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(data, key);
            printf("Your encrypted data is: %s\n", data);
            break;
        case 2:
            decrypt(data, key);
            printf("Your decrypted data is: %s\n", data);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}