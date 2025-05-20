//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int i, j, key;
    char message[SIZE];
    char encrypted[SIZE];
    char decrypted[SIZE];
    char choice;

    // Get message from user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Get key from user
    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    // Encrypt message
    for(i = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                encrypted[i] = (((int)message[i] - 65 + key) % 26) + 65;
            } else {
                encrypted[i] = (((int)message[i] - 97 + key) % 26) + 97;
            }
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';

    // Ask user if they want to decrypt
    printf("Do you want to decrypt the message? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        // Decrypt message
        for(i = 0; encrypted[i]!= '\0'; i++) {
            if(isalpha(encrypted[i])) {
                if(isupper(encrypted[i])) {
                    decrypted[i] = (((int)encrypted[i] - 65 - key + 26) % 26) + 65;
                } else {
                    decrypted[i] = (((int)encrypted[i] - 97 - key + 26) % 26) + 97;
                }
            } else {
                decrypted[i] = encrypted[i];
            }
        }
        decrypted[i] = '\0';

        // Print decrypted message
        printf("Decrypted message: %s\n", decrypted);
    }

    return 0;
}