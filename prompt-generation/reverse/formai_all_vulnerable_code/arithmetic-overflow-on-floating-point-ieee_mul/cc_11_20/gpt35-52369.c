//FormAI DATASET v1.0 Category: Unit converter ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //variable declaration
    float input_value;
    int input_unit, output_unit;
    float output_value;

    //display the list of available units for conversion
    printf("List of available units for conversion\n");
    printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n4. Meter\n5. Feet\n6. Inch\n");

    //get the input from the user
    printf("\nEnter the unit to be converted (1 to 6): ");
    scanf("%d",&input_unit);
    printf("Enter the value to be converted: ");
    scanf("%f",&input_value);
    printf("Enter the unit to be converted to (1 to 6): ");
    scanf("%d",&output_unit);

    //perform the conversion based on the input and output units
    switch(input_unit)
    {
        case 1: //Celsius
            if(output_unit == 2) //convert Celsius to Fahrenheit
            {
                output_value = (input_value * 9/5) + 32;
                printf("%.2f Celsius = %.2f Fahrenheit", input_value, output_value);
            }
            else if(output_unit == 3) //convert Celsius to Kelvin
            {
                output_value = input_value + 273.15;
                printf("%.2f Celsius = %.2f Kelvin", input_value, output_value);
            }
            else
            {
                printf("Invalid output unit!");
                exit(EXIT_FAILURE);
            }
            break;

        case 2: //Fahrenheit
            if(output_unit == 1) //convert Fahrenheit to Celsius
            {
                output_value = (input_value - 32) * 5/9;
                printf("%.2f Fahrenheit = %.2f Celsius", input_value, output_value);
            }
            else if(output_unit == 3) //convert Fahrenheit to Kelvin
            {
                output_value = (input_value - 32) * 5/9 + 273.15;
                printf("%.2f Fahrenheit = %.2f Kelvin", input_value, output_value);
            }
            else
            {
                printf("Invalid output unit!");
                exit(EXIT_FAILURE);
            }
            break;

        case 3: //Kelvin
            if(output_unit == 1) //convert Kelvin to Celsius
            {
                output_value = input_value - 273.15;
                printf("%.2f Kelvin = %.2f Celsius", input_value, output_value);
            }
            else if(output_unit == 2) //convert Kelvin to Fahrenheit
            {
                output_value = (input_value - 273.15) * 9/5 + 32;
                printf("%.2f Kelvin = %.2f Fahrenheit", input_value, output_value);
            }
            else
            {
                printf("Invalid output unit!");
                exit(EXIT_FAILURE);
            }
            break;

        case 4: //Meter
            if(output_unit == 5) //convert Meter to Feet
            {
                output_value = input_value * 3.281;
                printf("%.2f Meter = %.2f Feet", input_value, output_value);
            }
            else if(output_unit == 6) //convert Meter to Inch
            {
                output_value = input_value * 39.37;
                printf("%.2f Meter = %.2f Inch", input_value, output_value);
            }
            else
            {
                printf("Invalid output unit!");
                exit(EXIT_FAILURE);
            }
            break;

        case 5: //Feet
            if(output_unit == 4) //convert Feet to Meter
            {
                output_value = input_value / 3.281;
                printf("%.2f Feet = %.2f Meter", input_value, output_value);
            }
            else if(output_unit == 6) //convert Feet to Inch
            {
                output_value = input_value * 12;
                printf("%.2f Feet = %.2f Inch", input_value, output_value);
            }
            else
            {
                printf("Invalid output unit!");
                exit(EXIT_FAILURE);
            }
            break;

        case 6: //Inch
            if(output_unit == 4) //convert Inch to Meter
            {
                output_value = input_value / 39.37;
                printf("%.2f Inch = %.2f Meter", input_value, output_value);
            }
            else if(output_unit == 5) //convert Inch to Feet
            {
                output_value = input_value / 12;
                printf("%.2f Inch = %.2f Feet", input_value, output_value);
            }
            else
            {
                printf("Invalid output unit!");
                exit(EXIT_FAILURE);
            }
            break;

        default:
            printf("Invalid input unit!");
            exit(EXIT_FAILURE);
    }

    return 0;
}