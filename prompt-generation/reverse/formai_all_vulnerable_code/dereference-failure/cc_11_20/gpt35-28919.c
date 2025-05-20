//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

/* This program reads a text file, process the text and saves the modified text in a new file */

int main()
{
    FILE *fp, *fp_out;
    char line[MAX_LEN], c;
    int i, len, j;

    fp = fopen("input.txt", "r");  //opening the input file in read mode

    if(fp == NULL)   //if input file does not exist
    {
        printf("Error! File does not exist.");
        exit(1);
    }

    fp_out = fopen("output.txt", "w");  //creating a new output file in write mode

    if(fp_out == NULL)   //if output file cannot be created
    {
        printf("Error! Could not create output file.");
        exit(1);
    }

    while(!feof(fp))   //while not end of file
    {
        fgets(line, MAX_LEN, fp);   //reading each line of input file

        len = strlen(line);
        
        //removing the new line character '\n' from end of each line
        for(i=0; i<len; i++)
        {
            if(line[i] == '\n')
            {
                line[i] = ' ';    //replacing '\n' with a space ' '
                break;
            }
        }

        //modifying the text by removing word 'the' from each line
        for(i=0; i<len; i++)
        {
            if(line[i] == 't' && line[i+1] == 'h' && line[i+2] == 'e' && (line[i-1] == ' ' || i==0) && (line[i+3] == ' ' || i+3==len))
            {
                for(j=i+3; j<len; j++)
                {
                    line[j-3] = line[j];
                }
                len = strlen(line);
                line[len - 3] = '\0';   //removing the last 3 characters (word 'the')
            }
        }

        fputs(line, fp_out);   //writing the modified text to the output file
    }

    fclose(fp);   //closing the input file
    fclose(fp_out);   //closing the output file

    printf("Text processing completed successfully.");

    return 0;
}