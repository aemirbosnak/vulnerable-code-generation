//Falcon-180B DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 256

int main(void) {
    char message[LEN];
    char key[LEN];
    char encrypted[LEN];
    char decrypted[LEN];
    int i, j, k;
    int len;

    // Get message from user
    printf("Enter message: ");
    fgets(message, LEN, stdin);

    // Remove newline character from message
    len = strlen(message) - 1;
    message[len] = '\0';

    // Get key from user
    printf("Enter key: ");
    fgets(key, LEN, stdin);

    // Remove newline character from key
    len = strlen(key) - 1;
    key[len] = '\0';

    // Encrypt message
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted[i] = key[(int)message[i] - 65] + 65;
            } else {
                encrypted[i] = key[(int)message[i] - 97] + 97;
            }
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt message
    for (i = 0; encrypted[i]!= '\0'; i++) {
        if (isalpha(encrypted[i])) {
            if (isupper(encrypted[i])) {
                decrypted[i] = (char)((int)encrypted[i] - (int)key[i % strlen(key)] + 65);
            } else {
                decrypted[i] = (char)((int)encrypted[i] - (int)key[i % strlen(key)] + 97);
            }
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}