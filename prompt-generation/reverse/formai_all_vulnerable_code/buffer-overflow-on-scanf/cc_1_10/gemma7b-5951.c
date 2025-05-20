//Gemma-7B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void check_palindrome(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                printf("The character %c is a palindrome\n", arr[i]);
            }
        }
    }
}

int main()
{
    char **arr = NULL;
    int size = 0;

    printf("Enter the number of characters you want to store: ");
    scanf("%d", &size);

    arr = (char **)malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    printf("Enter the characters you want to store: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%s", arr[i]);
    }

    check_palindrome(arr, size);

    for (int i = 0; i < size; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return 0;
}