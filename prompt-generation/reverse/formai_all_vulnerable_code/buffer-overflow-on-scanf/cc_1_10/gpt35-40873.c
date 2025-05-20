//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Encryption Function
char* encrypt(char *inputString, int key) {
    int len = strlen(inputString);
    char* encryptedStr = (char*)malloc(sizeof(char) * (len+1));
    
    // srand seed
    srand(key);
    
    for(int i=0; i<len; i++) {
        // generate random number
        int randNum = rand() % 26;
        // add random number to character ascii value
        encryptedStr[i] = (char)(inputString[i] + randNum);
    }
    encryptedStr[len] = '\0';
    return encryptedStr;
}

// Decryption Function
char* decrypt(char *encryptedStr, int key) {
    int len = strlen(encryptedStr);
    char* decryptedStr = (char*)malloc(sizeof(char) * (len+1));
    
    // srand seed
    srand(key);
    
    for(int i=0; i<len; i++) {
        // generate random number
        int randNum = rand() % 26;
        // subtract random number from encrypted character ascii value
        decryptedStr[i] = (char)(encryptedStr[i] - randNum);
    }
    decryptedStr[len] = '\0';
    return decryptedStr;
}

int main() {
    int key;
    char inputString[100];
    
    printf("Enter a string to encrypt: ");
    scanf("%s", inputString);
    
    // Generate key using time
    key = time(NULL);
    
    // Encrypt input string
    char* encryptedStr = encrypt(inputString, key);
    printf("Encrypted String: %s\n", encryptedStr);
    
    // Decrypt encrypted string
    char* decryptedStr = decrypt(encryptedStr, key);
    printf("Decrypted String: %s\n", decryptedStr);
    
    free(encryptedStr);
    free(decryptedStr);
    return 0;
}