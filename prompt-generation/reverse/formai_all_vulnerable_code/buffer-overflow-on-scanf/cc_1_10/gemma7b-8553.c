//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scramble(char **arr, int n);

int main()
{
    int n, i, j;
    char **arr;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    arr = (char **)malloc(n * sizeof(char *));

    for(i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter the student's name: ");
        scanf("%s", arr[i]);
    }

    scramble(arr, n);

    for(i = 0; i < n; i++)
    {
        printf("The scrambled student's name is: %s\n", arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}

void scramble(char **arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; arr[i][j] != '\0'; j++)
        {
            int r = rand() % n;
            char temp = arr[i][j];
            arr[i][j] = arr[r][j];
            arr[r][j] = temp;
        }
    }
}