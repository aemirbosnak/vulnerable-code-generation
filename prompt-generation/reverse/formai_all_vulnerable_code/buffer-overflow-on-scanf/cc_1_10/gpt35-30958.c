//FormAI DATASET v1.0 Category: modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext){
    int keylen = strlen(key);
    int textlen = strlen(plaintext);
    int i, j;

    for(i=0; i<textlen; i++){
        ciphertext[i] = ((plaintext[i] + key[i % keylen]) % 26) + 'A';
        // This line adds the two characters together, takes the result mod 26 (to keep it within the range of the alphabet), and then adds back the ASCII value of 'A' to convert to a letter
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext){
    int keylen = strlen(key);
    int textlen = strlen(ciphertext);
    int i, j;

    for(i=0; i<textlen; i++){
        plaintext[i] = ((ciphertext[i] - key[i % keylen] + 26) % 26) + 'A';
        // This line does the opposite of the encryption function - it subtracts the two characters and then adds back the value of 'A'
    }
    plaintext[i] = '\0';
}

int main(){
    char plaintext[100], key[100], ciphertext[100];
    int choice;

    printf("Please enter the plaintext: ");
    scanf("%[^\n]", plaintext);
    printf("Please enter the key: ");
    scanf("%s", key);

    do{
        printf("\nPlease choose an option:\n1. Encrypt\n2. Decrypt\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                encrypt(plaintext, key, ciphertext);
                printf("\nThe encrypted text is: %s\n", ciphertext);
                break;
            case 2:
                decrypt(ciphertext, key, plaintext);
                printf("\nThe decrypted text is: %s\n", plaintext);
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }while(1);

    return 0;
}