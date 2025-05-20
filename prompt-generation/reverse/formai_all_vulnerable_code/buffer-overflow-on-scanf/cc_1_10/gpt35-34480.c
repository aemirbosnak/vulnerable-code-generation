//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char*, int);
char* decrypt(char*, int);

int main() {
    int key;
    char message[100];
    char* encrypted_message;
    char* decrypted_message;

    printf("Enter the message to encrypt: ");
    gets(message);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypted_message = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

char* encrypt(char* message, int key) {
    int i;
    char* encrypted_message = (char*) malloc(strlen(message) * sizeof(char));

    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = (message[i] + key - 'a') % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = (message[i] + key - 'A') % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[i] = '\0';

    return encrypted_message;
}

char* decrypt(char* message, int key) {
    int i;
    char* decrypted_message = (char*) malloc(strlen(message) * sizeof(char));

    for(i = 0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted_message[i] = (message[i] - key - 'a' + 26) % 26 + 'a';
        } else if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted_message[i] = (message[i] - key - 'A' + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = message[i];
        }
    }

    decrypted_message[i] = '\0';

    return decrypted_message;
}