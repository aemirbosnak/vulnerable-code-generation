//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

//Function to encrypt a string using the Caesar Cipher
char* caesarCipher(char* text, int key)
{
    int i;

    for(i = 0; i < strlen(text); i++)
    {
        //Encrypt uppercase characters
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = 'A' + (text[i] - 'A' + key) % 26;
        }
        //Encrypt lowercase characters
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = 'a' + (text[i] - 'a' + key) % 26;
        }
        //Continue for other characters
    }

    return text;
}

//Function to decrypt a string using the Caesar Cipher
char* caesarCipherDecrypt(char* text, int key)
{
    int i;

    for(i = 0; i < strlen(text); i++)
    {
        //Decrypt uppercase characters
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = 'A' + (text[i] - 'A' - key + 26) % 26;
        }
        //Decrypt lowercase characters
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = 'a' + (text[i] - 'a' - key + 26) % 26;
        }
        //Continue for other characters
    }

    return text;
}

//Main function
int main()
{
    char text[100], encryptedText[100], decryptedText[100];
    int key;

    printf("Enter the text to be encrypted: ");
    gets(text);

    printf("Enter the key (1-25): ");
    scanf("%d", &key);

    //Encrypt the text
    strcpy(encryptedText, caesarCipher(text, key));

    printf("Encrypted Text: %s\n", encryptedText);

    //Decrypt the encrypted text
    strcpy(decryptedText, caesarCipherDecrypt(encryptedText, key));

    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}