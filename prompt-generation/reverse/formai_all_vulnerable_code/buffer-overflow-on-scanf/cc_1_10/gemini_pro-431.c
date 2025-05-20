//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/* Key for encryption/decryption */
unsigned char key[] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};

/* Function to encrypt a file */
void encrypt_file(char *input_file, char *output_file)
{
    FILE *fin, *fout;
    unsigned char ch, enc_ch;
    int i;

    fin = fopen(input_file, "rb");
    if (fin == NULL)
    {
        printf("Error opening input file!\n");
        exit(1);
    }

    fout = fopen(output_file, "wb");
    if (fout == NULL)
    {
        printf("Error opening output file!\n");
        exit(1);
    }

    while ((ch = fgetc(fin)) != EOF)
    {
        for (i = 0; i < 8; i++)
        {
            enc_ch = ch ^ key[i];
            ch = enc_ch;
        }
        fputc(enc_ch, fout);
    }

    fclose(fin);
    fclose(fout);
}

/* Function to decrypt a file */
void decrypt_file(char *input_file, char *output_file)
{
    FILE *fin, *fout;
    unsigned char ch, dec_ch;
    int i;

    fin = fopen(input_file, "rb");
    if (fin == NULL)
    {
        printf("Error opening input file!\n");
        exit(1);
    }

    fout = fopen(output_file, "wb");
    if (fout == NULL)
    {
        printf("Error opening output file!\n");
        exit(1);
    }

    while ((ch = fgetc(fin)) != EOF)
    {
        for (i = 7; i >= 0; i--)
        {
            dec_ch = ch ^ key[i];
            ch = dec_ch;
        }
        fputc(dec_ch, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main()
{
    int choice;

    printf("1. Encrypt a file\n2. Decrypt a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        encrypt_file("input.txt", "encrypted.txt");
        printf("File encrypted successfully!\n");
        break;
    case 2:
        decrypt_file("encrypted.txt", "decrypted.txt");
        printf("File decrypted successfully!\n");
        break;
    default:
        printf("Invalid choice!\n");
    }

    return 0;
}