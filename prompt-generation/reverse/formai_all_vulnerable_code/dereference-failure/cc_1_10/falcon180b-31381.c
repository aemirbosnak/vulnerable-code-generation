//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_LINE_LEN 1000

// Function to encrypt a file
void encrypt_file(FILE* input_file, FILE* output_file, char* key)
{
    char input_buffer[MAX_LINE_LEN];
    char output_buffer[MAX_LINE_LEN];
    int key_index = 0;

    while (fgets(input_buffer, MAX_LINE_LEN, input_file)!= NULL)
    {
        int i = 0;
        while (i < strlen(input_buffer))
        {
            if (isalpha(input_buffer[i]))
            {
                output_buffer[i] = input_buffer[i] + key_index;
                if (!isalpha(output_buffer[i]))
                {
                    output_buffer[i] = tolower(output_buffer[i]);
                }
                key_index++;
                if (key_index >= strlen(key))
                {
                    key_index = 0;
                }
            }
            else
            {
                output_buffer[i] = input_buffer[i];
            }
            i++;
        }
        fputs(output_buffer, output_file);
    }
}

int main()
{
    FILE* input_file;
    FILE* output_file;
    char input_filename[MAX_LINE_LEN];
    char output_filename[MAX_LINE_LEN];
    char key[MAX_KEY_LEN];

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Get encryption key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    // Encrypt file
    encrypt_file(input_file, output_file, key);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}