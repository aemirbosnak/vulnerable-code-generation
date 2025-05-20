//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define KEYLENGTH 100
#define BUFFER 1024

int main()
{
    char input[BUFFER];
    char output[BUFFER];
    char key[KEYLENGTH];
    int keyIndex = 0;

    printf("Enter the text to be encrypted: ");
    fgets(input, BUFFER, stdin);

    printf("Enter the encryption key: ");
    fgets(key, KEYLENGTH, stdin);
    int keyLength = strlen(key);
    key[keyLength-1] = '\0';
    keyLength--;

    // Encrypt
    int inputLength = strlen(input);
    for (int i = 0; i < inputLength; i++)
    {
        char ch = input[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            int offset = key[keyIndex%keyLength] - 'a';
            if (ch + offset > 'z')
                output[i] = 'a' + offset - ('z' - ch + 1);
            else if (ch + offset > 'Z' && ch + offset < 'a')
                output[i] = 'A' + offset - ('Z' - ch + 1);
            else
                output[i] = ch + offset;

            keyIndex++;
        }
        else
        {
            output[i] = ch;
        }
    }

    printf("Encrypted text is: %s\n", output);

    return 0;
}