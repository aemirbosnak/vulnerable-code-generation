//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encrypt(char *str, int shift) {
    int n = strlen(str);
    for(int i=0; i<n; i++) {
        if(isalpha(str[i])) {
            if(isupper(str[i]))
                str[i] = ((str[i] - 'A' + shift) % 26) + 'A';
            else
                str[i] = ((str[i] - 'a' + shift) % 26) + 'a';
        }
    }
}

// Function to perform decryption
void decrypt(char *str, int shift) {
    int n = strlen(str);
    for(int i=0; i<n; i++) {
        if(isalpha(str[i])) {
            if(isupper(str[i]))
                str[i] = ((str[i] - 'A' - shift + 26) % 26) + 'A';
            else
                str[i] = ((str[i] - 'a' - shift + 26) % 26) + 'a';
        }
    }
}

int main() {
    char str[100]; 
    int shift;
        
    printf("Enter a string to encrypt: ");
    fgets(str, 100, stdin);
    printf("Enter shift amount: ");
    scanf("%d", &shift);
    
    // Remove '\n' from fgets input
    str[strcspn(str, "\n")] = 0;
    
    printf("Original string: %s\n", str);
    encrypt(str, shift);
    printf("Encrypted string: %s\n", str);
    
    decrypt(str, shift);
    printf("Decrypted string: %s\n", str);
    
    return 0;
}