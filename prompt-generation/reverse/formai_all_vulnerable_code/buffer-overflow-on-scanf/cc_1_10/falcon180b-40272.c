//Falcon-180B DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int key1;
    int key2;
    int key3;
} encryption_t;

void generate_keys(encryption_t* enc) {
    srand(time(NULL));
    enc->key1 = rand() % 10000;
    enc->key2 = rand() % 10000;
    enc->key3 = rand() % 10000;
}

void encrypt(char* message, encryption_t enc) {
    int length = strlen(message);
    char encrypted_message[length + 1];
    char* encrypted_ptr = encrypted_message;
    for (char* message_ptr = message; *message_ptr; message_ptr++) {
        int key1 = enc.key1;
        int key2 = enc.key2;
        int key3 = enc.key3;
        int ascii_value = *message_ptr;
        int encrypted_ascii_value = (ascii_value + key1 + key2 + key3) % 256;
        *encrypted_ptr++ = encrypted_ascii_value;
    }
    *encrypted_ptr = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, encryption_t enc) {
    int length = strlen(encrypted_message);
    char decrypted_message[length + 1];
    char* decrypted_ptr = decrypted_message;
    for (char* encrypted_ptr = encrypted_message; *encrypted_ptr; encrypted_ptr++) {
        int key1 = enc.key1;
        int key2 = enc.key2;
        int key3 = enc.key3;
        int encrypted_ascii_value = *encrypted_ptr;
        int decrypted_ascii_value = (encrypted_ascii_value - key1 - key2 - key3 + 256) % 256;
        *decrypted_ptr++ = decrypted_ascii_value;
    }
    *decrypted_ptr = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    encryption_t enc;
    generate_keys(&enc);
    char message[1000];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, enc);
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    decrypt(message, enc);
    return 0;
}