//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for a file name
    char filename[256];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", filename);

    // Open the file for reading
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    // Create the encrypted file name
    char encrypted_filename[256];
    strcpy(encrypted_filename, filename);
    strcat(encrypted_filename, ".enc");

    // Open the encrypted file for writing
    FILE *output_file = fopen(encrypted_filename, "w");
    if (output_file == NULL)
    {
        printf("Error creating encrypted file: %s\n", encrypted_filename);
        fclose(input_file);
        return 1;
    }

    // Read the input file line by line
    char line[256];
    while (fgets(line, sizeof(line), input_file)!= NULL)
    {
        // Encrypt the line using a simple substitution cipher
        char encrypted_line[256];
        int i;
        for (i = 0; line[i]!= '\0'; i++)
        {
            if (isalpha(line[i]))
            {
                if (isupper(line[i]))
                {
                    encrypted_line[i] = 'A' + rand() % 26;
                }
                else
                {
                    encrypted_line[i] = 'a' + rand() % 26;
                }
            }
            else
            {
                encrypted_line[i] = line[i];
            }
        }
        encrypted_line[i] = '\0';

        // Write the encrypted line to the output file
        fputs(encrypted_line, output_file);
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}