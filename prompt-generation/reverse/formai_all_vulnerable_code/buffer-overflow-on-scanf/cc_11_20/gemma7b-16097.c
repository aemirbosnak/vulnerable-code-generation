//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'A':
                printf(".-.");
                break;
            case 'b':
            case 'B':
                printf("-..");
                break;
            case 'c':
            case 'C':
                printf("..-.");
                break;
            case 'd':
            case 'D':
                printf(".---");
                break;
            case 'e':
            case 'E':
                printf("---.");
                break;
            case 'f':
            case 'F':
                printf("-----");
                break;
            default:
                printf("Unknown character.");
                break;
        }
    }

    printf("\nYour ASCII art: \n");
    printf("%s\n", str);

    return 0;
}