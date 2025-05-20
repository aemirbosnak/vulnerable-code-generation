//FormAI DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char plaintext[100];
    char key[26];
    char ciphertext[100];
    
    printf("Enter plaintext: ");
    scanf("%[^\n]", plaintext);
    getchar();
    
    printf("Enter key (must be 26 unique alphabets): ");
    scanf("%[^\n]", key);
    getchar();
    
    // Checking if key is valid
    if (strlen(key) != 26)
    {
        printf("Invalid key!");
        return 0;
    }
    
    for (int i = 0; i < 26; i++)
    {
        for (int j = i+1; j < 26; j++)
        {
            if (key[i] == key[j])
            {
                printf("Invalid key!");
                return 0;
            }
        }
    }
    
    // Encrypting
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        if (plaintext[i] == ' ')  // Handling spaces
        {
            ciphertext[i] = ' ';
            continue;
        }
        
        int index = plaintext[i] - 'a';
        ciphertext[i] = key[index];
    }
    
    printf("Ciphertext: %s", ciphertext);
    return 0;
}