//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000000

char *encrypt(char *message, int key) {
    int i, j, len = strlen(message);
    char *result = malloc(len + 1);

    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            result[j++] = (tolower(message[i]) + key - 97) % 26 + 97;
        } else {
            result[j++] = message[i];
        }
    }

    result[j] = '\0';

    return result;
}

int decrypt(char *message, int key) {
    int i, j, len = strlen(message);
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (tolower(message[i]) - key + 97 % 26 == 97) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int key = rand() % 26;

    char message[MAX_SIZE];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    char *encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    int decrypted = decrypt(encrypted, key);
    if (decrypted) {
        printf("Decrypted message: %s\n", encrypted);
    } else {
        printf("Invalid key\n");
    }

    free(encrypted);
    return 0;
}