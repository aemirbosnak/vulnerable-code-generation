//Gemma-7B DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *morse_code(char **arr, int n)
{
    char *res = malloc(n * 4);
    for (int i = 0; i < n; i++)
    {
        switch (*arr[i])
        {
            case 'a':
                strcpy(res + i * 4, "-..---");
                break;
            case 'b':
                strcpy(res + i * 4, "-....");
                break;
            case 'c':
                strcpy(res + i * 4, "-..");
                break;
            case 'd':
                strcpy(res + i * 4, ".---");
                break;
            case 'e':
                strcpy(res + i * 4, ".");
                break;
            case 'f':
                strcpy(res + i * 4, "..---");
                break;
            case 'g':
                strcpy(res + i * 4, "--.");
                break;
            case 'h':
                strcpy(res + i * 4, "....");
                break;
            case 'i':
                strcpy(res + i * 4, "..");
                break;
            case 'j':
                strcpy(res + i * 4, ".---.");
                break;
            case 'k':
                strcpy(res + i * 4, "-..");
                break;
            case 'l':
                strcpy(res + i * 4, ".-..");
                break;
            case 'm':
                strcpy(res + i * 4, "--");
                break;
            case 'n':
                strcpy(res + i * 4, "-.");
                break;
            case 'o':
                strcpy(res + i * 4, "---");
                break;
            case 'p':
                strcpy(res + i * 4, ".--.");
                break;
            case 'q':
                strcpy(res + i * 4, "--..");
                break;
            case 'r':
                strcpy(res + i * 4, ".-.");
                break;
            case 's':
                strcpy(res + i * 4, "...");
                break;
            case 't':
                strcpy(res + i * 4, "-");
                break;
            case 'u':
                strcpy(res + i * 4, "..-");
                break;
            case 'v':
                strcpy(res + i * 4, "...-");
                break;
            case 'w':
                strcpy(res + i * 4, ".--");
                break;
            case 'x':
                strcpy(res + i * 4, "-..--");
                break;
            case 'y':
                strcpy(res + i * 4, "--..-"
);
            case 'z':
                strcpy(res + i * 4, "---.");
                break;
            default:
                strcpy(res + i * 4, "");
                break;
        }
    }
    return res;
}

int main()
{
    char **arr = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = malloc(20 * sizeof(char));
    }

    strcpy(arr[0], "HELLO WORLD");
    strcpy(arr[1], "HOW ARE YOU?");
    strcpy(arr[2], "I AM FINE");

    char *res = morse_code(arr, 3);

    printf("%s", res);

    free(res);
    for (int i = 0; i < 10; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}