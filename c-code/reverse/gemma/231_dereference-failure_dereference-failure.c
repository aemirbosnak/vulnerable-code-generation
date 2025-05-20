#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char **elements = NULL;
    int i = 0, n = 0;

    fp = fopen("elements.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }

    elements = malloc(n * sizeof(char *));
    if (elements == NULL)
    {
        return 1;
    }

    while (fscanf(fp, "%s", elements[n]) != EOF)
    {
        n++;
    }

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        printf("What is the name of the element with symbol %s?\n", elements[i]);
        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, elements[i]) == 0)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect. The answer is %s.\n", elements[i]);
        }
    }

    free(elements);

    return 0;
}
