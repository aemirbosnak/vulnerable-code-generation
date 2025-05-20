//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <string.h>

void beautify_html(char *html)
{
    int i, j, k, indent = 0;
    char line[1024];

    for (i = 0; html[i] != '\0'; i++)
    {
        switch (html[i])
        {
            case '<':
                indent = 0;
                break;
            case ' ':
                if (html[i-1] != '<')
                {
                    for (j = 0; j < indent; j++)
                    {
                        line[k++] = ' ';
                    }
                    line[k++] = ' ';
                }
                break;
            default:
                line[k++] = html[i];
                break;
        }

        if (line[k-1] == '\n')
        {
            indent++;
            for (j = 0; j < indent; j++)
            {
                line[k++] = ' ';
            }
        }
    }

    strcpy(html, line);
}

int main()
{
    char html[] = "<p><b>Hello, world!</b></p>\n<div>This is a div.</div>";

    beautify_html(html);

    printf("%s", html);

    return 0;
}