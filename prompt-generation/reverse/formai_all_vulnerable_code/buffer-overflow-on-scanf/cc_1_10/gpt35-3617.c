//FormAI DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>

void encrypt(char message[], int key) {
    int i;
    char ch;

    for(i = 0; i < strlen(message); ++i) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }

        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char message[], int key) {
    int i;
    char ch;

    for(i = 0; i < strlen(message); ++i) {
        ch = message[i];

        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }

        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }
}

int main() {
    char message[100];
    int key, choice;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    switch(choice) {
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
    }

    return 0;
}