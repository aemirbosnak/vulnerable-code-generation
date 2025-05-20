//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char text[100];
    int i, j, k, l, n;

    printf("Enter text: ");
    gets(text);

    n = strlen(text);
    l = n + 1;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (text[j] != '\0')
            {
                switch (text[j])
                {
                    case 'a':
                        printf("%c ", 97 + i);
                        break;
                    case 'b':
                        printf("%c ", 97 + i);
                        break;
                    case 'c':
                        printf("%c ", 97 + i);
                        break;
                    case 'd':
                        printf("%c ", 97 + i);
                        break;
                    case 'e':
                        printf("%c ", 97 + i);
                        break;
                    case 'f':
                        printf("%c ", 97 + i);
                        break;
                    case 'g':
                        printf("%c ", 97 + i);
                        break;
                    case 'h':
                        printf("%c ", 97 + i);
                        break;
                    case 'i':
                        printf("%c ", 97 + i);
                        break;
                    case 'j':
                        printf("%c ", 97 + i);
                        break;
                    case 'k':
                        printf("%c ", 97 + i);
                        break;
                    case 'l':
                        printf("%c ", 97 + i);
                        break;
                    case 'm':
                        printf("%c ", 97 + i);
                        break;
                    case 'n':
                        printf("%c ", 97 + i);
                        break;
                    case 'o':
                        printf("%c ", 97 + i);
                        break;
                    case 'p':
                        printf("%c ", 97 + i);
                        break;
                    case 'q':
                        printf("%c ", 97 + i);
                        break;
                    case 'r':
                        printf("%c ", 97 + i);
                        break;
                    case 's':
                        printf("%c ", 97 + i);
                        break;
                    case 't':
                        printf("%c ", 97 + i);
                        break;
                    case 'u':
                        printf("%c ", 97 + i);
                        break;
                    case 'v':
                        printf("%c ", 97 + i);
                        break;
                    case 'w':
                        printf("%c ", 97 + i);
                        break;
                    case 'x':
                        printf("%c ", 97 + i);
                        break;
                    case 'y':
                        printf("%c ", 97 + i);
                        break;
                    case 'z':
                        printf("%c ", 97 + i);
                        break;
                    default:
                        printf("%c ", 32);
                        break;
                }
            }
        }

        printf("\n");
    }

    return 0;
}