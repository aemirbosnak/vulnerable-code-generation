//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[10]; //initialize input string
    char unit[10]; //initialize unit string
    float value; //initialize value
    int choice; //initialize choice
    float conv_value; //initialize converted value
    char conv_unit[10]; //initialize converted unit string

    //initialize variables
    value = 0;
    choice = 0;
    conv_value = 0;

    //prompt user for input
    printf("Enter a temperature value followed by its unit (e.g. 100 F): ");
    scanf("%s %s", input, unit);

    //convert input to uppercase
    for(int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    //convert input to float
    value = atof(input);

    //prompt user for conversion choice
    printf("Enter 1 to convert from Fahrenheit to Celsius or 2 to convert from Celsius to Fahrenheit: ");
    scanf("%d", &choice);

    //convert temperature
    switch(choice) {
        case 1: //Fahrenheit to Celsius
            conv_value = (value - 32) * 5/9;
            strcpy(conv_unit, "C");
            break;
        case 2: //Celsius to Fahrenheit
            conv_value = (value * 9/5) + 32;
            strcpy(conv_unit, "F");
            break;
        default: //invalid choice
            printf("Invalid choice! Please enter 1 or 2.\n");
            return 0;
    }

    //display converted temperature
    printf("The converted temperature is %.2f %s.\n", conv_value, conv_unit);

    return 0;
}