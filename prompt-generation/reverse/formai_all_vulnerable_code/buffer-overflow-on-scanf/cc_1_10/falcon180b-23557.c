//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024
#define MAX_ENCRYPTED_LENGTH (MAX_MESSAGE_LENGTH + 1)

int generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = toupper(rand() % 26 + 'A');
    }
    key[length] = '\0';
    return 0;
}

int encrypt(char* message, char* key) {
    int i, j, k;
    char encrypted[MAX_ENCRYPTED_LENGTH];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted[j++] = (char) (((int) message[i] - 65 + (int) key[i % strlen(key)]) % 26 + 65);
        } else {
            encrypted[j++] = message[i];
        }
    }
    encrypted[j] = '\0';
    strcpy(message, encrypted);
    return 0;
}

int decrypt(char* message, char* key) {
    int i, j, k;
    char decrypted[MAX_ENCRYPTED_LENGTH];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            decrypted[j++] = (char) (((int) message[i] - 65 - (int) key[i % strlen(key)]) % 26 + 65);
        } else {
            decrypted[j++] = message[i];
        }
    }
    decrypted[j] = '\0';
    strcpy(message, decrypted);
    return 0;
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int length;
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the length of the key: ");
    scanf("%d", &length);
    generate_key(key, length);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}