//FormAI DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include<stdio.h>

float celsius_to_fahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvin_to_fahrenheit(float kelvin){
    return (kelvin - 273.15) * 9/5 + 32;
}

int main(){
    int option;
    float value;
    printf("Welcome to Unit Converter\n\n");

    while(1){
        printf("\nChoose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Quit\n");
        printf("Option: ");

        scanf("%d", &option);

        if(option == 7){
            break;
        }else if(option >= 1 && option <= 6){
            printf("\nEnter the value: ");
            scanf("%f", &value);

            switch(option){
                case 1:
                    printf("%.2f Celsius = %.2f Fahrenheit\n", value, celsius_to_fahrenheit(value));
                    break;
                case 2:
                    printf("%.2f Fahrenheit = %.2f Celsius\n", value, fahrenheit_to_celsius(value));
                    break;
                case 3:
                    printf("%.2f Celsius = %.2f Kelvin\n", value, celsius_to_kelvin(value));
                    break;
                case 4:
                    printf("%.2f Kelvin = %.2f Celsius\n", value, kelvin_to_celsius(value));
                    break;
                case 5:
                    printf("%.2f Fahrenheit = %.2f Kelvin\n", value, fahrenheit_to_kelvin(value));
                    break;
                case 6:
                    printf("%.2f Kelvin = %.2f Fahrenheit\n", value, kelvin_to_fahrenheit(value));
                    break;
            }
        }else{
            printf("Invalid option selected. Select again\n");
        }
    }

    return 0;
}