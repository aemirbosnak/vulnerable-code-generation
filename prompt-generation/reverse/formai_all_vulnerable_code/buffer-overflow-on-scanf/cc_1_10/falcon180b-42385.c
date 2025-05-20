//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

void encrypt(char message[], char key[]) {
    int i, j;
    int key_index = 0;
    char new_message[100];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[i] = ((message[i] - 'A' + key_index) % SIZE + 'A');
            } else {
                new_message[i] = ((message[i] - 'a' + key_index) % SIZE + 'a');
            }
        } else {
            new_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", new_message);
}

void decrypt(char message[], char key[]) {
    int i, j;
    int key_index = 0;
    char new_message[100];

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                new_message[i] = ((message[i] - 'A' - key_index + SIZE) % SIZE + 'A');
            } else {
                new_message[i] = ((message[i] - 'a' - key_index + SIZE) % SIZE + 'a');
            }
        } else {
            new_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", new_message);
}

int main() {
    char message[100];
    char key[100];

    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}