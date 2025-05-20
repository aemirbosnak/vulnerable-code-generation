//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html_code)
{
    int i, j, k, indent = 0, found_tag = 0;
    char temp[1024];

    for (i = 0; html_code[i] != '\0'; i++)
    {
        switch (html_code[i])
        {
            case '<':
                found_tag = 1;
                break;
            case ' ':
                if (found_tag)
                {
                    for (j = i - 1; html_code[j] != '<'; j--)
                    {
                        temp[k] = html_code[j];
                        k++;
                    }
                    temp[k] = '\n';
                    k++;
                    indent++;
                }
                break;
            default:
                temp[k] = html_code[i];
                k++;
                break;
        }
    }

    temp[k] = '\0';
    strcpy(html_code, temp);
    indent = 0;
}

int main()
{
    char html_code[] = "<div><b>This is a sample HTML code.</b></div>";

    beautify_html(html_code);

    printf("%s", html_code);

    return 0;
}