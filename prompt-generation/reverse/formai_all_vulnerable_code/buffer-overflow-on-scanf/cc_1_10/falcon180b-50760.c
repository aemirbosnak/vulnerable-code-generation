//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char* message, char* key) {
    char encrypted_message[MAX_SIZE];
    int message_length = strlen(message);
    int key_length = strlen(key);
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int shift = (int)key[j] % 26;
            if (isupper(message[i])) {
                encrypted_message[i] = (char)((int)message[i] + shift - 65);
            } else {
                encrypted_message[i] = (char)((int)message[i] + shift - 97);
            }
            j++;
            if (j >= key_length) {
                j = 0;
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    char decrypted_message[MAX_SIZE];
    int message_length = strlen(message);
    int key_length = strlen(key);
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int shift = (int)key[j] % 26;
            if (isupper(message[i])) {
                decrypted_message[i] = (char)((int)message[i] - shift - 65 + 26) % 26 + 65;
            } else {
                decrypted_message[i] = (char)((int)message[i] - shift - 97 + 26) % 26 + 97;
            }
            j++;
            if (j >= key_length) {
                j = 0;
            }
        } else {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    printf("Enter message to be encrypted: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}