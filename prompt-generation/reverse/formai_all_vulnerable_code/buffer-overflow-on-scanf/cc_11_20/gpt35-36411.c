//FormAI DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //declaring variables
    float temp[10];
    int i, numReadings;
    float tempAvg = 0.0;
    
    printf("Welcome to the Temperature Monitor!\n");
    printf("How many temperature readings would you like to take (1-10)?\n");
    scanf("%d", &numReadings);
    
    //validating user input
    while(numReadings > 10 || numReadings < 1)
    {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        scanf("%d", &numReadings);
    }
    
    //reading user input for temperature readings
    for(i = 0; i < numReadings; i++)
    {
        printf("Enter temperature reading in celsius for reading %d: ", i+1);
        scanf("%f", &temp[i]);
    }
    
    //calculating average temperature
    for(i = 0; i < numReadings; i++)
    {
        tempAvg += temp[i];
    }
    tempAvg = tempAvg / numReadings;

    //displaying temperature readings and average temperature to user
    printf("Temperature Readings:\n");
    for(i = 0; i < numReadings; i++)
    {
        printf("%d. %.1f\n", (i+1), temp[i]);
    }
    printf("Average temperature = %.2f\n", tempAvg);

    //analyzing temperature data and giving recommendations to user
    if(tempAvg > 30)
    {
        printf("It's very hot today! Make sure to stay hydrated and avoid prolonged exposure to the sun.\n");
    }
    else if(tempAvg > 20 && tempAvg <= 30)
    {
        printf("It's a nice day outside! Enjoy the weather, but remember to wear sunscreen.\n");
    }
    else if(tempAvg > 10 && tempAvg <= 20)
    {
        printf("It's a bit chilly today. Consider wearing a light jacket.\n");
    }
    else
    {
        printf("It's quite cold outside. Make sure to bundle up before heading out.\n");
    }
    
    return 0;
}