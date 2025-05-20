//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>

int main()
{
    float fnum, tnum;
    int units, target_units;

    printf("Enter the number: ");
    scanf("%f", &fnum);

    printf("Enter the units: ");
    scanf("%d", &units);

    printf("Enter the target units: ");
    scanf("%d", &target_units);

    switch (units)
    {
        case 1:
            tnum = fnum * 1000;
            target_units = 2;
            break;
        case 2:
            tnum = fnum * 1000;
            target_units = 3;
            break;
        case 3:
            tnum = fnum * 1000;
            target_units = 4;
            break;
        case 4:
            tnum = fnum * 1000;
            target_units = 5;
            break;
        default:
            printf("Invalid units.\n");
            return 1;
    }

    switch (target_units)
    {
        case 1:
            tnum = tnum / 1000;
            printf("The converted number is: %.2f\n", tnum);
            break;
        case 2:
            tnum = tnum / 1000;
            printf("The converted number is: %.2f\n", tnum);
            break;
        case 3:
            tnum = tnum / 1000;
            printf("The converted number is: %.2f\n", tnum);
            break;
        case 4:
            tnum = tnum / 1000;
            printf("The converted number is: %.2f\n", tnum);
            break;
        case 5:
            tnum = tnum / 1000;
            printf("The converted number is: %.2f\n", tnum);
            break;
        default:
            printf("Invalid target units.\n");
            return 1;
    }

    return 0;
}