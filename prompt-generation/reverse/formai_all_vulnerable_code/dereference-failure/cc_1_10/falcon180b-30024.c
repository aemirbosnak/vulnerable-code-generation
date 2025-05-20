//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int main()
{
    char input_file_name[MAX_LINE_LENGTH];
    char output_file_name[MAX_LINE_LENGTH];
    FILE *input_file;
    FILE *output_file;

    // Get input file name from user
    printf("Enter input file name: ");
    fgets(input_file_name, MAX_LINE_LENGTH, stdin);
    input_file_name[strcspn(input_file_name, "\n")] = '\0';

    // Open input file for reading
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL)
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get output file name from user
    printf("Enter output file name: ");
    fgets(output_file_name, MAX_LINE_LENGTH, stdin);
    output_file_name[strcspn(output_file_name, "\n")] = '\0';

    // Open output file for writing
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL)
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read input file line by line and write to output file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL)
    {
        int i = 0;
        while (line[i]!= '\0')
        {
            if (isalpha(line[i]))
            {
                line[i] = toupper(line[i]);
            }
            i++;
        }
        fprintf(output_file, "%s", line);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Image editing completed successfully.\n");
    return 0;
}