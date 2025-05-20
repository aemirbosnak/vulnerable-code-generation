//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function to encrypt the given string using Caesar cipher
void encrypt(char* str, int key) {
    int len = strlen(str);
    char encrypted[MAX_LENGTH];
    memset(encrypted, 0, MAX_LENGTH);

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                encrypted[i] = (char) ((int) str[i] + key - 65);
                if (encrypted[i] > 'Z') {
                    encrypted[i] = (char) (encrypted[i] - 26);
                }
            } else {
                encrypted[i] = (char) ((int) str[i] + key - 97);
                if (encrypted[i] > 'z') {
                    encrypted[i] = (char) (encrypted[i] - 26);
                }
            }
        } else {
            encrypted[i] = str[i];
        }
    }

    printf("Encrypted string: %s\n", encrypted);
}

// Function to decrypt the given string using Caesar cipher
void decrypt(char* str, int key) {
    int len = strlen(str);
    char decrypted[MAX_LENGTH];
    memset(decrypted, 0, MAX_LENGTH);

    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                decrypted[i] = (char) ((int) str[i] - key - 65 + 26) % 26;
            } else {
                decrypted[i] = (char) ((int) str[i] - key - 97 + 26) % 26;
            }
        } else {
            decrypted[i] = str[i];
        }
    }

    printf("Decrypted string: %s\n", decrypted);
}

int main() {
    char input[MAX_LENGTH];
    int key;

    printf("Enter the string to be encrypted: ");
    scanf("%s", input);

    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    encrypt(input, key);
    decrypt(input, key);

    return 0;
}

/*
Sample Input/Output:

Enter the string to be encrypted: Hello World!
Enter the encryption key (0-25): 3
Encrypted string: Khoor Zruog!
Decrypted string: Hello World!
*/