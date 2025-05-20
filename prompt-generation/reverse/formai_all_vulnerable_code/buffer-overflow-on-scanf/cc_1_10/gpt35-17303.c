//FormAI DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* encrypt(char* inputStr, int key);
char* decrypt(char* inputStr, int key);

int main(){

    printf("Welcome to the Modern Encryption Program!\n");

    char *toEncrypt = malloc(sizeof(char)*100);
    char *toDecrypt = malloc(sizeof(char)*100);

    printf("Enter a string to encrypt: ");
    scanf("%s", toEncrypt);

    int key = 0;

    while(key <= 0){
        printf("Enter a positive integer key: ");
        scanf("%d", &key);
    }

    char *encryptedStr = encrypt(toEncrypt, key);

    printf("\nEncrypted string: %s\n", encryptedStr);

    printf("\nEnter a string to decrypt: ");
    scanf("%s", toDecrypt);

    char *decryptedStr = decrypt(toDecrypt, key);

    printf("\nDecrypted string: %s\n", decryptedStr);

    free(toEncrypt);
    free(toDecrypt);

    return 0;
}

char* encrypt(char* inputStr, int key){
    int strLen = strlen(inputStr);

    char* encrypted = malloc(sizeof(char)*strLen);

        for(int i = 0; i < strLen; i++){
            int numVal = (int)inputStr[i];

            if(numVal >= 65 && numVal <= 90){
                numVal += key;

                if(numVal > 90){
                    numVal -= 26;
                }
            }

            if(numVal >= 97 && numVal <= 122){
                numVal += key;

                if(numVal > 122){
                    numVal -= 26;
                }
            }

          encrypted[i] = (char)numVal;
        }

    return encrypted;
}

char* decrypt(char* inputStr, int key){
    int strLen = strlen(inputStr);

    char* decrypted = malloc(sizeof(char)*strLen);

        for(int i = 0; i < strLen; i++){
            int numVal = (int)inputStr[i];

            if(numVal >= 65 && numVal <= 90){
                numVal -= key;

                if(numVal < 65){
                    numVal += 26;
                }
            }

            if(numVal >= 97 && numVal <= 122){
                numVal -= key;

                if(numVal < 97){
                    numVal += 26;
                }
            }

          decrypted[i] = (char)numVal;
        }

    return decrypted;
}