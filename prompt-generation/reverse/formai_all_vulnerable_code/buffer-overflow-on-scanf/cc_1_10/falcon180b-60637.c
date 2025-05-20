//Falcon-180B DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10000

void encrypt(char *message, char *key) {
    int i, j, n = strlen(message);
    char encrypted[SIZE];

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(message[i])) {
            encrypted[j] = (tolower(message[i]) + tolower(key[i % strlen(key)]) - 97) % 26 + 97;
            j++;
        } else {
            encrypted[j] = message[i];
            j++;
        }
    }

    encrypted[j] = '\0';

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *encrypted, char *key) {
    int i, j, n = strlen(encrypted);
    char decrypted[SIZE];

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(encrypted[i])) {
            decrypted[j] = (tolower(encrypted[i]) - tolower(key[i % strlen(key)]) + 26) % 26 + 97;
            j++;
        } else {
            decrypted[j] = encrypted[i];
            j++;
        }
    }

    decrypted[j] = '\0';

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[SIZE], key[SIZE];
    printf("Enter message to be encrypted: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}