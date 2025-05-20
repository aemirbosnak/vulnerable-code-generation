//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to shift the given character by the given number of positions
char shift(char c, int n) {
    if (isupper(c))
        return (c + n - 65) % 26 + 65;
    else
        return (c + n - 97) % 26 + 97;
}

// Function to encrypt the given string using Caesar cipher
void encrypt(char str[], int key) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = shift(str[i], key);
        }
    }
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char str[], int key) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            str[i] = shift(str[i], 26 - key);
        }
    }
}

int main() {
    char str[100], choice;
    int key, i;

    // Get the string to be encrypted/decrypted
    printf("Enter the string to be encrypted/decrypted: ");
    scanf("%[^\n]", str);

    // Get the key value
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    // Get the choice of encryption/decryption
    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf(" %c", &choice);

    // Perform encryption/decryption based on the choice
    if (choice == 'e' || choice == 'E') {
        encrypt(str, key);
        printf("Encrypted string: %s\n", str);
    } else if (choice == 'd' || choice == 'D') {
        decrypt(str, key);
        printf("Decrypted string: %s\n", str);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}