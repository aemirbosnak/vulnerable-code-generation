//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Shocked C Phone Book\n");
    printf("--------------------\n");
    printf("Dial a Number:\n");
    printf("Enter Phone Number: ");

    char number[10];
    scanf("%s", number);

    int i = 0;
    for (i = 0; number[i] != '\0'; i++)
    {
        switch (number[i])
        {
            case '0':
                printf("Beep beep beep!\n");
                break;
            case '1':
                printf("Ring ring ring!\n");
                break;
            case '2':
                printf("Click click click!\n");
                break;
            case '3':
                printf("Buzz buzz buzz!\n");
                break;
            case '4':
                printf("Ding ding ding!\n");
                break;
            case '5':
                printf("Tinkle tinkle tinkle!\n");
                break;
            case '6':
                printf("Click click click!\n");
                break;
            case '7':
                printf("Ring ring ring!\n");
                break;
            case '8':
                printf("Beep beep beep!\n");
                break;
            case '9':
                printf("Buzz buzz buzz!\n");
                break;
            default:
                printf("Invalid Number!\n");
                break;
        }
    }

    return 0;
}