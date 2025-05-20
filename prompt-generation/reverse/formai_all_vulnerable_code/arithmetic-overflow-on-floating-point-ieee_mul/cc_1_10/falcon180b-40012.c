//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    float value,result;
    char unit[10];

    printf("Welcome to the Cheerful Unit Converter!\n");
    printf("Please enter the value you want to convert: ");
    scanf("%f",&value);

    printf("Please enter the unit of the value: ");
    scanf("%s",unit);

    printf("Please select the unit you want to convert to:\n");
    printf("1. Meters\n");
    printf("2. Kilometers\n");
    printf("3. Centimeters\n");
    printf("4. Millimeters\n");
    printf("5. Inches\n");
    printf("6. Feet\n");
    printf("7. Yards\n");
    printf("8. Miles\n");

    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            result = value*100;
            printf("The value %.2f %s is equal to %.2f meters.\n",value,unit,result);
            break;

        case 2:
            result = value/1000;
            printf("The value %.2f %s is equal to %.2f kilometers.\n",value,unit,result);
            break;

        case 3:
            result = value*10;
            printf("The value %.2f %s is equal to %.2f centimeters.\n",value,unit,result);
            break;

        case 4:
            result = value*100;
            printf("The value %.2f %s is equal to %.2f millimeters.\n",value,unit,result);
            break;

        case 5:
            result = value*2.54;
            printf("The value %.2f %s is equal to %.2f inches.\n",value,unit,result);
            break;

        case 6:
            result = value*2.54*12;
            printf("The value %.2f %s is equal to %.2f feet.\n",value,unit,result);
            break;

        case 7:
            result = value*2.54*36;
            printf("The value %.2f %s is equal to %.2f yards.\n",value,unit,result);
            break;

        case 8:
            result = value*1609.34;
            printf("The value %.2f %s is equal to %.2f miles.\n",value,unit,result);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }

    return 0;
}