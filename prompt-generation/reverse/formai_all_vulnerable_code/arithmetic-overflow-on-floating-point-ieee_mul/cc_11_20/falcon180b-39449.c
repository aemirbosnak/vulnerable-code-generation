//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: authentic
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    double num,result;
    char unit[50];

    printf("Enter the unit you want to convert:\n");
    scanf("%s",unit);

    printf("Enter the value to be converted:\n");
    scanf("%lf",&num);

    printf("Enter the unit you want to convert to:\n");
    scanf("%s",unit);

    switch(unit[0])
    {
        case 'k':
        case 'K':
            result=num*1000;
            break;
        case 'h':
        case 'H':
            result=num*60;
            break;
        case 'd':
        case 'D':
            result=num*1440;
            break;
        case'm':
        case 'M':
            result=num*100;
            break;
        default:
            printf("Invalid unit\n");
            return 0;
    }

    switch(unit[strlen(unit)-1])
    {
        case 'k':
        case 'K':
            printf("%lf %c = %.2lf %c\n",num,unit[0],result,unit[0]);
            break;
        case 'h':
        case 'H':
            printf("%lf %c = %.2lf %c\n",num,unit[0],result,unit[0]);
            break;
        case 'd':
        case 'D':
            printf("%lf %c = %.2lf %c\n",num,unit[0],result,unit[0]);
            break;
        case'm':
        case 'M':
            printf("%lf %c = %.2lf %c\n",num,unit[0],result,unit[0]);
            break;
        default:
            printf("Invalid unit\n");
            return 0;
    }

    return 0;
}