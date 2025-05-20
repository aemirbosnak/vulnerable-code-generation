//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char* html_code); 

int main()
{
    char html_code[1000];
    printf("Enter the HTML code:\n");
    scanf("%[^\n]s", html_code);
    beautify_html(html_code);
    printf("The beautified HTML code is:\n%s\n", html_code);
    return 0;
}

void beautify_html(char* html_code)
{
    int i, j;
    int indent_level = 0;
    int str_size = strlen(html_code);
    char temp[1000];
    memset(temp, 0, sizeof temp);
    for(i = 0, j = 0 ; i < str_size; i++, j++)
    {
        temp[j] = html_code[i];
        if(html_code[i] == '<')
        {
            if(html_code[i+1] == '/')
                indent_level--;
            if((html_code[i+1] >= 'a' && html_code[i+1] <= 'z') || (html_code[i+1] >= 'A' && html_code[i+1] <= 'Z'))
            {
                if(html_code[i-1] == '\n')
                {
                    temp[j] = '\0';
                    printf("%s", temp);
                    memset(temp, 0, sizeof temp);
                    for(int k = 0; k < indent_level; k++)
                    {
                        printf("    ");
                    }
                    j = -1;
                }
                indent_level++;
            }
        }
        if(html_code[i] == '\n')
        {
            temp[j] = '\0';
            printf("%s", temp);
            memset(temp, 0, sizeof temp);
            j = -1;
        }
    }
}