//Falcon-180B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 100

void generate_key(char key[LENGTH]) {
    srand(time(NULL));
    for (int i = 0; i < LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

char encrypt(char message[LENGTH], char key[LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        message[i] = message[i] + key[i];
    }
    return message[0];
}

char decrypt(char encrypted_message[LENGTH], char key[LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        encrypted_message[i] = encrypted_message[i] - key[i];
    }
    return encrypted_message[0];
}

int main() {
    char message[LENGTH];
    char key[LENGTH];

    printf("Enter message: ");
    scanf("%s", message);

    generate_key(key);

    char encrypted_message[LENGTH];
    encrypted_message[0] = encrypt(message, key);

    for (int i = 1; i < LENGTH; i++) {
        encrypted_message[i] = encrypt(encrypted_message, key);
    }

    char decrypted_message[LENGTH];
    decrypted_message[0] = decrypt(encrypted_message, key);

    for (int i = 1; i < LENGTH; i++) {
        decrypted_message[i] = decrypt(decrypted_message, key);
    }

    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}