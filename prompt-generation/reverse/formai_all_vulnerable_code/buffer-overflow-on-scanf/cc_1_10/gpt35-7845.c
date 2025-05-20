//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given string using the Caesar Cipher algorithm
void encrypt(char *str, int n)
{
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        // Apply the Caesar Cipher to each character in the string
        int c = str[i];
        if(c >= 'a' && c <= 'z')
        {
            c = (c + n - 'a') % 26 + 'a';
        }
        else if(c >= 'A' && c <= 'Z')
        {
            c = (c + n - 'A') % 26 + 'A';
        }
        str[i] = c;
    }
}

// Function to decrypt the given string using the Caesar Cipher algorithm
void decrypt(char *str, int n)
{
    // To decrypt the string, we just need to apply the cipher with a negative shift
    encrypt(str, 26 - n);
}

int main(void)
{
    char input[100];
    int rotation;

    // Prompt the user for input
    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);

    // Prompt the user for the rotation amount
    printf("Enter a rotation amount: ");
    scanf("%d", &rotation);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = '\0';

    // Encrypt the input string
    encrypt(input, rotation);
    printf("Encrypted string: %s\n", input);

    // Decrypt the encrypted string
    decrypt(input, rotation);
    printf("Decrypted string: %s\n", input);

    return 0;
}