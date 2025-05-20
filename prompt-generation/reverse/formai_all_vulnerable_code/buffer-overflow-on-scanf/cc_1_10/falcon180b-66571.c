//Falcon-180B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the given string
void encrypt(char* str) {
    int i, j, k;
    char key[100];

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Shift the key to get the decryption key
    for(i = 0; i < strlen(key); i++) {
        if(isalpha(key[i])) {
            key[i] = tolower(key[i]);
            if(key[i] >= 'a' && key[i] <='m') {
                key[i] += 13;
            }
            else if(key[i] >= 'n' && key[i] <= 'z') {
                key[i] -= 13;
            }
        }
    }

    // Encrypt the given string
    for(i = 0, j = 0; str[i]; i++) {
        if(isalpha(str[i])) {
            str[i] = tolower(str[i]);
            if(str[i] >= 'a' && str[i] <='m') {
                str[i] += 13;
            }
            else if(str[i] >= 'n' && str[i] <= 'z') {
                str[i] -= 13;
            }
        }
    }

    // XOR the encrypted string with the decryption key
    for(i = 0; str[i]; i++) {
        str[i] ^= key[j++ % strlen(key)];
    }
}

int main() {
    char str[1000];

    // Get the string to be encrypted from the user
    printf("Enter the string to be encrypted: ");
    scanf("%s", str);

    // Encrypt the string
    encrypt(str);

    // Print the encrypted string
    printf("Encrypted string: %s\n", str);

    return 0;
}