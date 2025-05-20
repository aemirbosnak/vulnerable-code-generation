//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *str)
{
    char *compressed = (char *) malloc(sizeof(char) * strlen(str));

    int i = 0, j = 0, count = 1;

    while(str[i] != '\0')
    {
        if(str[i] == str[i+1])
        {
            count++;
        }
        else
        {
            compressed[j++] = str[i];
            compressed[j++] = count + '0';
            count = 1;
        }
        i++;
    }

    compressed[j] = '\0';

    if(strlen(compressed) < strlen(str))
    {
        printf("\nCompressed String: %s", compressed);
    }
    else
    {
        printf("\nOriginal String: %s", str);
    }
}

int main()
{
    char str[100];

    printf("Enter a string to compress: ");
    scanf("%s", str);

    printf("\nOriginal String: %s", str);

    compress(str);

    return 0;
}