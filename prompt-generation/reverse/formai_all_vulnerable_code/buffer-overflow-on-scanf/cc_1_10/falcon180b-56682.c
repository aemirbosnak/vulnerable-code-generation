//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define SIZE 50
#define ALPHABET_SIZE 26

int main()
{
    char key[SIZE];
    char plainText[SIZE];
    char cipherText[SIZE];
    char alphabet[ALPHABET_SIZE];
    int i,j,k,n,m;
    srand(time(NULL));

    //Generating random key
    for(i=0;i<SIZE;i++)
    {
        key[i] = rand()%(ALPHABET_SIZE-1) + 'A';
    }

    //Generating alphabet
    for(i=0;i<ALPHABET_SIZE;i++)
    {
        alphabet[i] = i + 'A';
    }

    //Taking plain text input
    printf("Enter plain text: ");
    scanf("%s",plainText);

    //Encrypting plain text
    for(i=0,j=0;i<strlen(plainText);i++)
    {
        if(isalpha(plainText[i]))
        {
            if(isupper(plainText[i]))
            {
                m = (int)toupper(plainText[i]) - 65;
            }
            else
            {
                m = (int)tolower(plainText[i]) - 97;
            }

            if(isalpha(key[j]))
            {
                n = (int)toupper(key[j]) - 65;
            }
            else if(isdigit(key[j]))
            {
                n = (int)tolower(key[j]) - 48;
            }
            else
            {
                n = 0;
            }

            k = (m + n)%26;

            cipherText[j] = alphabet[k];
            j++;
        }
        else
        {
            cipherText[j] = plainText[i];
            j++;
        }
    }

    //Printing cipher text
    printf("Cipher text: %s",cipherText);

    return 0;
}