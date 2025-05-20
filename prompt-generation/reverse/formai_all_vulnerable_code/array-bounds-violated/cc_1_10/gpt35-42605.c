//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog";
    int n = strlen(str), i, j;
    char inp[100], c;
    time_t start, end;
    double time_used;
    srand(time(0));

    for(i = 0; i < n; i++)
    {
        if(str[i] == ' ')
            printf(" ");
        else
        {
            j = rand() % 2;
            if(j == 0)
                printf("%c", tolower(str[i]));
            else
                printf("%c", toupper(str[i]));
        }
    }

    printf("\n\nType the above text here: \n\n");

    time(&start);
    fgets(inp, sizeof(inp), stdin);
    time(&end);

    if(inp[strlen(inp) - 1] == '\n')
        inp[strlen(inp) - 1] = '\0';

    printf("\nYou typed: %s\n", inp);

    time_used = difftime(end, start);

    printf("\nTime taken: %.2lf seconds\n", time_used);

    int len1 = strlen(str), len2 = strlen(inp), minlen = len1 > len2 ? len2 : len1;
    int errors = 0, accuracy = 0;

    for(i = 0; i < minlen; i++)
    {
        if(str[i] == inp[i])
            accuracy++;
        else
            errors++;
    }

    accuracy = (int) ((double)accuracy / (double)len1 * 100.0);
    errors = (int) ((double)errors / (double)len1 * 100.0);

    printf("\nAccuracy: %d%%\n", accuracy);
    printf("Errors: %d%%\n", errors);

    return 0;
}