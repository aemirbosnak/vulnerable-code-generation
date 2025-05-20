//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} encryption_t;

void generate_key(encryption_t *encryption) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        encryption->key[i] = rand() % 26 + 'a';
    }
    encryption->key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt_message(encryption_t *encryption) {
    for (int i = 0; i < strlen(encryption->message); i++) {
        if (isalpha(encryption->message[i])) {
            encryption->message[i] = (encryption->message[i] - 'a' + encryption->key[i % MAX_KEY_LENGTH] - 'a') % 26 + 'a';
        }
    }
}

void decrypt_message(encryption_t *encryption) {
    for (int i = 0; i < strlen(encryption->message); i++) {
        if (isalpha(encryption->message[i])) {
            encryption->message[i] = (encryption->message[i] - 'a' - encryption->key[i % MAX_KEY_LENGTH] + 26) % 26 + 'a';
        }
    }
}

void usage() {
    printf("Usage:./encryption [key] [message]\n");
    printf("Options:\n");
    printf("-e, --encrypt: Encrypt message using key\n");
    printf("-d, --decrypt: Decrypt message using key\n");
}

int main(int argc, char **argv) {
    if (argc < 3) {
        usage();
        return 1;
    }

    encryption_t encryption;
    strcpy(encryption.key, argv[1]);
    strcpy(encryption.message, argv[2]);

    if (strcmp(argv[3], "-e") == 0 || strcmp(argv[3], "--encrypt") == 0) {
        generate_key(&encryption);
        encrypt_message(&encryption);
        printf("Encrypted message: %s\n", encryption.message);
    } else if (strcmp(argv[3], "-d") == 0 || strcmp(argv[3], "--decrypt") == 0) {
        decrypt_message(&encryption);
        printf("Decrypted message: %s\n", encryption.message);
    } else {
        usage();
        return 1;
    }

    return 0;
}