//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
#include <stdio.h>

#define KEY "secret_key"
#define ENCRYPT 1
#define DECRYPT 0

// Function to encrypt the message using Caesar cipher
void caesar_encrypt(char message[], int key, int mode) {
    int i, j;
    char encrypted_message[100];

    for (i = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            j = (int)message[i] + key - 97;
            if (j > 122)
                j = j - 26;
            else if (j < 97)
                j = j + 26;
            encrypted_message[i] = j;
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            j = (int)message[i] + key - 65;
            if (j > 122)
                j = j - 26;
            else if (j < 97)
                j = j + 26;
            encrypted_message[i] = j;
        }
        else
            encrypted_message[i] = message[i];
    }

    if (mode == ENCRYPT)
        printf("Encrypted message: %s\n", encrypted_message);
    else
        printf("Decrypted message: %s\n", encrypted_message);
}

int main() {
    char message[100];
    int choice, key;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the key (0-25): ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt and 0 to decrypt: ");
    scanf("%d", &choice);

    if (choice == ENCRYPT)
        caesar_encrypt(message, key, ENCRYPT);
    else
        caesar_encrypt(message, key, DECRYPT);

    return 0;
}