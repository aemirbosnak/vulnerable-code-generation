//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include<stdio.h>

//function prototypes
void lengthConverter();
void temperatureConverter();
void weightConverter();

int main()
{
    int choice;
    printf("Welcome to the Unit Converter Program\n");
    printf("Please choose an option from the following:\n1.Length\n2.Temperature\n3.Weight\n4.Exit\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            lengthConverter();
            break;
           
        case 2:
            temperatureConverter();
            break;
            
        case 3:
            weightConverter();
            break;
        
        case 4:
            printf("Thank you for using the Unit Converter Program\n");
            break;
            
        default:
            printf("Invalid choice! Please try again\n");
            break;
    }
}

//functions for conversion of length units
void lengthConverter()
{
    float input, output;
    int fromUnit, toUnit;
    
    printf("Welcome to the Length Converter\nPlease enter the input value: ");
    scanf("%f", &input);
    printf("Please select the input unit:\n1.mm\n2.cm\n3.m\n4.inch\n");
    scanf("%d", &fromUnit);
    printf("Please select the output unit:\n1.mm\n2.cm\n3.m\n4.inch\n");
    scanf("%d", &toUnit);
    
    switch(fromUnit) //convert input to meter
    {
        case 1: //mm to meter
            input /= 1000;
            break;
        
        case 2: //cm to meter
            input /= 100;
            break;
        
        case 3: //already in meter
            break;
        
        case 4: //inch to meter
            input /= 39.3701;
            break;
        
        default:
            printf("Invalid input unit! Please try again\n");
            lengthConverter();
            return;
    }
    
    switch(toUnit) //convert meter to output
    {
        case 1: //meter to mm
            output = input * 1000;
            printf("%.2f m = %.2f mm\n", input, output);
            break;
            
        case 2: //meter to cm
            output = input * 100;
            printf("%.2f m = %.2f cm\n", input, output);
            break;
            
        case 3: //meter
            printf("%.2f m = %.2f m\n", input, input);
            break;
            
        case 4: //meter to inch
            output = input * 39.3701;
            printf("%.2f m = %.2f inch\n", input, output);
            break;
            
        default:
            printf("Invalid output unit! Please try again\n");
            lengthConverter();
            return;
    }
}

//functions for conversion of temperature units
void temperatureConverter()
{
    float input, output;
    int fromUnit, toUnit;
    
    printf("Welcome to the Temperature Converter\nPlease enter the input value: ");
    scanf("%f", &input);
    printf("Please select the input unit:\n1.Celsius\n2.Fahrenheit\n3.Kelvin\n");
    scanf("%d", &fromUnit);
    printf("Please select the output unit:\n1.Celsius\n2.Fahrenheit\n3.Kelvin\n");
    scanf("%d", &toUnit);
    
    switch(fromUnit) //convert input to Celsius
    {
        case 1: //already in Celsius
            break;
        
        case 2: //Fahrenheit to Celsius
            input = (input - 32) * 5/9;
            break;
        
        case 3: //Kelvin to Celsius
            input -= 273.15;
            break;
            
        default:
            printf("Invalid input unit! Please try again\n");
            temperatureConverter();
            return;
    }
    
    switch(toUnit) //convert Celsius to output
    {
        case 1: //Celsius
            printf("%.2f %cC = %.2f %cC\n", input, 248, input, 248);
            break;
            
        case 2: //Celsius to Fahrenheit
            output = input * 9/5 + 32;
            printf("%.2f %cC = %.2f %cF\n", input, 248, output, 248);
            break;
            
        case 3: //Celsius to Kelvin
            output = input + 273.15;
            printf("%.2f %cC = %.2f K\n", input, 248, output);
            break;
            
        default:
            printf("Invalid output unit! Please try again\n");
            temperatureConverter();
            return;
    }
}

//functions for conversion of weight units
void weightConverter()
{
    float input, output;
    int fromUnit, toUnit;
    
    printf("Welcome to the Weight Converter\nPlease enter the input value: ");
    scanf("%f", &input);
    printf("Please select the input unit:\n1.mg\n2.g\n3.kg\n4.lb\n");
    scanf("%d", &fromUnit);
    printf("Please select the output unit:\n1.mg\n2.g\n3.kg\n4.lb\n");
    scanf("%d", &toUnit);
    
    switch(fromUnit) //convert input to kg
    {
        case 1: //mg to kg
            input /= 1000000;
            break;
        
        case 2: //g to kg
            input /= 1000;
            break;
        
        case 3: //already in kg
            break;
        
        case 4: //lb to kg
            input /= 2.20462;
            break;
        
        default:
            printf("Invalid input unit! Please try again\n");
            weightConverter();
            return;
    }
    
    switch(toUnit) //convert kg to output
    {
        case 1: //kg to mg
            output = input * 1000000;
            printf("%.2f kg = %.2f mg\n", input, output);
            break;
            
        case 2: //kg to g
            output = input * 1000;
            printf("%.2f kg = %.2f g\n", input, output);
            break;
            
        case 3: //kg
            printf("%.2f kg = %.2f kg\n", input, input);
            break;
            
        case 4: //kg to lb
            output = input * 2.20462;
            printf("%.2f kg = %.2f lb\n", input, output);
            break;
            
        default:
            printf("Invalid output unit! Please try again\n");
            weightConverter();
            return;
    }
}