//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length + 1];
    int i, j;

    for (i = 0, j = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int k = tolower(key[j % key_length]) - 'a';
            c = (c - 'a' + k) % 26 + 'a';
            encrypted_message[i] = c;
            j++;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[message_length + 1];
    int i, j;

    for (i = 0, j = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            int k = tolower(key[j % key_length]) - 'a';
            c = (c - 'a' - k + 26) % 26 + 'a';
            decrypted_message[i] = c;
            j++;
        } else {
            decrypted_message[i] = c;
        }
    }
    decrypted_message[message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100], key[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    printf("Enter a key to encrypt the message: ");
    scanf("%s", key);

    encrypt(message, key);

    return 0;
}