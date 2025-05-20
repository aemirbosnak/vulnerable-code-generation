//Falcon-180B DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

char *key = "secret";
char *cipher = "cipher";

void generate_matrix(char matrix[SIZE][SIZE]) {
    int j, k;
    for (j = 0; j < SIZE; j++) {
        matrix[j][j] = j;
    }

    for (j = 0; j < SIZE - 1; j++) {
        for (k = j + 1; k < SIZE; k++) {
            matrix[j][k] = (int) (26 * (matrix[j][k - 1] % 26 + 1));
        }
    }
}

void encrypt(char *message, char *encrypted_message, char matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = 'A';
            j = (int) message[i] - 97;
            if (isupper(message[i])) {
                j += 13;
            }
            encrypted_message[i] = (char) (((j + matrix[i % SIZE][j % SIZE]) % 26) + 97);
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

void decrypt(char *encrypted_message, char *message, char matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            j = (int) encrypted_message[i] - 97;
            if (isupper(encrypted_message[i])) {
                j -= 13;
            }
            message[i] = (char) (((j - matrix[i % SIZE][j % SIZE]) % 26) + 97);
        } else {
            message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_matrix(key);
    encrypt(message, encrypted_message, key);

    printf("Encrypted message: %s\n", encrypted_message);

    generate_matrix(cipher);
    decrypt(encrypted_message, decrypted_message, cipher);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}