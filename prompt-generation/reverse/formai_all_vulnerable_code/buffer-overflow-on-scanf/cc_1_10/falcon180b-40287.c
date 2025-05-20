//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>

// Function to encrypt a string using a given key
void encrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] + key;
        if (str[i] > 'z') {
            str[i] = str[i] - 26;
        } else if (str[i] < 'a') {
            str[i] = str[i] + 26;
        }
    }
}

// Function to decrypt a string using a given key
void decrypt(char* str, int key) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = str[i] - key;
        if (str[i] > 'z') {
            str[i] = str[i] - 26;
        } else if (str[i] < 'a') {
            str[i] = str[i] + 26;
        }
    }
}

// Function to take input string and key from user
void get_input(char* str, int* key) {
    printf("Enter a string to encrypt: ");
    scanf("%s", str);

    printf("Enter a key (0-25): ");
    scanf("%d", key);
}

int main() {
    char str[100];
    int key;

    // Get input string and key from user
    get_input(str, &key);

    // Encrypt the string
    encrypt(str, key);
    printf("Encrypted string: %s\n", str);

    // Decrypt the string
    decrypt(str, key);
    printf("Decrypted string: %s\n", str);

    return 0;
}