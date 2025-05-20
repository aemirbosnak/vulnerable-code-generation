//FormAI DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char plainText[1000], key[1000], cipherText[1000] = "", decryptedText[1000] = "";
    int i, j = 0, k = 0, m, n;
    
    printf("Enter plain text to encrypt: ");
    gets(plainText);
    
    printf("Enter key: ");
    gets(key);
    
    m = strlen(plainText);
    n = strlen(key);
    
    for (i = 0; i < m; i++)
    {
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            cipherText[i] = ((plainText[i] - 'a' + key[j] - 'a') % 26) + 'a';
            j = (++j) % n;
        }
        else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            cipherText[i] = ((plainText[i] - 'A' + key[j] - 'a') % 26) + 'A';
            j = (++j) % n;
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    
    cipherText[i] = '\0';
    
    printf("Cipher text: %s\n", cipherText);
    
    for (i = 0; i < m; i++)
    {
        if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
        {
            if ((cipherText[i] - key[k]) < 0)
            {
                decryptedText[i] = ((cipherText[i] - 'a' + 26 - key[k] + 'a') % 26) + 'a';
            }
            else
            {
                decryptedText[i] = ((cipherText[i] - 'a' - key[k] + 'a') % 26) + 'a';
            }
            
            k = (++k) % n;
        }
        else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
        {
            if ((cipherText[i] - key[k]) < 0)
            {
                decryptedText[i] = ((cipherText[i] - 'A' + 26 - key[k] + 'a') % 26) + 'A';
            }
            else
            {
                decryptedText[i] = ((cipherText[i] - 'A' - key[k] + 'a') % 26) + 'A';
            }
            
            k = (++k) % n;
        }
        else
        {
            decryptedText[i] = cipherText[i];
        }
    }
    
    decryptedText[i] = '\0';
    
    printf("Decrypted text: %s\n", decryptedText);
    
    return 0;
}