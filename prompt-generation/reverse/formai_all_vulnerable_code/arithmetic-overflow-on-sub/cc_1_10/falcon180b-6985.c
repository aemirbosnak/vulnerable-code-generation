//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int key = 0;
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    int i = 0;
    int j = 0;

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Get key from user
    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[j] = message[i] + key;
            } else {
                encrypted_message[j] = message[i] + key - 32;
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';

    // Decrypt message
    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[j] = encrypted_message[i] - key;
            } else {
                decrypted_message[j] = encrypted_message[i] - key + 32;
            }
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';

    // Print encrypted and decrypted messages
    printf("\nEncrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}