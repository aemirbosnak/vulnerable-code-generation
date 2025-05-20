//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>

// Function to encrypt message
void encrypt(char message[], char key[]) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (((message[i] - 65) + key[j]) % 26) + 65;
            } else {
                message[i] = (((message[i] - 97) + key[j]) % 26) + 97;
            }
        }
    }
}

// Function to decrypt message
void decrypt(char message[], char key[]) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (((message[i] - 65) - key[j]) % 26) + 65;
            } else {
                message[i] = (((message[i] - 97) - key[j]) % 26) + 97;
            }
        }
    }
}

int main() {
    char message[100], key[100], choice;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter 1 to encrypt, 2 to decrypt: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}