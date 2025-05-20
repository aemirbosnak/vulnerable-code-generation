//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<locale.h>
#include<time.h>

int main(){
    setlocale(LC_ALL, "");
    char ch;
    int choice;
    double num1, num2, result;
    char celsius[10] = "Celsius";
    char fahrenheit[10] = "Fahrenheit";
    char kelvin[10] = "Kelvin";

    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose a temperature scale:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("You have chosen Celsius.\n");
            printf("Please enter the temperature in Celsius:\n");
            scanf("%lf", &num1);
            result = (num1 * 9/5) + 32;
            printf("The temperature in Fahrenheit is: %.2lf\n", result);
            break;
        case 2:
            printf("You have chosen Fahrenheit.\n");
            printf("Please enter the temperature in Fahrenheit:\n");
            scanf("%lf", &num1);
            result = (num1 - 32) * 5/9;
            printf("The temperature in Celsius is: %.2lf\n", result);
            break;
        case 3:
            printf("You have chosen Kelvin.\n");
            printf("Please enter the temperature in Kelvin:\n");
            scanf("%lf", &num1);
            result = num1 - 273.15;
            printf("The temperature in Celsius is: %.2lf\n", result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    printf("Do you want to convert another temperature? (y/n)\n");
    scanf(" %c", &ch);

    if(tolower(ch) == 'y'){
        main();
    }else{
        printf("Thank you for using the Temperature Converter!\n");
        return 0;
    }
}