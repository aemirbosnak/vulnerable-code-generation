//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char fileName[100], word[100], ch;
    int count = 0, i = 0, j = 0, isWord = 0;
    FILE *filePointer;

    printf("Enter file name: ");
    scanf("%s", fileName);

    filePointer = fopen(fileName, "r");

    if (filePointer == NULL)
    {
        printf("File not found.");
        return 0;
    }

    while ((ch = fgetc(filePointer)))
    {
        if (isalpha(ch))
        {
            isWord = 1;
            word[i] = ch;
            i++;
        }
        else
        {
            if (isWord)
            {
                word[i] = '\0';
                count++;
                printf("%s\n", word);
                isWord = 0;
                i = 0;
            }
        }

        if (ch == EOF)
        {
            break;
        }
    }
    fclose(filePointer);

    printf("\nWord count: %d\n", count);

    return 0;
}