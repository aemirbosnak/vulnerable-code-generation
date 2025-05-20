//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    float inch, feet, meter, cel, fahr, mile, km, pound, kg;

    printf("***Retro Style Unit Converter***\n\n");

    printf("Enter your choice:\n");
    printf("1. Inches to Feet\n");
    printf("2. Feet to Inches\n");
    printf("3. Meters to Feet\n");
    printf("4. Feet to Meters\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Fahrenheit to Celsius\n");
    printf("7. Miles to Kilometers\n");
    printf("8. Kilometers to Miles\n");
    printf("9. Pounds to Kilograms\n");
    printf("10. Kilograms to Pounds\n");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            printf("Enter the value in inches: ");
            scanf("%f",&inch);
            feet = inch/12.0;
            printf("%.2f inches is equal to %.2f feet.\n", inch, feet);
            break;

        case 2:
            printf("Enter the value in feet: ");
            scanf("%f",&feet);
            inch = feet*12.0;
            printf("%.2f feet is equal to %.2f inches.\n", feet, inch);
            break;

        case 3:
            printf("Enter the value in meters: ");
            scanf("%f",&meter);
            feet = meter/0.3048;
            printf("%.2f meters is equal to %.2f feet.\n", meter, feet);
            break;

        case 4:
            printf("Enter the value in feet: ");
            scanf("%f",&feet);
            meter = feet*0.3048;
            printf("%.2f feet is equal to %.2f meters.\n", feet, meter);
            break;

        case 5:
            printf("Enter the temperature in Celsius: ");
            scanf("%f",&cel);
            fahr = (cel*1.8)+32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", cel, fahr);
            break;

        case 6:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f",&fahr);
            cel = (fahr-32)/1.8;
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahr, cel);
            break;

        case 7:
            printf("Enter the value in miles: ");
            scanf("%f",&mile);
            km = mile*1.60934;
            printf("%.2f miles is equal to %.2f kilometers.\n", mile, km);
            break;

        case 8:
            printf("Enter the value in kilometers: ");
            scanf("%f",&km);
            mile = km/1.60934;
            printf("%.2f kilometers is equal to %.2f miles.\n", km, mile);
            break;

        case 9:
            printf("Enter the weight in pounds: ");
            scanf("%f",&pound);
            kg = pound*0.453592;
            printf("%.2f pounds is equal to %.2f kilograms.\n", pound, kg);
            break;

        case 10:
            printf("Enter the weight in kilograms: ");
            scanf("%f",&kg);
            pound = kg/0.453592;
            printf("%.2f kilograms is equal to %.2f pounds.\n", kg, pound);
            break;

        default:
            printf("Invalid choice! Try again.");
    }

    return 0;
}