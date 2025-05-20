//FormAI DATASET v1.0 Category: modern Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryption(char str[], int key) {
    int len = strlen(str);
    int i, j;
    char encrypted_message[len];

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            encrypted_message[i] = 'a' + ((str[i] - 'a' + key) % 26);
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            encrypted_message[i] = 'A' + ((str[i] - 'A' + key) % 26);
        } else {
            encrypted_message[i] = str[i];
        }
    }

    printf("Encrypted message: %s", encrypted_message);
}

void decryption(char str[], int key) {
    int len = strlen(str);
    int i, j;
    char decrypted_message[len];

    for (i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] - key < 'a') {
                decrypted_message[i] = 'z' - (key - (str[i] - 'a') - 1);
            } else {
                decrypted_message[i] = str[i] - key;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] - key < 'A') {
                decrypted_message[i] = 'Z' - (key - (str[i] - 'A') - 1);
            } else {
                decrypted_message[i] = str[i] - key;
            }
        } else {
            decrypted_message[i] = str[i];
        }
    }

    printf("Decrypted message: %s", decrypted_message);
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    do {
        printf("Enter key (1-25): ");
        scanf("%d", &key);
    } while (key < 1 || key > 25);

    printf("\nMessage: %s", message);
    encryption(message, key);

    printf("\n\n");

    printf("Enter message to decrypt: ");
    fgets(message, 100, stdin);

    do {
        printf("Enter key (1-25): ");
        scanf("%d", &key);
    } while (key < 1 || key > 25);

    printf("\nMessage: %s", message);
    decryption(message, key);

    return 0;
}