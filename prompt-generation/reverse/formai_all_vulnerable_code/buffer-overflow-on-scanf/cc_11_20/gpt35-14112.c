//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include<stdio.h>
#include<string.h>

int main()
{
    char alien_string[100];
    printf("Enter the alien language code to translate: ");
    scanf("%s", alien_string);

    int length = strlen(alien_string);
    int i = 0, count = 0, current = 0, previous = 0;

    printf("Translated message: ");

    for(i = 0; i < length; i++)
    {
        current = alien_string[i] - '0';

        if(count == 0)
        {
            previous = current;
            count++;
            continue;
        }

        if(current == previous)
        {
            count++;
        }
        else
        {
            if(previous == 1)
            {
                printf("a");
            }
            else if(previous == 2)
            {
                printf("b");
            }
            else if(previous == 3)
            {
                printf("c");
            }
            else if(previous == 4)
            {
                printf("d");
            }
            else if(previous == 5)
            {
                printf("e");
            }

            previous = current;
            count = 1;
        }
    }

    if(previous == 1)
    {
        printf("a");
    }
    else if(previous == 2)
    {
        printf("b");
    }
    else if(previous == 3)
    {
        printf("c");
    }
    else if(previous == 4)
    {
        printf("d");
    }
    else if(previous == 5)
    {
        printf("e");
    }

    return 0;
}