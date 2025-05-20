//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int i, j, k, l, n;
    int key[3][3], message[100], encrypted_message[100];
    char key_input[10], message_input[100];

    // Get key from user
    printf("Enter key (9 digits with spaces between): ");
    fgets(key_input, 10, stdin);

    // Parsing key into a 3x3 matrix
    k = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            key[i][j] = key_input[k] - '0';
            k += 2;
        }
    }

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message_input, 100, stdin);

    // Parsing message into a number array
    n = strlen(message_input);
    for (i = 0; i < n; i++) {
        message[i] = (int) message_input[i];
    }

    // Encryption algorithm
    l = 0;
    for (i = 0; i < n; i += 3) {
        for (j = 0; j < 3; j++) {
            encrypted_message[l] = (message[i]*key[0][j]) + (message[i+1]*key[1][j]) + (message[i+2]*key[2][j]);
            l++;
        }
    }

    // Printing encrypted message
    printf("Encrypted message: ");
    for (i = 0; i < l; i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

    return 0;
}