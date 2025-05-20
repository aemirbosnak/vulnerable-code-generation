//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SET_SIZE 64
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-={}|:<>?,./;'"

int main(int argc, char **argv)
{
    FILE *input_file;
    FILE *output_file;
    char input_filename[100];
    char output_filename[100];
    char line[1000];
    int char_set_index;
    int pixel_value;
    int width, height, max_value;

    // Read input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Read output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open input file
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get image dimensions
    fseek(input_file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    // Calculate maximum pixel value
    fseek(input_file, 54, SEEK_SET);
    fread(&max_value, sizeof(int), 1, input_file);

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL)
    {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Write header to output file
    fprintf(output_file, "P5\n%d %d\n%d\n", width, height, max_value);

    // Loop through each line of the image
    while (fgets(line, sizeof(line), input_file)!= NULL)
    {
        // Loop through each character in the line
        for (int i = 0; i < strlen(line); i++)
        {
            // Convert pixel value to character in char set
            pixel_value = line[i];
            char_set_index = pixel_value % CHAR_SET_SIZE;
            fprintf(output_file, "%c", CHAR_SET[char_set_index]);
        }
        // Move to next line
        fprintf(output_file, "\n");
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Image converted to ASCII art successfully!\n");

    return 0;
}