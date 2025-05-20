//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

//Encrypt function
void encrypt(char *password, char *key) {
    int password_len = strlen(password), key_len = strlen(key);
    char encrypted[MAX_SIZE];
    int i, j;
    for(i = 0, j = 0; i < password_len; i++, j++) {
        if(j == key_len) j = 0;
        encrypted[i] = ((password[i] + key[j]) % 26) + 'A';
    }
    encrypted[i] = '\0';
    printf("Encrypted text: %s\n", encrypted);
}

//Decrypt function
void decrypt(char *encrypted_password, char *key) {
    int encrypted_len = strlen(encrypted_password), key_len = strlen(key);
    char decrypted[MAX_SIZE];
    int i, j;
    for(i = 0, j = 0; i < encrypted_len; i++, j++) {
        if(j == key_len) j = 0;
        decrypted[i] = (((encrypted_password[i] - key[j]) + 26) % 26) + 'A';
    }
    decrypted[i] = '\0';
    printf("Decrypted password: %s\n", decrypted);
}

int main() {
    char password[MAX_SIZE], key[MAX_SIZE], encrypted_password[MAX_SIZE];
    int choice;

    //Get password and key from user
    printf("Enter the password: ");
    scanf("%s", password);
    printf("Enter the key: ");
    scanf("%s", key);

    //Menu for user
    printf("Enter your choice -\n");
    printf("1. Encrypt password\n");
    printf("2. Decrypt password\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: 
            encrypt(password, key);
            break;
        case 2:
            printf("Enter the encrypted password: ");
            scanf("%s", encrypted_password);
            decrypt(encrypted_password, key);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}