//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *filename);

int main()
{
    char filename[50];
    printf("Enter the name of the HTML file to beautify: ");
    scanf("%s",filename);
    beautify(filename);
    return 0;
}

void beautify(char *filename)
{
    FILE *fp, *temp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found!\n");
        exit(0);
    }
    temp = fopen("temp.html", "w+");
    if (temp == NULL)
    {
        printf("Error creating temporary file!\n");
        exit(0);
    }
    char c;
    int indent_level = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '<')
        {
            fputc(c, temp);
            c = fgetc(fp);
            if (c == '/')
            {
                indent_level--;
                putchar('\n');
                for (int i = 0; i < indent_level; i++)
                    fputs("    ", temp);
            }
            else
            {
                putchar('\n');
                for (int i = 0; i < indent_level; i++)
                    fputs("    ", temp);
                indent_level++;
            }
        }
        else if (c == '>')
        {
            fputc(c, temp);
            putchar('\n');
            for (int i = 0; i < indent_level; i++)
                fputs("    ", temp);
        }
        else
            fputc(c, temp);
    }
    fclose(fp);
    fclose(temp);
    remove(filename);
    rename("temp.html", filename);
    printf("Beautification complete!\n");
}