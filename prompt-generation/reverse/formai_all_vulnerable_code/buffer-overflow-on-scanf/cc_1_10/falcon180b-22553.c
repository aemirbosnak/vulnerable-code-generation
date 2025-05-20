//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void encrypt(char* message, char* key, char* encrypted_message) {
    int i, j, k = 0;
    char temp;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = tolower(message[i]);
            }

            j = tolower(message[i]) - 'a';
            temp = key[k];
            k = (k + j) % SIZE;

            if (isupper(message[i])) {
                message[i] = toupper(temp);
            } else {
                message[i] = tolower(temp);
            }
        }
    }

    strcpy(encrypted_message, message);
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int i, j, k = 0;
    char temp;

    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                encrypted_message[i] = tolower(encrypted_message[i]);
            }

            j = tolower(encrypted_message[i]) - 'a';
            temp = key[k];
            k = (k - j + SIZE) % SIZE;

            if (isupper(encrypted_message[i])) {
                encrypted_message[i] = toupper(temp);
            } else {
                encrypted_message[i] = tolower(temp);
            }
        }
    }

    strcpy(decrypted_message, encrypted_message);
}

int main() {
    char message[100], key[100], encrypted_message[100], decrypted_message[100];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}