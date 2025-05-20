//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

//Recursive function to encrypt the message using Caesar cipher
void encrypt(char *message, int key, int length) {
    if (length == 0) {
        return;
    }
    if (isalpha(message[0])) {
        if (isupper(message[0])) {
            printf("%c", ((int)message[0] + key - 65) % 26 + 65);
        } else {
            printf("%c", ((int)message[0] + key - 97) % 26 + 97);
        }
    } else {
        printf("%c", message[0]);
    }
    encrypt(message + 1, key, length - 1);
}

//Recursive function to decrypt the message using Caesar cipher
void decrypt(char *message, int key, int length) {
    if (length == 0) {
        return;
    }
    if (isalpha(message[0])) {
        if (isupper(message[0])) {
            printf("%c", ((int)message[0] - key - 65 + 26) % 26 + 65);
        } else {
            printf("%c", ((int)message[0] - key - 97 + 26) % 26 + 97);
        }
    } else {
        printf("%c", message[0]);
    }
    decrypt(message + 1, key, length - 1);
}

int main() {
    char message[100];
    int key, length;
    printf("Enter the message: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%d", &key);
    printf("Enter the length of the message: ");
    scanf("%d", &length);
    printf("Encrypted Message: ");
    encrypt(message, key, length);
    printf("\n");
    printf("Decrypted Message: ");
    decrypt(message, key, length);
    printf("\n");
    return 0;
}