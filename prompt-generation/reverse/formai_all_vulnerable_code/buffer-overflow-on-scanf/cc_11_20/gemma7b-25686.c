//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int num;
    char sign;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter a number between 1 and 10: ");
    scanf("%d", &num);

    srand(time(NULL));
    num = rand() % 11;

    switch (num)
    {
        case 0:
            sign = '+';
            break;
        case 1:
            sign = 'A';
            break;
        case 2:
            sign = 'B';
            break;
        case 3:
            sign = 'C';
            break;
        case 4:
            sign = 'D';
            break;
        case 5:
            sign = 'E';
            break;
        case 6:
            sign = 'F';
            break;
        case 7:
            sign = 'G';
            break;
        case 8:
            sign = 'H';
            break;
        case 9:
            sign = 'I';
            break;
        case 10:
            sign = 'J';
            break;
    }

    printf("Your fortune is: You will have %c%s in the future.", sign, name);

    return 0;
}