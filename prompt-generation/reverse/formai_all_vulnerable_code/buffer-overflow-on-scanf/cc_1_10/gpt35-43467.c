//FormAI DATASET v1.0 Category: Image Editor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Display a Welcome Message
    printf("Welcome to my Image Editor!\n\n");

    // Ask the user for the file name
    char file_name[50];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the input file
    FILE *input_file;
    input_file = fopen(file_name, "r");

    // Check if the input file exists
    if (input_file == NULL) {
        printf("Error: The file \"%s\" does not exist or could not be opened.\n", file_name);
        exit(1);
    }

    // Ask the user for the output file name
    char output_file_name[50];
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    // Open the output file
    FILE *output_file;
    output_file = fopen(output_file_name, "w");

    // Check if the output file was successfully created
    if (output_file == NULL) {
        printf("Error: The output file \"%s\" could not be created.\n", output_file_name);
        exit(1);
    }

    // Read the contents of the input file and write it to the output file
    char c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(c, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    // Display a message that the image has been successfully edited
    printf("The image has been successfully edited!\n");

    return 0;
}