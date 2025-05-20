//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include<stdio.h>

int main()
{
    int choice;
    float temp_in_c, temp_in_f, temp_in_k, converted_temp;
    printf("Enter 1 for Celsius to Fahrenheit conversion\nEnter 2 for Celsius to Kelvin conversion\nEnter 3 for Fahrenheit to Celsius conversion\nEnter 4 for Fahrenheit to Kelvin conversion\nEnter 5 for Kelvin to Celsius conversion\nEnter 6 for Kelvin to Fahrenheit conversion\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&temp_in_c);
            converted_temp = temp_in_c*(9.0/5.0)+32;
            printf("%.2f C is %.2f F",temp_in_c,converted_temp);
            break;

        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&temp_in_c);
            converted_temp = temp_in_c + 273.15;
            printf("%.2f C is %.2f K",temp_in_c,converted_temp);
            break;

        case 3:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&temp_in_f);
            converted_temp = (temp_in_f-32)*(5.0/9.0);
            printf("%.2f F is %.2f C",temp_in_f,converted_temp);
            break;

        case 4:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&temp_in_f);
            converted_temp = (temp_in_f-32)*(5.0/9.0) + 273.15;
            printf("%.2f F is %.2f K",temp_in_f,converted_temp);
            break;

        case 5:
            printf("Enter temperature in Kelvin: ");
            scanf("%f",&temp_in_k);
            converted_temp = temp_in_k - 273.15;
            printf("%.2f K is %.2f C",temp_in_k,converted_temp);
            break;

        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f",&temp_in_k);
            converted_temp = (temp_in_k - 273.15)*(9.0/5.0) + 32;
            printf("%.2f K is %.2f F",temp_in_k,converted_temp);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}