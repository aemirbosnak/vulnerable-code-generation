//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *filename)
{
    FILE *f;
    char buffer[256];
    char line[256];
    char output[256];
    char *indent = "";
    int i;

    if ( (f = fopen(filename, "r")) == NULL )
    {
        perror("Error opening file");
        return;
    }

    while ( fgets(line, sizeof(line), f)!= NULL )
    {
        if (line[0] == '<')
        {
            fclose(f);
            return;
        }

        if (line[strlen(line)-1] == '>')
        {
            line[strlen(line)-1] = '\0';
        }

        for (i = 0; i < strlen(line); i++)
        {
            if (line[i] == '<')
            {
                if (indent!= NULL)
                {
                    sprintf(output, "%s%s", indent, line);
                }
                else
                {
                    sprintf(output, "%s%s", line);
                }
                break;
            }

            if (line[i] == '>')
            {
                if (indent!= NULL)
                {
                    sprintf(output, "%s</%s>", indent, line);
                }
                else
                {
                    sprintf(output, "</%s>", line);
                }
                break;
            }

            indent = "    ";
            sprintf(output, "%s%c", indent, line[i]);
        }

        printf("%s\n", output);
    }

    fclose(f);
}

int main(int argc, char **argv)
{
    if (argc!= 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(0);
    }

    beautify(argv[1]);

    return 0;
}