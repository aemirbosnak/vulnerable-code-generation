//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MSG_LENGTH 1000

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char* msg, char* key, char* encrypted_msg) {
    int i, j;
    for (i = 0, j = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            encrypted_msg[j++] = (msg[i] - 'a' + key[i % strlen(key)] - 'a') % 26 + 'a';
        } else {
            encrypted_msg[j++] = msg[i];
        }
    }
    encrypted_msg[j] = '\0';
}

void decrypt(char* encrypted_msg, char* key, char* decrypted_msg) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_msg); i++) {
        if (isalpha(encrypted_msg[i])) {
            decrypted_msg[j++] = (encrypted_msg[i] - key[i % strlen(key)] - 'a' + 26) % 26 + 'a';
        } else {
            decrypted_msg[j++] = encrypted_msg[i];
        }
    }
    decrypted_msg[j] = '\0';
}

int main() {
    char* key;
    char* msg;
    char* encrypted_msg;
    char* decrypted_msg;
    int key_length;
    int msg_length;

    printf("Enter the message to be encrypted: ");
    scanf("%s", msg);
    msg_length = strlen(msg);

    printf("Enter the key to be used for encryption: ");
    scanf("%s", key);
    key_length = strlen(key);

    if (key_length > MAX_KEY_LENGTH || msg_length > MAX_MSG_LENGTH) {
        printf("Invalid key or message length.\n");
        return 1;
    }

    generate_key(key, key_length);
    encrypt(msg, key, encrypted_msg);
    decrypt(encrypted_msg, key, decrypted_msg);

    printf("Encrypted message: %s\n", encrypted_msg);
    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}