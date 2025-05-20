//Falcon-180B DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 26
#define KEY "abcdefghijklmnopqrstuvwxyz"

void encrypt(char* message, char* key) {
    int i, j, k = 0;
    char encrypted_message[LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }
            for (j = 0; key[j]!= '\0'; j++) {
                if (key[j] == message[i]) {
                    encrypted_message[k] = message[i];
                    k++;
                    break;
                }
            }
        }
    }
    encrypted_message[k] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int i, j, k = 0;
    char decrypted_message[LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        for (j = 0; key[j]!= '\0'; j++) {
            if (key[j] == message[i]) {
                decrypted_message[k] = message[i];
                k++;
                break;
            }
        }
    }
    decrypted_message[k] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[LENGTH], key[LENGTH];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}