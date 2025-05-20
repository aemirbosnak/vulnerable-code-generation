//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char *key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=[{]}\\|;:'\",.<>/?";
    int i;
    for (i = 0; i < length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + (key[j] - 65) % 26);
            } else {
                message[i] = toupper(message[i] + (key[j] - 97) % 26);
            }
        } else {
            message[i] = message[i];
        }
        j = (j + 1) % strlen(key);
    }
}

void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] - (key[j] - 65) % 26);
            } else {
                message[i] = toupper(message[i] - (key[j] - 97) % 26);
            }
        }
        j = (j + 1) % strlen(key);
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int message_length, key_length;
    printf("Enter message length (max %d): ", MAX_MESSAGE_LENGTH - 1);
    scanf("%d", &message_length);
    printf("Enter message: ");
    scanf("%s", message);
    generate_key(key, message_length);
    printf("Encrypted message: %s\n", message);
    encrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}