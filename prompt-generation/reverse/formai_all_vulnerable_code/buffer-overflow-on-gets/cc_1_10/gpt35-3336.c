//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//function to remove whitespace and comments from input string
void beautify(char source[], char result[])
{
    int slen = strlen(source);
    int rlen = 0;
  
    for(int i=0; i<slen; i++)
    {
        //if whitespace, skip
        if(source[i] == ' ' || source[i] == '\t' || source[i] == '\r' || source[i] == '\n')
        {
            continue;
        }
        
        //if start of single line comment, skip to next line
        if(source[i] == '/' && source[i+1] == '/')
        {
            while(source[i] != '\n')
            {
                i++;
            }
        }
        
        //if start of multi line comment, skip until end of comment
        if(source[i] == '/' && source[i+1] == '*')
        {
            while(source[i] != '*' || source[i+1] != '/')
            {
                i++;
            }
            i += 2;
        }
        
        //if start of tag, add proper formatting
        if(source[i] == '<')
        {
            if(source[i+1] == '/')
            {
                rlen--;
            }
            
            for(int j=0; j<rlen; j++)
            {
                result[i+j] = '\t';
            }
            
            rlen++;
            result[i+rlen-1] = source[i];
            
            if(source[i+1] != '/')
            {
                rlen++;
            }
            
            result[i+rlen-1] = '\n';
        }
        else if(source[i] == '>')
        {
            result[i] = source[i];
            result[i+1] = '\n';
            rlen--;
            for(int j=0; j<rlen; j++)
            {
                result[i+2+j] = '\t';
            }
            i++;
        }
        else
        {
            result[i+rlen] = source[i];
        }
    }
    result[slen+rlen] = '\0';
}
 
int main()
{
    char source[500], result[500];
 
    printf("Enter HTML code:\n");
    gets(source);
 
    beautify(source, result);
 
    printf("Beautified code:\n%s", result);
 
    return 0;
}