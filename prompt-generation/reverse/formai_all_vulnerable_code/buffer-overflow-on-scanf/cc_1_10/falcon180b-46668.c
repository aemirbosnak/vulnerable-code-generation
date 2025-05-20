//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];
    int key_size;
    int i;

    // Get message from user
    printf("Enter message: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0';

    // Get key from user
    printf("Enter key: ");
    fgets(key, MAX_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';

    // Get key size from user
    printf("Enter key size: ");
    scanf("%d", &key_size);

    // Encrypt message
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int ascii_value = message[i] + key_size;
            if (isupper(message[i])) {
                ascii_value = ascii_value - 65;
            } else {
                ascii_value = ascii_value - 97;
            }
            encrypted_message[i] = ascii_value;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';

    // Decrypt message
    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            int ascii_value = encrypted_message[i] - key_size;
            if (isupper(encrypted_message[i])) {
                ascii_value = ascii_value + 65;
            } else {
                ascii_value = ascii_value + 97;
            }
            decrypted_message[i] = ascii_value;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0';

    // Print results
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}