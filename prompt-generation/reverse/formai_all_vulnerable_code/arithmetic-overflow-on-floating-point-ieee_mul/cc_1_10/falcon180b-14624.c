//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define PI 3.14159265358979323846
#define R 8.3144598

int main(){
    char choice;
    double value,result;
    int choice_int;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter '1' for Celsius to Fahrenheit conversion.\n");
    printf("Enter '2' for Fahrenheit to Celsius conversion.\n");
    printf("Enter '3' for Kelvin to Celsius conversion.\n");
    printf("Enter '4' for Celsius to Kelvin conversion.\n");
    scanf("%c",&choice);

    switch(choice){
        case '1':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf",&value);
            result = (value*9/5)+32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n",value,result);
            break;
        case '2':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf",&value);
            result = (value-32)*5/9;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n",value,result);
            break;
        case '3':
            printf("Enter the temperature in Kelvin: ");
            scanf("%lf",&value);
            result = value-273.15;
            printf("%.2lf Kelvin is equal to %.2lf Celsius.\n",value,result);
            break;
        case '4':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf",&value);
            result = value+273.15;
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n",value,result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}