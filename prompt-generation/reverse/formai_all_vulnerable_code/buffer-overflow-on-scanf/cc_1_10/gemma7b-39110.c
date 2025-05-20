//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Dial a number:\n");

    char number[10];
    scanf("%s", number);

    int length = strlen(number);

    if (length != 3)
    {
        printf("Invalid number. Please try again.\n");
        exit(1);
    }

    int areaCode = number[0] - '0';
    int exchangeCode = number[1] - '0';
    int lineNumber = number[2] - '0';

    switch (areaCode)
    {
        case 5:
            printf("You are calling from New York.\n");
            break;
        case 4:
            printf("You are calling from Los Angeles.\n");
            break;
        case 3:
            printf("You are calling from Chicago.\n");
            break;
        default:
            printf("Invalid area code.\n");
    }

    switch (exchangeCode)
    {
        case 1:
            printf("You are calling to the first exchange.\n");
            break;
        case 2:
            printf("You are calling to the second exchange.\n");
            break;
        case 3:
            printf("You are calling to the third exchange.\n");
            break;
        default:
            printf("Invalid exchange code.\n");
    }

    printf("Your line number is %d.\n", lineNumber);

    return 0;
}