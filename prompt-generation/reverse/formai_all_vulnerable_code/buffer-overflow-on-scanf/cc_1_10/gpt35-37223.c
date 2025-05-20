//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *fpin, *fpout;
    char in_file[100], out_file[100], c;
    int indent = 0, i;

    //asking for input and output file names
    printf("Enter the input file name: ");
    scanf("%s", in_file);
    printf("\nEnter the output file name: ");
    scanf("%s", out_file);

    //opening input file in read mode
    fpin = fopen(in_file, "r");

    //checking if input file exists or not
    if(fpin == NULL)
    {
        printf("\nFile not found!\n");
        exit(1);
    }

    //opening output file in write mode
    fpout = fopen(out_file, "w");

    //fetching characters from input file
    while((c = fgetc(fpin)) != EOF)
    {
        //if '<' is found then increase indent
        if(c == '<')
        {
            indent++;

            //printing the '<' character
            fprintf(fpout, "%c", c);

            //checking for the tag name
            while((c = fgetc(fpin)) != ' ')
            {
                fprintf(fpout, "%c", c);
            }

            fprintf(fpout, "\n");

            //printing the indent
            for(i = 0; i < indent; i++)
            {
                fprintf(fpout, "  ");
            }
        }
        //if '>' is found then decrease indent
        else if(c == '>')
        {
            fprintf(fpout, "%c", c);
            fprintf(fpout, "\n");

            //printing the indent
            for(i = 0; i < indent; i++)
            {
                fprintf(fpout, "  ");
            }
        }
        //printing the character
        else
        {
            fprintf(fpout, "%c", c);
        }
    }

    //closing the files
    fclose(fpin);
    fclose(fpout);

    printf("\nHTML beautifier done successfully!\n");

    return 0;
}