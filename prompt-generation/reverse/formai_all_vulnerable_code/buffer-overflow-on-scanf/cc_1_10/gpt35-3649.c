//FormAI DATASET v1.0 Category: Encryption ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// A function to perform encryption
char* encrypt(char* plaintext, int key)
{
    int len = strlen(plaintext);
  
    // Generate a random salt
    srand(time(NULL));
    char salt[3];
    salt[0] = rand() % 26 + 'a';
    salt[1] = rand() % 26 + 'a';
    salt[2] = '\0';
    
    // Add salt to plaintext
    char* plaintext_with_salt = malloc(len+3);
    strcpy(plaintext_with_salt, salt);
    strcat(plaintext_with_salt, plaintext);
  
    // Apply encryption using the key
    char* ciphertext = malloc(len+3);
    for(int i = 0; i < len+2; i++)
    {
        if(i%2 == 0)
        {
            ciphertext[i] = plaintext_with_salt[i] + key;
        }
        else
        {
            ciphertext[i] = plaintext_with_salt[i] - key;
        }
    }
    ciphertext[len+2] = '\0';
  
    return ciphertext;
}

int main()
{
    char plaintext[100];
    int key;
  
    printf("Enter the plaintext: ");
    scanf("%s", &plaintext);
  
    printf("Enter the key: ");
    scanf("%d", &key);

    char* ciphertext = encrypt(plaintext, key);
  
    printf("Encrypted text: %s", ciphertext);
  
    return 0;
}