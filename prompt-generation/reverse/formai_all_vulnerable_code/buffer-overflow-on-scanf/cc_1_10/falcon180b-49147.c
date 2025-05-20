//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Recursive function to encrypt the file
void encrypt(FILE *file, int key, int mode)
{
    char ch;
    int i = 0;

    // Reading the file character by character
    while ((ch = fgetc(file))!= EOF)
    {
        // Encrypting the character using the key
        if (ch >= 65 && ch <= 90)
        {
            ch = ch + key - 65;
            if (ch > 90)
            {
                ch = ch - 26;
            }
        }
        else if (ch >= 97 && ch <= 122)
        {
            ch = ch + key - 97;
            if (ch > 122)
            {
                ch = ch - 26;
            }
        }
        else
        {
            ch = ch;
        }

        // Writing the encrypted character to the file
        fputc(ch, file);
    }

    // Closing the file
    fclose(file);
}

int main()
{
    char filename[100];
    char mode[10];
    int key;

    // Taking user input for the filename, mode and key
    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Enter the mode (0 for encryption, 1 for decryption): ");
    scanf("%s", mode);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Opening the input file
    FILE *infile = fopen(filename, "r");

    // Checking if the file exists
    if (infile == NULL)
    {
        printf("File not found!\n");
        exit(0);
    }

    // Closing the input file
    fclose(infile);

    // Opening the input file in the appropriate mode
    if (strcmp(mode, "0") == 0)
    {
        encrypt(infile, key, 0);
    }
    else if (strcmp(mode, "1") == 0)
    {
        encrypt(infile, key, 1);
    }
    else
    {
        printf("Invalid mode!\n");
        exit(0);
    }

    // Closing the input file
    fclose(infile);

    return 0;
}