//Gemma-7B DATASET v1.0 Category: Data mining ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void analyze_data(char **arr, int size)
{
    int i, j, count = 0, max_length = 0;
    char **word_arr = NULL;

    for (i = 0; i < size; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
            {
                count++;
            }
        }
    }

    word_arr = malloc(count * sizeof(char *));

    for (i = 0; i < count; i++)
    {
        word_arr[i] = malloc(MAX_SIZE);
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; arr[i][j] != '\0'; j++)
        {
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
            {
                strcpy(word_arr[count], &arr[i][j]);
                count++;
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        printf("%s\n", word_arr[i]);
    }

    free(word_arr);
}

int main()
{
    char **arr = NULL;
    int size = 0;

    printf("Enter the number of sentences: ");
    scanf("%d", &size);

    arr = malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++)
    {
        arr[i] = malloc(MAX_SIZE);
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter the sentence: ");
        scanf("%s", arr[i]);
    }

    analyze_data(arr, size);

    free(arr);

    return 0;
}