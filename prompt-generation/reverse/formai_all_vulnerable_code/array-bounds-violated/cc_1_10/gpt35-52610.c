//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<math.h>

#define MAX 1000

// Encryption function
char *encrypt(char *message, int key) {
    char ch;
    int i;
    
    // Allocate dynamic memory for the encrypted message
    char *encrypted = (char*)malloc(MAX*sizeof(char));
    
    for(i=0; message[i] != '\0'; i++) {
        ch = message[i];
        if(isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch-65) + key) % 26; // Apply Caesar cipher
            ch += 65; // Convert back to ASCII
        }
        encrypted[i] = ch;
    }
    encrypted[i] = '\0'; // Add null terminator
    return encrypted;
}

// Decryption function
char *decrypt(char *message, int key) {
    char ch;
    int i;
    
    // Allocate dynamic memory for the decrypted message
    char *decrypted = (char*)malloc(MAX*sizeof(char));
    
    for(i=0; message[i] != '\0'; i++) {
        ch = message[i];
        if(isalpha(ch)) {
            ch = toupper(ch);
            ch = ((ch-65) - key + 26) % 26; // Apply reverse Caesar cipher
            ch += 65; // Convert back to ASCII
        }
        decrypted[i] = ch;
    }
    decrypted[i] = '\0'; // Add null terminator
    return decrypted;
}

// Key generation function
int generate_key() {
    srand(time(NULL)); // Seed the random number generator with current time
    return rand() % 26; // Generate a random number between 0 and 25
}

int main() {
    char message[MAX], choice;
    int key;
    
    printf("Enter message to encrypt: ");
    fgets(message, MAX, stdin);
    
    // Remove newline character from message
    message[strlen(message)-1] = '\0';
    
    printf("Do you want to enter key? (Y/N): ");
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y') {
        printf("Enter key (0-25): ");
        scanf("%d", &key);
    }
    else {
        key = generate_key();
        printf("Generated key = %d\n", key);
    }
    
    // Perform encryption and decryption
    char *encrypted = encrypt(message, key);
    char *decrypted = decrypt(encrypted, key);
    
    // Print original, encrypted and decrypted messages
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
    
    // Free dynamically allocated memory
    free(encrypted);
    free(decrypted);
    
    return 0;
}