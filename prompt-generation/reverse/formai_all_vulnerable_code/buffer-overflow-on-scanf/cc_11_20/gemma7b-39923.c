//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *name = malloc(20);
    printf("Enter your name: ");
    scanf("%s", name);

    int num = rand() % 10;
    char fortune[20];

    switch (num)
    {
        case 0:
            fortune[0] = 'A';
            fortune[1] = 'B';
            fortune[2] = 'C';
            break;
        case 1:
            fortune[0] = 'D';
            fortune[1] = 'E';
            fortune[2] = 'F';
            break;
        case 2:
            fortune[0] = 'G';
            fortune[1] = 'H';
            fortune[2] = 'I';
            break;
        case 3:
            fortune[0] = 'J';
            fortune[1] = 'K';
            fortune[2] = 'L';
            break;
        case 4:
            fortune[0] = 'M';
            fortune[1] = 'N';
            fortune[2] = 'O';
            break;
        case 5:
            fortune[0] = 'P';
            fortune[1] = 'Q';
            fortune[2] = 'R';
            break;
        case 6:
            fortune[0] = 'S';
            fortune[1] = 'T';
            fortune[2] = 'U';
            break;
        case 7:
            fortune[0] = 'V';
            fortune[1] = 'W';
            fortune[2] = 'X';
            break;
        case 8:
            fortune[0] = 'Y';
            fortune[1] = 'Z';
            fortune[2] = 'A';
            break;
        case 9:
            fortune[0] = 'B';
            fortune[1] = 'C';
            fortune[2] = 'D';
            break;
    }

    printf("Your fortune is: %s", fortune);

    free(name);

    return 0;
}