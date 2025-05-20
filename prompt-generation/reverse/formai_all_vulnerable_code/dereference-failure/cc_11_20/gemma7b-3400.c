//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <string.h>

char *morse_code(char **str)
{
    char *p = *str;
    char *q = NULL;
    int i = 0;

    *str = malloc(strlen(*str) * 3);

    for (; i < strlen(*str); i++)
    {
        switch (p[i])
        {
            case 'a':
                q = strcat(str, "-..");
                break;
            case 'b':
                q = strcat(str, "-...");
                break;
            case 'c':
                q = strcat(str, "-.");
                break;
            case 'd':
                q = strcat(str, ".");
                break;
            case 'e':
                q = strcat(str, "..");
                break;
            case 'f':
                q = strcat(str, "...");
                break;
            case 'g':
                q = strcat(str, "--");
                break;
            case 'h':
                q = strcat(str, "....");
                break;
            case 'i':
                q = strcat(str, "..--");
                break;
            case 'j':
                q = strcat(str, ".---");
                break;
            case 'k':
                q = strcat(str, "-..");
                break;
            case 'l':
                q = strcat(str, ".-..");
                break;
            case 'm':
                q = strcat(str, "--");
                break;
            case 'n':
                q = strcat(str, "-.");
                break;
            case 'o':
                q = strcat(str, "---");
                break;
            case 'p':
                q = strcat(str, ".---");
                break;
            case 'q':
                q = strcat(str, "--..");
                break;
            case 'r':
                q = strcat(str, ".-");
                break;
            case 's':
                q = strcat(str, "...");
                break;
            case 't':
                q = strcat(str, "-");
                break;
            case 'u':
                q = strcat(str, ".");
                break;
            case 'v':
                q = strcat(str, "...");
                break;
            case 'w':
                q = strcat(str, ".--");
                break;
            case 'x':
                q = strcat(str, "-..");
                break;
            case 'y':
                q = strcat(str, "--.");
                break;
            case 'z':
                q = strcat(str, "---");
                break;
            default:
                break;
        }

        if (q)
            *str = realloc(*str, strlen(*str) + 1);
    }

    return *str;
}

int main()
{
    char *str = "HELLO WORLD";
    char *p = morse_code(&str);
    printf("%s", p);

    return 0;
}