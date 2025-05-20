//Falcon-180B DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 1024

void generate_key(char *key) {
    time_t t;
    time(&t);
    srand(t);

    for (int i = 0; i < MAX_KEY_LEN; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *key, char *msg) {
    int len = strlen(msg);
    char *encrypted = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isalpha(msg[i])) {
            encrypted[i] = ((msg[i] - 'a' + ((key[i % MAX_KEY_LEN] - 'a') % 26)) % 26) + 'a';
        } else {
            encrypted[i] = msg[i];
        }
    }

    encrypted[len] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *key, char *msg) {
    int len = strlen(msg);
    char *decrypted = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (isalpha(msg[i])) {
            decrypted[i] = ((msg[i] - 'a' - ((key[i % MAX_KEY_LEN] - 'a') % 26)) % 26) + 'a';
        } else {
            decrypted[i] = msg[i];
        }
    }

    decrypted[len] = '\0';

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];

    printf("Enter message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(key, msg);

    char choice;
    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        decrypt(key, msg);
    }

    return 0;
}