//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
    char input_file[256], output_file[256];
    char *key;
    int key_size;
    FILE *input, *output;
    char input_buffer[BUFFER_SIZE], output_buffer[BUFFER_SIZE];
    int i, j, k, n;

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    printf("Enter the key: ");
    scanf("%s", key);

    key_size = strlen(key);

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    if (input == NULL || output == NULL)
    {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while ((n = fread(input_buffer, sizeof(char), BUFFER_SIZE, input)) > 0)
    {
        for (i = 0, j = 0; i < n; i++)
        {
            if (isalpha(input_buffer[i]))
            {
                input_buffer[i] = tolower(input_buffer[i]);
                j = (j + input_buffer[i] - 'a' + key_size) % key_size;
                input_buffer[i] = key[j];
            }
            else
            {
                input_buffer[i] = input_buffer[i];
            }
        }
        fwrite(input_buffer, sizeof(char), n, output);
    }

    fclose(input);
    fclose(output);

    printf("File encrypted successfully!\n");

    return 0;
}