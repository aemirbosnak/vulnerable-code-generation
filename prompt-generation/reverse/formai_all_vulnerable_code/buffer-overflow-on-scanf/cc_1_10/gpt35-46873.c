//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fpIn, *fpOut;
    char fileName[100], ch;

    // Get user input for file name
    printf("Enter the input HTML file name: ");
    scanf("%s", fileName);

    // Open input file in read mode
    fpIn = fopen(fileName,"r");

    if(fpIn == NULL)
    {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    // Create output file with "_beauty" suffix
    char newFileName[100];
    sprintf(newFileName, "%s_beauty.html", fileName);
    fpOut = fopen(newFileName,"w");

    // Check if output file was created successfully
    if(fpOut == NULL)
    {
        printf("Could not open file %s\n", newFileName);
        exit(1);
    }

    int indent = 0; // initialize indent level
    while((ch = fgetc(fpIn)) != EOF)
    {
        if(ch == '<')
        {
            fprintf(fpOut, "\n"); // start a new line when opening tag found
            for(int i=0; i<indent; i++)
                fprintf(fpOut, "\t"); // add appropriate number of tabs
            indent++; // increase indent level
        }
        else if(ch == '>')
        {
            fprintf(fpOut, "%c\n", ch); // add closing bracket on a new line
            indent--; // decrease indent level
            for(int i=0; i<indent; i++)
                fprintf(fpOut, "\t"); // add appropriate number of tabs
        }
        else
            fprintf(fpOut, "%c", ch); // write character to output file
    }

    printf("\nInput file has been beautified and stored as %s\n", newFileName);

    fclose(fpIn);
    fclose(fpOut);
    return 0;
}