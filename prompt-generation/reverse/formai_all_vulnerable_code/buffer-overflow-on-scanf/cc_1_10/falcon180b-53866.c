//Falcon-180B DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 1000

//Function to check if string is a palindrome or not
int isPalindrome(char *str)
{
    int len = strlen(str);
    for(int i=0; i<len/2; i++)
    {
        if(str[i]!= str[len-i-1])
        {
            return 0;
        }
    }
    return 1;
}

//Function to encrypt the string using Caesar cipher
void encrypt(char *str, int key)
{
    int len = strlen(str);
    char encrypted[MAX_SIZE];
    encrypted[0] = '\0';
    for(int i=0; i<len; i++)
    {
        if(isalpha(str[i]))
        {
            if(isupper(str[i]))
            {
                encrypted[i] = (str[i] + key - 65) % 26 + 65;
            }
            else
            {
                encrypted[i] = (str[i] + key - 97) % 26 + 97;
            }
        }
        else
        {
            encrypted[i] = str[i];
        }
    }
    printf("Encrypted string: %s\n", encrypted);
}

//Function to decrypt the string using Caesar cipher
void decrypt(char *str, int key)
{
    int len = strlen(str);
    char decrypted[MAX_SIZE];
    decrypted[0] = '\0';
    for(int i=0; i<len; i++)
    {
        if(isalpha(str[i]))
        {
            if(isupper(str[i]))
            {
                decrypted[i] = (str[i] - key - 65) % 26 + 65;
            }
            else
            {
                decrypted[i] = (str[i] - key - 97) % 26 + 97;
            }
        }
        else
        {
            decrypted[i] = str[i];
        }
    }
    printf("Decrypted string: %s\n", decrypted);
}

int main()
{
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Original string: %s\n", str);
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    encrypt(str, key);
    decrypt(str, key);
    return 0;
}