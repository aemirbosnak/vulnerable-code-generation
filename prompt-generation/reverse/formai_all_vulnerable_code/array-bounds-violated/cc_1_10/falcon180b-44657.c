//Falcon-180B DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LEN (strlen(KEY))

void encrypt(char *message) {
    int i, j, k;
    char encrypted_message[strlen(message)];
    char key[KEY_LEN];

    strcpy(key, KEY);

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        encrypted_message[j] = (char) (message[i] + key[i % KEY_LEN]);
        j++;
    }

    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message) {
    int i, j, k;
    char decrypted_message[strlen(encrypted_message)];
    char key[KEY_LEN];

    strcpy(key, KEY);

    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        decrypted_message[j] = (char) (encrypted_message[i] - key[i % KEY_LEN]);
        j++;
    }

    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100] = "Hello, world!";

    printf("Original message: %s\n", message);
    encrypt(message);
    decrypt(message);

    return 0;
}