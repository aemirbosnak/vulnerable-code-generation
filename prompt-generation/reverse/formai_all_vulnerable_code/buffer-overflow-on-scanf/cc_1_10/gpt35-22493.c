//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <string.h>

#define BLOCK_SIZE 16

// Function to encrypt
void encrypt(unsigned char *encrypt_message, unsigned char *key) {
    AES_KEY aes_key;
    int num = 0;
    int length = strlen(encrypt_message);

    if (AES_set_encrypt_key(key, 128, &aes_key) < 0) {       
        fprintf(stderr, "Could not set AES encryption key.");    
        exit(1);    
    }

    unsigned char iv[BLOCK_SIZE];    
    memset(iv, 0, BLOCK_SIZE);

    if (length % BLOCK_SIZE != 0) {
        num = BLOCK_SIZE - (length % BLOCK_SIZE);
        int j;
        for (j = 0; j < num; j++) {
            encrypt_message[length + j] = num;    
        }
        length += num;
    }

    unsigned char encrypted_message[length];

    AES_cbc_encrypt(encrypt_message, encrypted_message, length, &aes_key, iv, AES_ENCRYPT);    

    printf("\n\nEncrypted Message:\n");
    for (int i=0; i<length; i++) {
        printf("%c", encrypted_message[i]);    
    } 
}

// Function to decrypt
void decrypt(unsigned char *decrypt_message, unsigned char *key) {
    AES_KEY aes_key;
    int num = 0;
    int length = strlen(decrypt_message);
    
    if (AES_set_decrypt_key(key, 128, &aes_key) < 0) {
        fprintf(stderr, "Could not set AES encryption key.");
        exit(1);    
    }

    unsigned char iv[BLOCK_SIZE];
    memset(iv, 0, BLOCK_SIZE);

    unsigned char decrypted_message[length];
    AES_cbc_encrypt(decrypt_message, decrypted_message, length, &aes_key, iv, AES_DECRYPT);

    if (decrypted_message[length-1] < 16) {
        num = decrypted_message[length-1];   
        length -= num;
    }

    printf("\n\nDecrypted Message:\n");
    for (int i=0; i<length; i++) {
        printf("%c", decrypted_message[i]);    
    }
} 

int main() {
    printf("CybeEncrypt v1.0 - Cyberpunk Cryptography\n");

    unsigned char message[1000];
    unsigned char key[17];
    int option;

    printf("\nEnter message (max 1000 characters):\n");
    fgets((char *)message, 1000, stdin);
    printf("Enter encryption key (max 16 characters):\n");
    fgets((char *)key, 16, stdin);

    printf("\nChoose an option:\n");
    printf("1. Encrypt\n2. Decrypt\n");
    scanf("%d", &option);

    if (option == 1) {
        printf("\nEncrypting message...");
        encrypt(message, key);
    }
    else if (option == 2) {
        printf("\nDecrypting message...");
        decrypt(message, key);    
    }
    else {
        printf("Invalid option.");
    }

    printf("\n");
    return 0;
}