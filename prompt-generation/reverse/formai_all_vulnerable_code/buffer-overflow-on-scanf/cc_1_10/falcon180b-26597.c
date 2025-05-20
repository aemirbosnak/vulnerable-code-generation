//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to encrypt a string
void encrypt(char* str, int key) {
    int len = strlen(str);
    if (len > MAX_LENGTH) {
        printf("String too long!\n");
        exit(1);
    }
    char new_str[MAX_LENGTH];
    int i = 0;
    int j = 0;
    int k = 0;
    while (str[i]!= '\0') {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                new_str[j] = ((int)str[i] + key - 65) % 26 + 65;
            } else {
                new_str[j] = ((int)str[i] + key - 97) % 26 + 97;
            }
            i++;
            j++;
        } else {
            new_str[j] = str[i];
            i++;
            j++;
        }
    }
    new_str[j] = '\0';
    printf("Encrypted string: %s\n", new_str);
}

// Function to decrypt a string
void decrypt(char* str, int key) {
    int len = strlen(str);
    if (len > MAX_LENGTH) {
        printf("String too long!\n");
        exit(1);
    }
    char new_str[MAX_LENGTH];
    int i = 0;
    int j = 0;
    int k = 0;
    while (str[i]!= '\0') {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                new_str[j] = ((int)str[i] - 65 - key + 26) % 26 + 65;
            } else {
                new_str[j] = ((int)str[i] - 97 - key + 26) % 26 + 97;
            }
            i++;
            j++;
        } else {
            new_str[j] = str[i];
            i++;
            j++;
        }
    }
    new_str[j] = '\0';
    printf("Decrypted string: %s\n", new_str);
}

// Main function
int main() {
    char str[MAX_LENGTH];
    int key;
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter a key: ");
    scanf("%d", &key);
    encrypt(str, key);
    decrypt(str, key);
    return 0;
}