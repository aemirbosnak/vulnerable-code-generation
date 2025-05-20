//FormAI DATASET v1.0 Category: Unit converter ; Style: light-weight
#include <stdio.h>

int main() {
    double inputValue;
    int inputUnit, outputUnit;
    double outputValue;
    
    // Displaying Conversion Options
    printf("C unit converter\n");
    printf("Select input unit: \n");
    printf("\t1. Celsius\n");
    printf("\t2. Fahrenheit\n");
    printf("\t3. Kelvin\n");
    
    // Taking input unit option from user
    printf("Enter option: ");
    scanf("%d",&inputUnit);
    
    // Validating input unit option
    if(inputUnit < 1 || inputUnit > 3) {
        printf("Invalid input unit option!");
        return 0;
    }
    
    // Displaying Output Unit Options
    printf("Select output unit: \n");
    printf("\t1. Celsius\n");
    printf("\t2. Fahrenheit\n");
    printf("\t3. Kelvin\n");
    
    // Taking output unit option from user
    printf("Enter option: ");
    scanf("%d",&outputUnit);
    
    // Validating output unit option
    if(outputUnit < 1 || outputUnit > 3) {
        printf("Invalid output unit option!");
        return 0;
    }
    
    // Taking input value from user
    printf("Enter value to convert: ");
    scanf("%lf",&inputValue);
    
    // Converting input value to output value
    if(inputUnit == 1) {  // Celsius
        if(outputUnit == 1) {  // to Celsius
            outputValue = inputValue;
        } else if(outputUnit == 2) {  // to Fahrenheit
            outputValue = (inputValue * 9/5) + 32;
        } else {  // to Kelvin
            outputValue = inputValue + 273.15;
        }
    } else if(inputUnit == 2) {  // Fahrenheit
        if(outputUnit == 1) {  // to Celsius
            outputValue = (inputValue - 32) * 5/9;
        } else if(outputUnit == 2) {  // to Fahrenheit
            outputValue = inputValue;
        } else {  // to Kelvin
            outputValue = (inputValue + 459.67) * 5/9;
        }
    } else {  // Kelvin
        if(outputUnit == 1) {  // to Celsius
            outputValue = inputValue - 273.15;
        } else if(outputUnit == 2) {  // to Fahrenheit
            outputValue = (inputValue * 9/5) - 459.67;
        } else {  // to Kelvin
            outputValue = inputValue;
        }
    }
    
    // Displaying Converted Value
    if(outputUnit == 1) {  // to Celsius
        printf("%.2lf C\n", outputValue);
    } else if(outputUnit == 2) {  // to Fahrenheit
        printf("%.2lf F\n", outputValue);
    } else {  // to Kelvin
        printf("%.2lf K\n", outputValue);
    }
    
    return 0;
}