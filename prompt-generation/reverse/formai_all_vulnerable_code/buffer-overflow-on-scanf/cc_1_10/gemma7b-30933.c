//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

void dance(int d)
{
    switch(d)
    {
        case 0:
            printf("C robot is dancing with style!\n");
            break;
        case 1:
            printf("C robot is doing a backflip!\n");
            break;
        case 2:
            printf("C robot is spinning like a top!\n");
            break;
        case 3:
            printf("C robot is doing a cartwheel!\n");
            break;
        case 4:
            printf("C robot is breaking dance moves!\n");
            break;
    }
}

int main()
{
    int n = 0;
    printf("Enter a number between 0 and 4: ");
    scanf("%d", &n);

    switch(n)
    {
        case 0:
            dance(0);
            break;
        case 1:
            dance(1);
            break;
        case 2:
            dance(2);
            break;
        case 3:
            dance(3);
            break;
        case 4:
            dance(4);
            break;
    }

    return 0;
}