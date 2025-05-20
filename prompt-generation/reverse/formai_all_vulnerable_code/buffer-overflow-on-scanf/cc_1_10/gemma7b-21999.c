//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void translate(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        switch (*arr[i])
        {
            case 'a':
                *arr[i] = 'A';
                break;
            case 'e':
                *arr[i] = 'E';
                break;
            case 'i':
                *arr[i] = 'I';
                break;
            case 'o':
                *arr[i] = 'O';
                break;
            case 'u':
                *arr[i] = 'U';
                break;
            default:
                break;
        }
    }
}

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    int size = 0;

    printf("Welcome to the C Cat Language Translator!\n");

    // Get the input text
    printf("Enter text: ");
    char str[MAX];
    scanf("%s", str);

    // Convert the text into an array of words
    char *word = strtok(str, " ");
    while (word)
    {
        arr[size++] = strdup(word);
        word = strtok(NULL, " ");
    }

    // Translate the words
    translate(arr, size);

    // Print the translated text
    printf("Translated text:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%s ", arr[i]);
    }

    free(arr);

    return 0;
}