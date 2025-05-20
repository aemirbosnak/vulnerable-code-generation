//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_IV_SIZE 16

typedef struct {
    char key[MAX_KEY_SIZE];
    char iv[MAX_IV_SIZE];
} encryption_params;

void generate_key(char* key) {
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 256;
    }
}

void generate_iv(char* iv) {
    for (int i = 0; i < strlen(iv); i++) {
        iv[i] = rand() % 256;
    }
}

int main() {
    srand(time(NULL));
    encryption_params params;
    char message[256];
    int message_length;

    // Generate encryption parameters
    generate_key(params.key);
    generate_iv(params.iv);

    // Prompt user to enter message
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    message_length = strlen(message);

    // Encrypt message
    char encrypted_message[message_length + 1];
    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ params.key[i % strlen(params.key)];
    }
    encrypted_message[message_length] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}