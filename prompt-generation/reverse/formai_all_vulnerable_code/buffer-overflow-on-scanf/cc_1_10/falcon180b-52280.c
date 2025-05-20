//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define KEY "secretkey"

void encrypt(char* message, char* encrypted_message) {
    int i, j, k;
    char key[strlen(KEY)];
    strcpy(key, KEY);

    for (i = 0; i < strlen(message); i++) {
        message[i] = tolower(message[i]);
    }

    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = '\0';
        for (j = 0; j < strlen(key); j++) {
            k = (int)key[j] - 97;
            encrypted_message[i] += message[i] - 97 + k;
        }
    }
}

void decrypt(char* encrypted_message, char* decrypted_message) {
    int i, j, k;
    char key[strlen(KEY)];
    strcpy(key, KEY);

    for (i = 0; i < strlen(encrypted_message); i++) {
        encrypted_message[i] = tolower(encrypted_message[i]);
    }

    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = '\0';
        for (j = 0; j < strlen(key); j++) {
            k = (int)key[j] - 97;
            decrypted_message[i] += encrypted_message[i] - 97 - k;
        }
    }
}

int main() {
    char message[SIZE], encrypted_message[SIZE], decrypted_message[SIZE];
    printf("Enter a message: ");
    scanf("%s", message);

    encrypt(message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}