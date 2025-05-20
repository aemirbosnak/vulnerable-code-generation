//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_SIZE 1024

char *encrypt(char *message, int key) {
    int i, j;
    char *result = (char *)malloc(MAX_SIZE);
    memset(result, 0, MAX_SIZE);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j++] = (char)(((int)message[i] + key - 65) % 26 + 65);
            } else {
                result[j++] = (char)(((int)message[i] + key - 97) % 26 + 97);
            }
        } else {
            result[j++] = message[i];
        }
    }

    return result;
}

int decrypt(char *message, int key) {
    int i, j;
    char *result = (char *)malloc(MAX_SIZE);
    memset(result, 0, MAX_SIZE);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                result[j++] = (char)(((int)message[i] - key - 65) % 26 + 65);
            } else {
                result[j++] = (char)(((int)message[i] - key - 97) % 26 + 97);
            }
        } else {
            result[j++] = message[i];
        }
    }

    return result;
}

int main() {
    char message[MAX_SIZE];
    int key, choice;

    printf("Enter a message to encrypt/decrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the encryption/decryption key (1-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char *encrypted = encrypt(message, key);
        printf("Encrypted message: %s\n", encrypted);
    } else if (choice == 2) {
        char *decrypted = decrypt(message, key);
        printf("Decrypted message: %s\n", decrypted);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}