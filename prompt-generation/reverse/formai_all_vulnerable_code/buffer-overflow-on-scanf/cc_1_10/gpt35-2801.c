//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

//Function to convert Celsius to Fahrenheit
float convertCtoF(float celsius){
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

//Function to convert Fahrenheit to Celsius
float convertFtoC(float fahrenheit){
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

//Main function
int main(){
    char choice;
    float temp, convertedTemp;

    printf("Welcome to the temperature converter program!\n");
    printf("Please select which conversion you would like to make.\n");
    printf("Enter 'c' to convert Celsius to Fahrenheit.\n");
    printf("Enter 'f' to convert Fahrenheit to Celsius.\n");
    scanf("%c", &choice);

    switch(choice){
        case 'c':
            printf("You have selected Celsius to Fahrenheit conversion.\n");
            //Get temperature input in Celsius
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &temp);
            //Convert Celsius to Fahrenheit
            convertedTemp = convertCtoF(temp);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", temp, convertedTemp);
            break;
        case 'f':
            printf("You have selected Fahrenheit to Celsius conversion.\n");
            //Get temperature input in Fahrenheit
            printf("Please enter the temperature in Fahrenheit: ");
            scanf("%f", &temp);
            //Convert Fahrenheit to Celsius
            convertedTemp = convertFtoC(temp);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", temp, convertedTemp);
            break;
        default:
            printf("Invalid choice. Please select 'c' or 'f'.");
            break;
    }

    return 0;
}