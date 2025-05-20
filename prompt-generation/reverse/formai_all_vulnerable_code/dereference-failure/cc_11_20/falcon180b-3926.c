//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[])
{
    if (argc!= 3)
    {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char key[MAX_KEY_LENGTH];

    if (strcmp(mode, "encrypt")!= 0 && strcmp(mode, "decrypt")!= 0)
    {
        printf("Invalid mode. Use either 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    FILE *input = fopen(input_file, "r");
    if (input == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    if (strcmp(mode, "encrypt") == 0)
    {
        printf("Enter encryption key: ");
        fgets(key, MAX_KEY_LENGTH, stdin);
        key[strcspn(key, "\n")] = '\0';
    }
    else
    {
        printf("Enter decryption key: ");
        fgets(key, MAX_KEY_LENGTH, stdin);
        key[strcspn(key, "\n")] = '\0';
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, input)!= NULL)
    {
        if (strcmp(mode, "encrypt") == 0)
        {
            for (int i = 0; i < strlen(buffer); i++)
            {
                if (isalpha(buffer[i]))
                {
                    char c = buffer[i];
                    if (isupper(c))
                    {
                        c = 'A' + (c - 'A' + key[i % strlen(key)] - 'A') % 26;
                    }
                    else
                    {
                        c = 'a' + (c - 'a' + key[i % strlen(key)] - 'a') % 26;
                    }
                    buffer[i] = c;
                }
            }
        }
        else if (strcmp(mode, "decrypt") == 0)
        {
            for (int i = 0; i < strlen(buffer); i++)
            {
                if (isalpha(buffer[i]))
                {
                    char c = buffer[i];
                    if (isupper(c))
                    {
                        c = 'A' + (c - 'A' - key[i % strlen(key)] + 26) % 26;
                    }
                    else
                    {
                        c = 'a' + (c - 'a' - key[i % strlen(key)] + 26) % 26;
                    }
                    buffer[i] = c;
                }
            }
        }

        fputs(buffer, output);
    }

    fclose(input);
    fclose(output);

    printf("Done.\n");
    return 0;
}