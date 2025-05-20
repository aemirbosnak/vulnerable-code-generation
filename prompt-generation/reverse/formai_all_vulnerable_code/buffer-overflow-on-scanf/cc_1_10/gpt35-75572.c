//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define ROTATION_AMOUNT 13

void rotate(char *text, int key);
void encrypt_caesar(char *text, int key);
void decrypt_caesar(char *text, int key);
void encrypt_substitution(char *text, char *key);
void decrypt_substitution(char *text, char *key);

int main()
{
    char plain_text[1024], substitution_key[ALPHABET_SIZE], caesar_key;
    
    printf("Enter the plain text: ");
    fgets(plain_text, 1024, stdin);
    plain_text[strcspn(plain_text, "\n")] = '\0';
    
    printf("\n----- Caesar Cipher -----\n");
    printf("Enter the Caesar cipher key (0-25): ");
    scanf("%d", &caesar_key);
    getchar();
    
    encrypt_caesar(plain_text, caesar_key);
    printf("\nEncrypted text: %s\n", plain_text);
    
    decrypt_caesar(plain_text, caesar_key);
    printf("Decrypted text: %s\n", plain_text);
    
    printf("\n----- Substitution Cipher -----\n");
    printf("Enter the 26-letter substitution cipher key: ");
    fgets(substitution_key, ALPHABET_SIZE+1, stdin);
    substitution_key[strcspn(substitution_key, "\n")] = '\0';
    
    encrypt_substitution(plain_text, substitution_key);
    printf("\nEncrypted text: %s\n", plain_text);
    
    decrypt_substitution(plain_text, substitution_key);
    printf("Decrypted text: %s\n", plain_text);
    
    return 0;
}

void rotate(char *text, int key)
{
    int i;
    
    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a' + key) % ALPHABET_SIZE) + 'a';
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' + key) % ALPHABET_SIZE) + 'A';
        }
    }
}

void encrypt_caesar(char *text, int key)
{
    rotate(text, key);
}

void decrypt_caesar(char *text, int key)
{
    rotate(text, ALPHABET_SIZE - key);
}

void encrypt_substitution(char *text, char *key)
{
    int i;
    char substitutions[ALPHABET_SIZE];
    strcpy(substitutions, key);
    
    for(i = 0; substitutions[i] != '\0'; i++)
    {
        if(substitutions[i] >= 'a' && substitutions[i] <= 'z')
        {
            substitutions[i] = toupper(substitutions[i]);
        }
        else if(substitutions[i] < 'A' || substitutions[i] > 'Z')
        {
            substitutions[i] = '\0';
        }
    }
    
    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = substitutions[text[i] - 'a'] + 32;
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = substitutions[text[i] - 'A'];
        }
    }
}

void decrypt_substitution(char *text, char *key)
{
    int i, j;
    char substitutions[ALPHABET_SIZE], temp;
    strcpy(substitutions, key);
    
    for(i = 0; substitutions[i] != '\0'; i++)
    {
        if(substitutions[i] >= 'a' && substitutions[i] <= 'z')
        {
            substitutions[i] = toupper(substitutions[i]);
        }
        else if(substitutions[i] < 'A' || substitutions[i] > 'Z')
        {
            substitutions[i] = '\0';
        }
    }
    
    for(i = 0; i < ALPHABET_SIZE; i++)
    {
        for(j = i + 1; j < ALPHABET_SIZE; j++)
        {
            if(substitutions[i] > substitutions[j])
            {
                temp = substitutions[i];
                substitutions[i] = substitutions[j];
                substitutions[j] = temp;
            }
        }
    }
    
    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (char)(tolower(substitutions[text[i] - 'a']) - ROTATION_AMOUNT);
        }
        else if(text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = substitutions[text[i] - 'A'] - ROTATION_AMOUNT;
        }
    }
}