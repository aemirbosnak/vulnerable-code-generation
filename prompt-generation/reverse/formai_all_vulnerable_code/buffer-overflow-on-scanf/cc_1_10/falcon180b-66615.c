//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define SIZE 1000
#define ENCRYPT 0
#define DECRYPT 1

void generateKey(char key[], int keySize) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    srand(time(NULL));
    for(i=0; i<keySize; i++) {
        key[i] = charset[rand()%strlen(charset)];
    }
}

void encrypt(char plaintext[], char key[], int keySize, char ciphertext[]) {
    int i, j, k;
    for(i=0, j=0; i<strlen(plaintext); i++) {
        if(isalpha(plaintext[i])) {
            plaintext[i] = toupper(plaintext[i]);
            ciphertext[j++] = plaintext[i] ^ key[i%keySize];
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char ciphertext[], char key[], int keySize, char plaintext[]) {
    int i, j, k;
    for(i=0, j=0; i<strlen(ciphertext); i++) {
        if(isalpha(ciphertext[i])) {
            ciphertext[i] = toupper(ciphertext[i]);
            plaintext[j++] = ciphertext[i] ^ key[i%keySize];
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[SIZE], ciphertext[SIZE], key[SIZE];
    int keySize, choice, i;

    printf("Enter the size of the key (between 1 and %d): ", SIZE-1);
    scanf("%d", &keySize);

    generateKey(key, keySize);

    printf("Enter the plaintext to encrypt/decrypt:\n");
    fgets(plaintext, SIZE, stdin);

    printf("Enter 1 to encrypt and 2 to decrypt:\n");
    scanf("%d", &choice);

    switch(choice) {
        case ENCRYPT:
            encrypt(plaintext, key, keySize, ciphertext);
            printf("Ciphertext: %s\n", ciphertext);
            break;
        case DECRYPT:
            strcpy(plaintext, ciphertext);
            decrypt(plaintext, key, keySize, plaintext);
            printf("Plaintext: %s\n", plaintext);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}