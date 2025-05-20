//FormAI DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>

int main(){
    int choice1, choice2, input;
    float result;

    printf("Welcome to the C Unit Converter\n");

    printf("\nChoose the unit you want to convert from:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n\n");
    printf("Enter choice: ");
    scanf("%d",&choice1);

    printf("\nChoose the unit you want to convert to:\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n\n");
    printf("Enter choice: ");
    scanf("%d",&choice2);

    printf("\nEnter the temperature to be converted: ");
    scanf("%d",&input);

    if(choice1 == 1 && choice2 == 2){ // Celsius to Fahrenheit
        result = (input * 9/5) + 32;
        printf("\n%d Celsius = %.2f Fahrenheit\n",input,result);
    }
    else if(choice1 == 2 && choice2 == 1){ // Fahrenheit to Celsius
        result = (input - 32) * 5/9;
        printf("\n%d Fahrenheit = %.2f Celsius\n",input,result);
    }
    else if(choice1 == 1 && choice2 == 3){ // Celsius to Kelvin
        result = input + 273.15;
        printf("\n%d Celsius = %.2f Kelvin\n",input,result);
    }
    else if(choice1 == 3 && choice2 == 1){ // Kelvin to Celsius
        result = input - 273.15;
        printf("\n%d Kelvin = %.2f Celsius\n",input,result);
    }
    else if(choice1 == 2 && choice2 == 3){ // Fahrenheit to Kelvin
        result = (input + 459.67) / 1.8;
        printf("\n%d Fahrenheit = %.2f Kelvin\n",input,result);
    }
    else if(choice1 == 3 && choice2 == 2){ // Kelvin to Fahrenheit
        result = input * 1.8 - 459.67;
        printf("\n%d Kelvin = %.2f Fahrenheit\n",input,result);
    }
    else if(choice1 == choice2){ // if both are same
        printf("\nThe temperature is same in both units!\n");
    }
    else{ // if invalid choice
        printf("\nInvalid choice!\n");
    }

    printf("\nThank you for using C Unit Converter\n");

    return 0;
}