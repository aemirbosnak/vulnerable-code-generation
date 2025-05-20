//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int main() {
    char key[SIZE];
    char message[SIZE];
    char encrypted[SIZE];
    char decrypted[SIZE];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the message: ");
    scanf("%s", message);

    // Encryption
    int index = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted[index++] = (char) ((int) message[i] + (int) key[i % strlen(key)] - 65);
            } else {
                encrypted[index++] = (char) ((int) message[i] + (int) key[i % strlen(key)] - 97);
            }
        } else {
            encrypted[index++] = message[i];
        }
    }
    encrypted[index] = '\0';

    // Decryption
    index = 0;
    for (int i = 0; i < strlen(encrypted); i++) {
        if (isalpha(encrypted[i])) {
            if (isupper(encrypted[i])) {
                decrypted[index++] = (char) ((int) encrypted[i] - (int) key[i % strlen(key)] - 65 + 26);
            } else {
                decrypted[index++] = (char) ((int) encrypted[i] - (int) key[i % strlen(key)] - 97 + 26);
            }
        } else {
            decrypted[index++] = encrypted[i];
        }
    }
    decrypted[index] = '\0';

    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}