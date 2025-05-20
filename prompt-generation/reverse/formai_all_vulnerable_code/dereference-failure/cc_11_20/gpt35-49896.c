//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include<stdio.h>

int main()
{
    char *html_code = "<html><head><title>My Page</title></head><body><h1>Welcome to my page</h1><p>This is my first website built using C</p></body></html>";

    char *new_html_code = "";
    int indent_level = 0;

    for(int i = 0; i < strlen(html_code); i++)
    {
        if(html_code[i] == '<')
        {
            if(html_code[i+1] == '/')
            {
                indent_level--;
            }

            for(int j = 0; j < indent_level; j++)
            {
                strcat(new_html_code, "\t");
            }

            if(html_code[i+1] != '/')
            {
                indent_level++;
            }
        }

        strncat(new_html_code, &html_code[i], 1);

        if(html_code[i] == '>')
        {
            strcat(new_html_code, "\n");
        }

        if(html_code[i] == '<' && html_code[i+1] == '/')
        {
            strcat(new_html_code, "\n");
        }

        if(html_code[i] == '<' && html_code[i+1] != '/')
        {
            strcat(new_html_code, "\n");
        }
    }

    printf("%s", new_html_code);

    return 0;
}