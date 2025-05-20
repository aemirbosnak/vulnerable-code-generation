//FormAI DATASET v1.0 Category: File Encyptor ; Style: medieval
// Medieval File Encryptor

#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *file = NULL, *encryptedFile = NULL;
    char fileName[50], ch;
    int key;

    printf("Welcome to the Medieval File Encryptor\n");
    printf("Enter the file name to encrypt: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Enter the key to encrypt the file: ");
    scanf("%d", &key);

    encryptedFile = fopen("encrypted_file.txt", "w");

    if (encryptedFile == NULL)
    {
        printf("Error: Could not create encrypted file.\n");
        return 1;
    }

    ch = fgetc(file);
    while (ch != EOF)
    {
        if (isalpha(ch))
        {
            // Encrypt alphabet characters only
            int upperBound = isupper(ch) ? 'Z' : 'z';
            int loweredCh = tolower(ch);
            int cipherChar = ((loweredCh - 'a' + key) % 26) + 'a';
            if (isupper(ch))
            {
                cipherChar = toupper(cipherChar);
            }
            fputc(cipherChar,encryptedFile);
        }
        else
        {
            fputc(ch, encryptedFile);
        }
        ch = fgetc(file);
    }

    fclose(file);
    fclose(encryptedFile);

    printf("Encryption complete. Encrypted file saved as 'encrypted_file.txt'\n");

    return 0;
}