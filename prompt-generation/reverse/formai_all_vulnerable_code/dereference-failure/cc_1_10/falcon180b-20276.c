//Falcon-180B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
} Encryption;

Encryption* createEncryption(char key[], char message[]);
void encrypt(Encryption* encryption);
void decrypt(Encryption* encryption);

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];

    printf("Enter a key between 1 and %d characters: ", MAX_KEY_LENGTH - 1);
    scanf("%s", key);

    printf("Enter a message between 1 and %d characters: ", MAX_MESSAGE_LENGTH - 1);
    scanf("%s", message);

    Encryption* encryption = createEncryption(key, message);

    printf("Encrypted message: %s\n", encryption->encrypted_message);

    decrypt(encryption);

    printf("Decrypted message: %s\n", encryption->message);

    return 0;
}

Encryption* createEncryption(char key[], char message[]) {
    Encryption* encryption = (Encryption*)malloc(sizeof(Encryption));

    strcpy(encryption->key, key);
    strcpy(encryption->message, message);

    return encryption;
}

void encrypt(Encryption* encryption) {
    int key_length = strlen(encryption->key);
    int message_length = strlen(encryption->message);

    int j = 0;
    for (int i = 0; i < message_length; i++) {
        char c = toupper(encryption->message[i]);
        if (isalpha(c)) {
            int index = (c - 'A') % key_length;
            encryption->encrypted_message[i] = encryption->key[index];
        } else {
            encryption->encrypted_message[i] = encryption->message[i];
        }
    }
}

void decrypt(Encryption* encryption) {
    int key_length = strlen(encryption->key);
    int message_length = strlen(encryption->encrypted_message);

    int j = 0;
    for (int i = 0; i < message_length; i++) {
        char c = toupper(encryption->encrypted_message[i]);
        if (isalpha(c)) {
            int index = (c - 'A') % key_length;
            encryption->message[i] = 'A' + index;
        } else {
            encryption->message[i] = encryption->encrypted_message[i];
        }
    }
}