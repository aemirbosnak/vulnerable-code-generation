//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv)
{
    FILE *infile;
    FILE *outfile;
    char *input_file;
    char *output_file;
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int i, j, k, len;

    if (argc != 3)
    {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = argv[1];
    output_file = argv[2];

    infile = fopen(input_file, "r");
    if (!infile)
    {
        printf("Unable to open input file \"%s\"\n", input_file);
        return 1;
    }

    outfile = fopen(output_file, "w");
    if (!outfile)
    {
        printf("Unable to open output file \"%s\"\n", output_file);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, infile))
    {
        len = strlen(line);

        for (i = 0; i < len; i++)
        {
            if (line[i] == '<')
            {
                if (line[i+1] == '/')
                {
                    indent_level--;
                }

                for (j = 0; j < indent_level; j++)
                {
                    fputc('\t', outfile);
                }

                if (line[i+1] != '/')
                {
                    indent_level++;
                }

                fputc(line[i], outfile);
                i++;

                while (line[i] != ' ' && line[i] != '>' && i < len)
                {
                    fputc(line[i], outfile);
                    i++;
                }

                fputc(line[i], outfile);

                if (line[i] == '>')
                {
                    fputc('\n', outfile);
                }

                if (line[i-1] == '/')
                {
                    indent_level--;
                }

            }
            else
            {
                fputc(line[i], outfile);
            }
        }
    }

    fclose(infile);
    fclose(outfile);

    printf("Beautified HTML written to \"%s\"\n", output_file);

    return 0;
}