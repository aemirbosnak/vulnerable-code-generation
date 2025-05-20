//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert_word(char **arr, int *size)
{
    char *new_arr = realloc(*arr, (*size) * 2);
    *arr = new_arr;
    (*size) *= 2;
    printf("Enter a word: ");
    scanf("%s", new_arr);
}

void search_word(char **arr, int size)
{
    char word[20];
    printf("Enter a word to search for: ");
    scanf("%s", word);
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (strcmp(arr[i], word) == 0)
        {
            printf("Word found: %s\n", arr[i]);
        }
    }
}

int main()
{
    char **arr = NULL;
    int size = 0;

    printf("Welcome to the Word Count Tool!\n");
    printf("Enter 'insert' to add a word, 'search' to search for a word, or 'exit' to exit: ");
    char command[20];
    scanf("%s", command);

    while (strcmp(command, "exit") != 0)
    {
        if (strcmp(command, "insert") == 0)
        {
            insert_word(arr, &size);
        }
        else if (strcmp(command, "search") == 0)
        {
            search_word(arr, size);
        }
        else
        {
            printf("Invalid command.\n");
        }

        printf("Enter 'insert' to add a word, 'search' to search for a word, or 'exit' to exit: ");
        scanf("%s", command);
    }

    printf("Thank you for using the Word Count Tool!\n");

    return 0;
}