//FormAI DATASET v1.0 Category: Unit converter ; Style: imaginative
#include<stdio.h>

//Function prototypes
float convertFtoC(float fahrenheit);
float convertCtoF(float celsius);
float convertKtoC(float kelvin);
float convertCtoK(float celsius);
float convertFtoK(float fahrenheit);
float convertKtoF(float kelvin);

//Main function
int main()
{
    float temp;
    int option;

    //Menu driven program
    do
    {
        printf("\n********** UNIT CONVERTER **********\n");
        printf("\n1. Fahrenheit to Celsius");
        printf("\n2. Celsius to Fahrenheit");
        printf("\n3. Kelvin to Celsius");
        printf("\n4. Celsius to Kelvin");
        printf("\n5. Fahrenheit to Kelvin");
        printf("\n6. Kelvin to Fahrenheit");
        printf("\n7. Exit");
        
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                printf("%.2f F = %.2f C\n", temp, convertFtoC(temp));
                break;
                
            case 2:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temp);
                printf("%.2f C = %.2f F\n", temp, convertCtoF(temp));
                break;

            case 3:
                printf("\nEnter temperature in Kelvin: ");
                scanf("%f", &temp);
                printf("%.2f K = %.2f C\n", temp, convertKtoC(temp));
                break;

            case 4:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temp);
                printf("%.2f C = %.2f K\n", temp, convertCtoK(temp));
                break;

            case 5:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                printf("%.2f F = %.2f K\n", temp, convertFtoK(temp));
                break;

            case 6:
                printf("\nEnter temperature in Kelvin: ");
                scanf("%f", &temp);
                printf("%.2f K = %.2f F\n", temp, convertKtoF(temp));
                break;

            case 7:
                printf("\nThank you for using the program!\n");
                break;

            default:
                printf("\nInvalid option selected. Please try again.\n");                
        }

    }while(option != 7);

    return 0;
}

//Function to convert Fahrenheit to Celsius
float convertFtoC(float fahrenheit)
{
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

//Function to convert Celsius to Fahrenheit
float convertCtoF(float celsius)
{
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

//Function to convert Kelvin to Celsius
float convertKtoC(float kelvin)
{
    float celsius = kelvin - 273.15;
    return celsius;
}

//Function to convert Celsius to Kelvin
float convertCtoK(float celsius)
{
    float kelvin = celsius + 273.15;
    return kelvin;
}

//Function to convert Fahrenheit to Kelvin
float convertFtoK(float fahrenheit)
{
    float kelvin = (fahrenheit + 459.67) * 5/9;
    return kelvin;
}

//Function to convert Kelvin to Fahrenheit
float convertKtoF(float kelvin)
{
    float fahrenheit = kelvin * 9/5 - 459.67;
    return fahrenheit;
}