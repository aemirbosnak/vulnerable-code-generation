//Falcon-180B DATASET v1.0 Category: Encryption ; Style: random
/* C Encryption Example Program */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY "secretkey"
#define FLAG "encrypted"

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[strlen(message)];

    for (i = 0, j = 0; message[i]; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = ((c - 'a' + 13) % 26) + 'a';
        }
        encrypted_message[j++] = c;
    }

    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int i, j;
    char decrypted_message[strlen(message)];

    for (i = 0, j = 0; message[i]; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = ((c - 'a' + 13 - (KEY[j % strlen(KEY)] - 'a')) % 26) + 'a';
        }
        decrypted_message[j++] = c;
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    encrypt(message, KEY);

    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == FLAG[i]) {
            printf("%c", message[i]);
        } else {
            printf("*");
        }
    }

    return 0;
}