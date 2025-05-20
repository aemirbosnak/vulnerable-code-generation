//FormAI DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include<stdio.h>

//Defining unit conversion functions
float celcius_to_fahrenheit(float celsius){
    return (celsius*9/5)+32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit-32)*5/9;
}

float miles_to_kilometers(float miles){
    return miles*1.60934;
}

float kilometers_to_miles(float kilometers){
    return kilometers/1.60934;
}

//Main function
int main(){
    int choice;
    float input, output;
    char* from_unit;
    char* to_unit;

    //Displaying menu for unit conversion types
    printf("Welcome to the unit converter!\n");
    printf("\nChoose the conversion you want to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Enter your choice (1/2/3/4): ");
    scanf("%d",&choice);

    //Taking user inputs
    printf("Enter the value you want to convert: ");
    scanf("%f",&input);

    //Performing selected unit conversion
    switch(choice){
        case 1:
            output = celcius_to_fahrenheit(input); //Calling function for Celsius to Fahrenheit converter
            from_unit = "Celsius";
            to_unit = "Fahrenheit";
            break;
        case 2:
            output = fahrenheit_to_celsius(input); //Calling function for Fahrenheit to Celsius converter
            from_unit = "Fahrenheit";
            to_unit = "Celsius";
            break;
        case 3:
            output = miles_to_kilometers(input); //Calling function for Miles to Kilometers converter
            from_unit = "Miles";
            to_unit = "Kilometers";
            break;
        case 4:
            output = kilometers_to_miles(input); //Calling function for Kilometers to Miles converter
            from_unit = "Kilometers";
            to_unit = "Miles";
            break;
        default:
            printf("Wrong choice! Try again."); //Displaying error message for invalid choice
            return 0;
    }

    //Displaying output
    printf("\n%.3f %s is equal to %.3f %s.",input,from_unit,output,to_unit);
    return 0;
}