//FormAI DATASET v1.0 Category: Unit converter ; Style: Cryptic
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50
#define MAX_OUTPUT_LENGTH 100

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius){
    return (celsius * 9/5) + 32;
}

// Function to convert Fahrenheit to Celsius
double fahrenheit_to_celsius(double fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

// Function to convert Kilometer to Miles
double kilometer_to_miles(double km){
    return km / 1.609344;
}

// Function to convert Miles to Kilometer
double miles_to_kilometer(double miles){
    return miles * 1.609344;
}

// Function to convert meters to feet
double meters_to_feet(double meters){
    return meters * 3.28084;
}

// Function to convert feet to meters
double feet_to_meters(double feet){
    return feet / 3.28084;
}

int main(){
    char input_unit[MAX_INPUT_LENGTH];
    char output_unit[MAX_INPUT_LENGTH];
    double input_value;
    double output_value;

    printf("Welcome to the Cryptic C Unit Converter!\n");

    while(1){
        printf("Enter the input unit (e.g. Celsius, Kilometer, Feet): ");
        scanf("%s", input_unit);

        printf("Enter the input value: ");
        scanf("%lf", &input_value);

        printf("Enter the output unit (e.g. Fahrenheit, Miles, Meters): ");
        scanf("%s", output_unit);

        // Convert input unit to lowercase for easier comparison
        for(int i=0; i<strlen(input_unit); i++){
            input_unit[i] = tolower(input_unit[i]);
        }

        // Convert output unit to lowercase for easier comparison
        for(int i=0; i<strlen(output_unit); i++){
            output_unit[i] = tolower(output_unit[i]);
        }
        
        // Check input and output units and perform appropriate conversion 
        if(strcmp(input_unit, "celsius") == 0 && strcmp(output_unit, "fahrenheit") == 0){
            output_value = celsius_to_fahrenheit(input_value);
        }
        else if(strcmp(input_unit, "fahrenheit") == 0 && strcmp(output_unit, "celsius") == 0){
            output_value = fahrenheit_to_celsius(input_value);
        }
        else if(strcmp(input_unit, "kilometer") == 0 && strcmp(output_unit, "miles") == 0){
            output_value = kilometer_to_miles(input_value);
        }
        else if(strcmp(input_unit, "miles") == 0 && strcmp(output_unit, "kilometer") == 0){
            output_value = miles_to_kilometer(input_value);
        }
        else if(strcmp(input_unit, "meters") == 0 && strcmp(output_unit, "feet") == 0){
            output_value = meters_to_feet(input_value);
        }
        else if(strcmp(input_unit, "feet") == 0 && strcmp(output_unit, "meters") == 0){
            output_value = feet_to_meters(input_value);
        }
        else{
            printf("Invalid input or output unit. Please try again.\n");
            continue;
        }

        // Format and print output
        char output_string[MAX_OUTPUT_LENGTH];
        sprintf(output_string, "%g %s is equal to %g %s", input_value, input_unit, output_value, output_unit);
        printf("%s\n", output_string);

        // Ask user if they want to convert again
        char answer[MAX_INPUT_LENGTH];
        printf("Do you want to convert again? (y/n): ");
        scanf("%s", answer);
        if(strcmp(answer, "y") != 0 && strcmp(answer, "Y") != 0){
            break;
        }
    }
    return 0;
}