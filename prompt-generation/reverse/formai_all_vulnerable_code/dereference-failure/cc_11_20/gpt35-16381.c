//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp_input, *fp_output;
    char inputFile[100], outputFile[100], ch;
    int spaceCount=0, indentCount=0, i;

    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    printf("Enter the output file name: ");
    scanf("%s", outputFile);

    fp_input=fopen(inputFile, "r");

    if(fp_input == NULL)
    {
        printf("\nError: Unable to open file.\n");
        exit(1);
    }

    fp_output=fopen(outputFile, "w");

    if(fp_output == NULL)
    {
        printf("\nError: Unable to open file.\n");
        exit(1);
    }

    while((ch=fgetc(fp_input)) != EOF)
    {
        if(ch == '{' || ch == '}')
        {
            if(indentCount > 0)
            {
                for(i=1; i<=indentCount-1; i++)
                    fprintf(fp_output, "  ");
            }
            fprintf(fp_output, "%c\n", ch);
            if(ch == '{')
                indentCount++;
            if(ch == '}')
                indentCount--;
        }
        else if(ch == ';')
        {
            fprintf(fp_output, ";\n");
            if(spaceCount > 0)
            {
                for(i=1; i<=spaceCount; i++)
                    fprintf(fp_output, " ");
            }
        }
        else if(ch == '\n')
        {
            fprintf(fp_output, "\n");
            spaceCount=0;
        }
        else if(ch == ' ')
        {
            if(spaceCount == 0)
                fputc(' ', fp_output);
            spaceCount++;
        }
        else
        {
            fputc(ch, fp_output);
            spaceCount=0;
        }
    }

    fclose(fp_input);
    fclose(fp_output);

    printf("File beautified successfully.");

    return 0;
}