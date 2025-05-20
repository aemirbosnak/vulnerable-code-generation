//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include<stdio.h>
#include<string.h>

//Key for encryption and decryption
char key[] = "SecretKey";

//Encryption function
void encrypt(char plainText[], char cipherText[])
{
    int i, j, k = 0;
    int len = strlen(key);
    int lenPlain = strlen(plainText);
    
    for(i = 0; i < lenPlain; i++)
    {
        j = k % len;
        cipherText[i] = ((plainText[i] ^ key[j]) + 65) % 26 + 97; //XOR operation with key
        k++;
    }
    cipherText[i] = '\0';
}

//Decryption function
void decrypt(char cipherText[], char decryptedText[])
{
    int i, j, k = 0;
    int len = strlen(key);
    int lenCipher = strlen(cipherText);
    
    for(i = 0; i < lenCipher; i++)
    {
        j = k % len;
        decryptedText[i] = (((cipherText[i] - 65) ^ key[j]) + 26) % 26 + 97; //XOR operation with key
        k++;
    }
    decryptedText[i] = '\0';
}

int main()
{
    char plainText[100], cipherText[100], decryptedText[100];
    
    printf("Enter the plain text:\n");
    scanf("%s", plainText);
    
    encrypt(plainText, cipherText);
    printf("\nCipher Text: %s", cipherText);
    
    decrypt(cipherText, decryptedText);
    printf("\nDecrypted Text: %s", decryptedText);
    
    return 0;
}