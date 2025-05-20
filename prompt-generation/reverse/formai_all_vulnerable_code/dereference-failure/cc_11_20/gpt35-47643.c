//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *input_file, *output_file;
    char input_file_name[20], output_file_name[20];
    char c, prev_c = ' ';
    int indent_level = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    input_file = fopen(input_file_name, "r");

    if (input_file == NULL) 
    {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "w");

    if (output_file == NULL) 
    {
        printf("Error opening output file.\n");
        exit(1);
    }

    while ((c = fgetc(input_file)) != EOF) 
    {
        if (c == '\n') 
        {
            fputc('\n', output_file);
            prev_c = ' ';
        }
        else if (c == '{') 
        {
            fputc('\n', output_file);

            for (int i = 0; i < indent_level; i++) 
            {
                fputc('\t', output_file);
            }

            fputc('{', output_file);
            fputc('\n', output_file);

            indent_level += 1;
            prev_c = ' ';
        }
        else if (c == '}') 
        {
            fputc('\n', output_file);

            indent_level -= 1;

            for (int i = 0; i < indent_level; i++) 
            {
                fputc('\t', output_file);
            }

            fputc('}', output_file);
            fputc('\n', output_file);

            prev_c = ' ';
        }
        else if (prev_c == '{') 
        {
            fputc('\n', output_file);

            for (int i = 0; i < indent_level; i++) 
            {
                fputc('\t', output_file);
            }

            fputc(c, output_file);
            prev_c = c;
        }
        else 
        {
            fputc(c, output_file);
            prev_c = c;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}