//FormAI DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10000

int main()
{
    // Ask the user for the input file name
    char input_file[50];
    printf("Enter the input file name: ");
    scanf("%s", input_file);

    // Ask the user for the output file name
    char output_file[50];
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Generate the encryption key
    char key[50];
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL)
    {
        printf("Could not open the input file.\n");
        return 1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL)
    {
        printf("Could not open the output file.\n");
        return 1;
    }

    // Read the input file to a char array
    char input_data[MAX_SIZE];
    size_t size = fread(input_data, 1, sizeof(input_data), input);

    // Create an encryption buffer
    char encryption_buffer[MAX_SIZE];

    // Loop through each character in the input data and encrypt it
    for (int i = 0; i < size; i++)
    {
        encryption_buffer[i] = input_data[i] ^ key[i % strlen(key)];
    }

    // Write the encrypted data to the output file
    fwrite(encryption_buffer, 1, size, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("The file has been encrypted successfully.\n");

    return 0;
}