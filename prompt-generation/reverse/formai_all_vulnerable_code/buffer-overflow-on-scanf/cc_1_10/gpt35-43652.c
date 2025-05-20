//FormAI DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>

/* Function prototypes */
float convertFtoC(float temp);
float convertCtoF(float temp);
float convertMtoKm(float dist);
float convertKmtoM(float dist);

/* Main function */
int main(void)
{
    int choice;
    float input, output;
    
    printf("Select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Miles to Kilometers\n");
    printf("4. Convert Kilometers to Miles\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &input);
            output = convertFtoC(input);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", input, output);
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &input);
            output = convertCtoF(input);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", input, output);
            break;
        case 3:
            printf("Enter the distance in miles: ");
            scanf("%f", &input);
            output = convertMtoKm(input);
            printf("%.2f miles is equal to %.2f kilometers.", input, output);
            break;
        case 4:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &input);
            output = convertKmtoM(input);
            printf("%.2f kilometers is equal to %.2f miles.", input, output);
            break;
        default:
            printf("Invalid choice.");
    }
    
    return 0;
}

/* Function to convert Fahrenheit to Celsius */
float convertFtoC(float temp)
{
    return (temp - 32) * 5.0 / 9.0;
}

/* Function to convert Celsius to Fahrenheit */
float convertCtoF(float temp)
{
    return temp * 9.0 / 5.0 + 32;
}

/* Function to convert Miles to Kilometers */
float convertMtoKm(float dist)
{
    return dist * 1.60934;
}

/* Function to convert Kilometers to Miles */
float convertKmtoM(float dist)
{
    return dist / 1.60934;
}