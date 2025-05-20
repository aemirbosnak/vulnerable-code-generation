//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int idx, spaces, tabs, i = 0, j = 0, k = 0;
    char c;
    char code[100000], out[100000];

    FILE *fptr;

    fptr = fopen("input.html", "r");

    if (fptr == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }

    while ((c = fgetc(fptr)) != EOF)
    {
        code[i++] = c;
    }

    code[i] = '\0';
    fclose(fptr);

    i = 0;
    while (code[i] != '\0')
    {
        if (code[i] == '\n')
        {
            spaces = 0;
            tabs = 0;
            j = i + 1;

            while (code[j] == ' ')
            {
                spaces++;
                j++;
            }

            while (code[j] == '\t')
            {
                tabs++;
                j++;
            }

            if (tabs > 0)
            {
                spaces += (tabs * 4);
            }

            k = 0;
            while (k < spaces)
            {
                out[idx++] = ' ';
                k++;
            }

            i = j;
        }
        else
        {
            out[idx++] = code[i++];
        }
    }

    out[idx] = '\0';

    fptr = fopen("output.html", "w");

    if (fptr != NULL)
    {
        fprintf(fptr, "%s", out);
        fclose(fptr);
        printf("File beautified successfully.");
    }
    else
    {
        printf("Error creating output file.");
    }

    return 0;
}