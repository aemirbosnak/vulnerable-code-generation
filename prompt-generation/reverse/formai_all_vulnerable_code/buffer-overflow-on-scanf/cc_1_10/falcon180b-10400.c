//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    char unit[20],result_unit[20];
    float num,result;
    int choice;

    printf("Enter the unit to convert from: ");
    scanf("%s",unit);

    printf("Enter the value to be converted: ");
    scanf("%f",&num);

    printf("\nEnter the unit to convert to:\n");
    printf("1. Millimeters\n");
    printf("2. Centimeters\n");
    printf("3. Meters\n");
    printf("4. Kilometers\n");
    printf("5. Miles\n");
    printf("6. Yards\n");
    printf("7. Feet\n");
    printf("8. Inches\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            result = num*10.0;
            strcpy(result_unit,"mm");
            break;

        case 2:
            result = num*100.0;
            strcpy(result_unit,"cm");
            break;

        case 3:
            result = num*1000.0;
            strcpy(result_unit,"m");
            break;

        case 4:
            result = num*1000000.0;
            strcpy(result_unit,"km");
            break;

        case 5:
            result = num*160934.4;
            strcpy(result_unit,"mi");
            break;

        case 6:
            result = num*1093.61;
            strcpy(result_unit,"yd");
            break;

        case 7:
            result = num*3.281;
            strcpy(result_unit,"ft");
            break;

        case 8:
            result = num*2.54;
            strcpy(result_unit,"in");
            break;

        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\n%f %s = %f %s\n",num,unit,result,result_unit);

    return 0;
}