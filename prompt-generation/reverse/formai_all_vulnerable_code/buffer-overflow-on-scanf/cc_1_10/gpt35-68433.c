//FormAI DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include<stdio.h>
#include<string.h>

// Function to check if the character is alphanumeric
int isAlphaNumeric(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

// Function to perform the Modern Encryption
void modernEncryption(char input[], int key) {
    
    int i, j=0, len = strlen(input);
    char output[len];
    
    // Loop through each character in the input
    for(i=0; i<len; i++) {
        
        // Shift the character by the key amount
        output[i] = input[i] + key;
        
        // If character is alphanumeric, double shift it
        if(isAlphaNumeric(input[i])) {
            output[i] += key;
        }
        
        // Add a space after every 5th character
        if((i+1)%5 == 0) {
            output[i+1] = ' ';
            i++;
        }
    }
    
    // Print the encrypted message
    printf("Encrypted Message: %s\n", output);
}

int main() {
    
    char input[100];
    int key;
    
    // Get message and key from user
    printf("Enter message to encrypt: ");
    fgets(input, 100, stdin);
    printf("Enter encryption key: ");
    scanf("%d", &key);
    
    // Call Modern Encryption function
    modernEncryption(input, key);
    
    return 0;
}