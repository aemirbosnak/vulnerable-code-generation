//FormAI DATASET v1.0 Category: Encryption ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char s[100], key[100];
    int i, j, k=0;
    
    printf("Enter the message to be encrypted: ");
    fgets(s, sizeof(s), stdin);
    
    printf("Enter the key to be used for encryption: ");
    fgets(key, sizeof(key), stdin);
    
    //Removing newline character from the message and key
    s[strcspn(s, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    
    //Converting the key to uppercase
    for(i=0; i<strlen(key); i++)
    {
        key[i] = toupper(key[i]);
    }
    
    //Finding length of the key
    int key_len = strlen(key);
    
    //Creating an array to store the key in integer values
    int key_int[key_len];
    
    //Converting the key from characters to numbers
    for(i=0; i<key_len; i++)
    {
        key_int[i] = key[i] - 'A';
    }
    
    //Encrypting the message
    for(i=0; i<strlen(s); i++)
    {
        if(isalpha(s[i]))
        {
            //Converting the plaintext character to integer value
            int val = s[i] - 'A';
            
            //Adding the corresponding key value to the plaintext value
            int val_enc = (val + key_int[k]) % 26;
            
            //Converting the encrypted integer value back to character
            char temp = val_enc + 'A';
            
            //Printing the encrypted character
            printf("%c", temp);
            
            //Updating the key index to use the next key value
            k++;
            
            //If we reach the last key value, start again from the beginning
            if(k == key_len)
            {
                k = 0;
            }
        }
        else
        {
            //Printing non-alphabetic characters as it is
            printf("%c", s[i]);
        }
    }
    
    return 0;
}