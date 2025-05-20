//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[100];
    char tmpfilename[100];
    char buffer[1024];

    printf("Enter input HTML file name (with .html extension): ");
    scanf("%s", filename);

    FILE *infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("File not found.\n");
        exit(1);
    }

    printf("Enter output HTML file name (with .html extension): ");
    scanf("%s", tmpfilename);

    FILE *outfile = fopen(tmpfilename, "w");
    if (outfile == NULL)
    {
        printf("Failed to create file.\n");
        exit(1);
    }

    int indent = 0;

    while (fgets(buffer, sizeof(buffer), infile) != NULL)
    {
        // Trim leading and trailing whitespace
        char *trimmed = strdup(buffer);
        char *end = trimmed + strlen(trimmed) - 1;
        while (end > trimmed && (*end == '\n' || *end == '\r' || *end == ' ' || *end == '\t'))
        {
            *end-- = '\0';
        }
        while (*trimmed == ' ' || *trimmed == '\t')
        {
            trimmed++;
        }

        if (strlen(trimmed) == 0)
        {
            continue; // skip empty lines
        }

        if (trimmed[0] == '<' && trimmed[strlen(trimmed)-1] == '>')
        {
            if (trimmed[1] == '/')
            {
                indent--;
            }

            for (int i = 0; i < indent; i++)
            {
                fprintf(outfile, "    ");
            }

            fprintf(outfile, "%s\n", trimmed);

            if (trimmed[1] != '/')
            {
                indent++;
            }
        }
        else
        {
            for (int i = 0; i < indent; i++)
            {
                fprintf(outfile, "    ");
            }

            fprintf(outfile, "%s\n", trimmed);
        }
    }

    fclose(infile);
    fclose(outfile);

    printf("Beautified HTML written to %s.\n", tmpfilename);

    return 0;
}