//Gemma-7B DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[200];
    char query[200];
    int i, j, k, l, found = 0;
    FILE *fp;

    fp = fopen("sherlock.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter your query: ");
    scanf("%s", query);

    while (fgets(str, 200, fp) != NULL)
    {
        l = strlen(str);
        for (i = 0; i < l; i++)
        {
            for (j = 0; query[j] != '\0'; j++)
            {
                if (str[i] == query[j])
                {
                    found = 1;
                    break;
                }
            }
            if (found)
            {
                printf("Found: %s\n", str);
                break;
            }
        }
    }

    if (!found)
    {
        printf("No match found.\n");
    }

    fclose(fp);

    return 0;
}