//FormAI DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <string.h>

const int MAX_LENGTH = 100;

char encrypt(char c, int key)
{
    char result;
    if(c >= 'A' && c <= 'Z')
    {
        result = (((c - 'A') + key) % 26) + 'A';
    }
    else if(c >= 'a' && c <= 'z')
    {
        result = (((c - 'a') + key) % 26) + 'a';
    }
    else if(c >= '0' && c <= '9')
    {
        result = (((c - '0') + key) % 10) + '0';
    }
    else
    {
        result = c;
    }
    return result;
}

char* encryptString(char* s, int key)
{
    char* result = (char*) malloc(MAX_LENGTH * sizeof(char));
    int i;
    for(i = 0; i < strlen(s); i++)
    {
        char encrypted_char = encrypt(s[i], key);
        result[i] = encrypted_char;
    }
    return result;
}

int main()
{
    char input_string[MAX_LENGTH];
    int key;
    printf("Enter a string to encrypt: ");
    fgets(input_string, MAX_LENGTH, stdin);
    printf("Enter an encryption key: ");
    scanf("%d", &key);
    char* encrypted_string = encryptString(input_string, key);
    printf("Encrypted string: %s", encrypted_string);
    free(encrypted_string);
    return 0;
}