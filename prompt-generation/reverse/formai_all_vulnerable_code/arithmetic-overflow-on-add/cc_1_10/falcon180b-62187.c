//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int key = 0;
    char message[1000];
    char encrypted_message[1000];
    char decrypted_message[1000];
    int i, j;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Get encryption key
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Encrypt message
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (islower(message[i])) {
                encrypted_message[j] = message[i] + key;
            } else {
                encrypted_message[j] = message[i] - key;
            }
            j++;
        } else {
            encrypted_message[j] = message[i];
            j++;
        }
    }
    encrypted_message[j] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            if (islower(encrypted_message[i])) {
                decrypted_message[j] = encrypted_message[i] - key;
            } else {
                decrypted_message[j] = encrypted_message[i] + key;
            }
            j++;
        } else {
            decrypted_message[j] = encrypted_message[i];
            j++;
        }
    }
    decrypted_message[j] = '\0';

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}