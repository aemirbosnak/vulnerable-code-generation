//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <string.h>

void encrypt(char* str, int shift);
void decrypt(char* str, int shift);

int main() {
    char original[100], encrypted[100], decrypted[100];
    int shift;
    
    // Get user input
    printf("Enter a string to encrypt: ");
    fgets(original, 100, stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Encrypt user input and print encrypted string
    strcpy(encrypted, original);
    encrypt(encrypted, shift);
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt encrypted string and print decrypted string
    strcpy(decrypted, encrypted);
    decrypt(decrypted, shift);
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}

// Encrypt function
void encrypt(char* str, int shift) {
    int i = 0;
    char ch;

    while (str[i] != '\0') {
        ch = str[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + shift;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            str[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + shift;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            str[i] = ch;
        }
        i++;
    }
}

// Decrypt function
void decrypt(char* str, int shift) {
    int i = 0;
    char ch;

    while (str[i] != '\0') {
        ch = str[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - shift;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            str[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - shift;
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            str[i] = ch;
        }
        i++;
    }
}