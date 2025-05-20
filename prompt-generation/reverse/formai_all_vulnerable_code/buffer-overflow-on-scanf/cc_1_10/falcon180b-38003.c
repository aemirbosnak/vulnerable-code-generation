//Falcon-180B DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 9

// Function to encrypt the given string using Caesar Cipher
void encrypt(char* str) {
    int i, j;
    for(i=0; str[i]!='\0'; i++) {
        if(isalpha(str[i])) {
            // Encrypt only alphabets
            str[i] = tolower(str[i]);
            j = str[i] - 'a' + 65; // Convert to uppercase and add 65 (ASCII value of A)
            j = (j + (int)KEY[i%KEY_LENGTH]) % 26; // Encrypt using the key
            str[i] = j + 'A'; // Convert back to uppercase
        }
    }
}

// Function to decrypt the given string using Caesar Cipher
void decrypt(char* str) {
    int i, j;
    for(i=0; str[i]!='\0'; i++) {
        if(isalpha(str[i])) {
            // Decrypt only alphabets
            str[i] = tolower(str[i]);
            j = str[i] - 'a' + 65; // Convert to uppercase and add 65 (ASCII value of A)
            j = (j - (int)KEY[i%KEY_LENGTH] + 26) % 26; // Decrypt using the key
            str[i] = j + 'a'; // Convert back to lowercase
        }
    }
}

int main() {
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Encrypt the message using Caesar Cipher
    encrypt(message);
    printf("\nEncrypted message: %s\n", message);

    // Decrypt the encrypted message back to the original message
    decrypt(message);
    printf("\nDecrypted message: %s\n", message);

    return 0;
}