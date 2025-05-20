//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];
} CipherContext;

int generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = (char) rand() % 26 + 'A';
    }
    key[MAX_KEY_SIZE - 1] = '\0';
    return 0;
}

int encrypt_message(CipherContext* context) {
    int i, j;
    char* message = context->message;
    char* key = context->key;
    char* encrypted_message = context->encrypted_message;

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = (char) ((message[i] + (int) key[j % strlen(key)]) % 26 + 'A');
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';

    return 0;
}

int decrypt_message(CipherContext* context) {
    int i, j;
    char* encrypted_message = context->encrypted_message;
    char* key = context->key;
    char* decrypted_message = context->decrypted_message;

    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[j] = (char) ((encrypted_message[i] - (int) key[j % strlen(key)]) % 26 + 'A');
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';

    return 0;
}

int main() {
    CipherContext context;
    srand(time(NULL));
    generate_key(context.key);
    printf("Enter your message: ");
    scanf("%s", context.message);
    printf("Your key is: %s\n", context.key);
    printf("Encrypted message: %s\n", context.encrypted_message);
    printf("Decrypted message: %s\n", context.decrypted_message);

    return 0;
}