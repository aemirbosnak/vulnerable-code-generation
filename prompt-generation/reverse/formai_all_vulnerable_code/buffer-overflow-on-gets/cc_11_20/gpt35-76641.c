//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int i, j, k;
    printf("Enter the sentence to translate in C Cat Language:\n");
    gets(input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            printf(" ");
        }
        else if (input[i] == 'C')
        {
            printf("Meow");
        }
        else if (input[i] == 'c')
        {
            printf("meow");
        }
        else if (input[i] == 't')
        {
            printf("purr");
        }
        else if (input[i] == 'T')
        {
            printf("Purr");
        }
        else if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
        {
            printf("m");
        }
        else if (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
        {
            printf("M");
        }
        else if (input[i] == '\n')
        {
            printf("\n");
        }
        else
        {
            printf("%c", input[i]);
        }
    }
    return 0;
}