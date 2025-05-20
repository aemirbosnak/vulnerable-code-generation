//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void translate_string(char *str)
{
    char *p = str;
    char *q = NULL;
    int i = 0;

    while (*p)
    {
        switch (*p)
        {
            case 'a':
                q = strcpy(q, "-..");
                break;
            case 'b':
                q = strcpy(q, "-");
                break;
            case 'c':
                q = strcpy(q, ".");
                break;
            case 'd':
                q = strcpy(q, "..");
                break;
            case 'e':
                q = strcpy(q, ".");
                break;
            case 'f':
                q = strcpy(q, "-..");
                break;
            case 'g':
                q = strcpy(q, "--");
                break;
            case 'h':
                q = strcpy(q, "....");
                break;
            case 'i':
                q = strcpy(q, "..");
                break;
            case 'j':
                q = strcpy(q, ".---");
                break;
            case 'k':
                q = strcpy(q, "-.");
                break;
            case 'l':
                q = strcpy(q, ".-");
                break;
            case 'm':
                q = strcpy(q, "--");
                break;
            case 'n':
                q = strcpy(q, "-");
                break;
            case 'o':
                q = strcpy(q, "---");
                break;
            case 'p':
                q = strcpy(q, ".--");
                break;
            case 'q':
                q = strcpy(q, "--.");
                break;
            case 'r':
                q = strcpy(q, ".-");
                break;
            case 's':
                q = strcpy(q, "...");
                break;
            case 't':
                q = strcpy(q, "-");
                break;
            case 'u':
                q = strcpy(q, "..-");
                break;
            case 'v':
                q = strcpy(q, "...");
                break;
            case 'w':
                q = strcpy(q, ".---");
                break;
            case 'x':
                q = strcpy(q, "-..");
                break;
            case 'y':
                q = strcpy(q, "--.");
                break;
            case 'z':
                q = strcpy(q, "---");
                break;
            default:
                q = strcpy(q, "");
                break;
        }

        if (q)
        {
            *p = '\0';
            p++;
            q = NULL;
            i++;
        }
    }

    printf("%s\n", str);
}

int main()
{
    translate_string("HELLO WORLD!");

    return 0;
}