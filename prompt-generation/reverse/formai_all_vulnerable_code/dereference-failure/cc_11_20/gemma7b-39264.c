//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 255

void text_to_ascii(char **arr, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(arr[i]); j++)
        {
            switch (arr[i][j])
            {
                case 'a':
                    arr[i][j] = 97;
                    break;
                case 'b':
                    arr[i][j] = 98;
                    break;
                case 'c':
                    arr[i][j] = 99;
                    break;
                case 'd':
                    arr[i][j] = 100;
                    break;
                case 'e':
                    arr[i][j] = 101;
                    break;
                case 'f':
                    arr[i][j] = 102;
                    break;
                case 'g':
                    arr[i][j] = 103;
                    break;
                case 'h':
                    arr[i][j] = 104;
                    break;
                case 'i':
                    arr[i][j] = 105;
                    break;
                case 'j':
                    arr[i][j] = 106;
                    break;
                case 'k':
                    arr[i][j] = 107;
                    break;
                case 'l':
                    arr[i][j] = 108;
                    break;
                case 'm':
                    arr[i][j] = 109;
                    break;
                case 'n':
                    arr[i][j] = 110;
                    break;
                case 'o':
                    arr[i][j] = 111;
                    break;
                case 'p':
                    arr[i][j] = 112;
                    break;
                case 'q':
                    arr[i][j] = 113;
                    break;
                case 'r':
                    arr[i][j] = 114;
                    break;
                case 's':
                    arr[i][j] = 115;
                    break;
                case 't':
                    arr[i][j] = 116;
                    break;
                case 'u':
                    arr[i][j] = 117;
                    break;
                case 'v':
                    arr[i][j] = 118;
                    break;
                case 'w':
                    arr[i][j] = 119;
                    break;
                case 'x':
                    arr[i][j] = 120;
                    break;
                case 'y':
                    arr[i][j] = 121;
                    break;
                case 'z':
                    arr[i][j] = 122;
                    break;
                default:
                    arr[i][j] = 0;
            }
        }
    }

    for (k = 0; k < n; k++)
    {
        printf("%s\n", arr[k]);
    }
}

int main()
{
    char **arr;
    int n;

    printf("Enter the number of lines: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    text_to_ascii(arr, n);

    return 0;
}