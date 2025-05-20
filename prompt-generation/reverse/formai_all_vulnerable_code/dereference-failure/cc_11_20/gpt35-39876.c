//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautify(char *input_file, char *output_file);

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Invalid arguments!\nUsage: ./beautify input_file output_file");
        exit(1);
    }
    beautify(argv[1], argv[2]);
    printf("The beautification process is complete!");
    return 0;
}

void beautify(char *input_file, char *output_file)
{
    FILE *input_fp, *output_fp;
    input_fp = fopen(input_file, "r");
    if(input_fp == NULL)
    {
        printf("Error opening input file!");
        exit(1);
    }
    output_fp = fopen(output_file, "w");
    if(output_fp == NULL)
    {
        printf("Error opening output file!");
        exit(1);
    }
    char ch, prev_ch = '\0', prev_space = 0, prev_line = 0, prev_comment_start = 0, prev_comment_end = 0, comment_flag = 0, quote_flag = 0, escape_flag = 0;
    while((ch = fgetc(input_fp)) != EOF)
    {
        if(ch == '"')
        {
            if(!escape_flag)
            {
                quote_flag ^= 1; //toggle the flag when the double quotes are not in an escape sequence
            }
        }
        if(!quote_flag) //if we're not in a string literal
        {
            //check for block comment
            if(prev_ch == '/' && ch == '*')
            {
                prev_comment_start = 1;
                comment_flag = 1;
                fprintf(output_fp, "/%c", ch);
                prev_ch == '\0';
            }
            //check for line comment
            else if(prev_ch == '/' && ch == '/')
            {
                prev_comment_start = 1;
                comment_flag = 2;
                fprintf(output_fp, "/%c", ch);
                prev_ch == '\0';
            }
            //check for comment end
            else if(prev_ch == '*' && ch == '/')
            {
                prev_comment_end = 1;
                comment_flag = 0;
                fprintf(output_fp, "%c%c", ch, fgetc(input_fp));
            }
            //check for newline character
            else if(ch == '\n')
            {
                prev_line = 1;
                fprintf(output_fp, "%c", ch);
            }
            //check for spaces and ignore excessive spaces
            else if(prev_space == 0 && isspace(ch)) 
            {
                fprintf(output_fp, " ");
                prev_space = 1;
            }
            //check for keywords, loop constructs, and data types and format them
            else if(isalnum(ch) || ch == '_')
            {
                fprintf(output_fp, "%c", ch);
                prev_space = 0;
            }
            //all other characters will be printed as is
            else
            {
                fprintf(output_fp, "%c", ch);
                prev_space = 0;
            }
        }
        //escape flag is reset after every character read
        if(ch == '\\')
        {
            escape_flag ^= 1;
        }
        else
        {
            escape_flag = 0;
        }
        if(comment_flag == 2)
        {
            prev_line = 1;
        }
        if(prev_comment_start && !prev_comment_end) //ignores all beautification rules when in a comment
        {
            fprintf(output_fp, "%c", ch);
        }
        prev_ch = ch;
        prev_comment_start = 0;
        prev_comment_end = 0;
    }
    fclose(input_fp);
    fclose(output_fp);
}