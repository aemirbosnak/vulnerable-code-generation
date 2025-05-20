//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, char *key);
void decrypt(char *text, char *key);

int main()
{
    char text[100], key[26];
    int choice;
    
    printf("Enter the text to encrypt/decrypt (max 100 characters): ");
    fgets(text, 100, stdin);
    // Removing the newline character at the end of text
    text[strcspn(text, "\n")] = 0;

    printf("Enter the key (max 26 characters): ");
    fgets(key, 26, stdin);
    // Removing the newline character at the end of key
    key[strcspn(key, "\n")] = 0;
    
    do
    {
        printf("Enter your choice:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice)
        {
            case 1:
                encrypt(text, key);
                printf("Encrypted text: %s\n", text);
                break;
            case 2:
                decrypt(text, key);
                printf("Decrypted text: %s\n", text);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}

void encrypt(char *text, char *key)
{
    int i, j, k;
    char cipher[26], c;
    
    // Converting the key to uppercase
    for(i=0; key[i]; i++)
    {
        key[i] = toupper(key[i]);
    }
    
    // Generating the cipher by removing repeated characters
    k = 0;
    for(i=0; key[i]; i++)
    {
        if(!strchr(cipher, key[i]))
        {
            cipher[k++] = key[i];
        }
    }
    for(i=0; i<26; i++)
    {
        if(!strchr(cipher, 'A'+i))
        {
            cipher[k++] = 'A'+i;
        }
    }
    cipher[k] = '\0';

    // Transposing the text using the cipher
    for(i=0; text[i]; i++)
    {
        if(isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                c = toupper(text[i]);
                text[i] = tolower(cipher[c-'A']);
            }
            else
            {
                text[i] = cipher[text[i]-'A'];
            }
        }
    }
}

void decrypt(char *text, char *key)
{
    int i, j, k;
    char cipher[26], c;
    
    // Converting the key to uppercase
    for(i=0; key[i]; i++)
    {
        key[i] = toupper(key[i]);
    }
    
    // Generating the cipher by removing repeated characters
    k = 0;
    for(i=0; key[i]; i++)
    {
        if(!strchr(cipher, key[i]))
        {
            cipher[k++] = key[i];
        }
    }
    for(i=0; i<26; i++)
    {
        if(!strchr(cipher, 'A'+i))
        {
            cipher[k++] = 'A'+i;
        }
    }
    cipher[k] = '\0';

    // Transposing the text using the inverse of the cipher
    for(i=0; text[i]; i++)
    {
        if(isalpha(text[i]))
        {
            if(islower(text[i]))
            {
                c = toupper(text[i]);
                for(j=0; j<26; j++)
                {
                    if(cipher[j] == tolower(text[i]))
                    {
                        text[i] = 'a' + j;
                        break;
                    }
                }
            }
            else
            {
                for(j=0; j<26; j++)
                {
                    if(cipher[j] == text[i])
                    {
                        text[i] = 'A' + j;
                        break;
                    }
                }
            }
        }
    }
}