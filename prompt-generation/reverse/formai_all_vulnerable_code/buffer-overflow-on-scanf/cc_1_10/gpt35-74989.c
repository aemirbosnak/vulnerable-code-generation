//FormAI DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {

    float temperature;
    int count = 0;
    float highTemp = 0.0;
    float lowTemp = 100.0;
    float totalTemp = 0.0;
    
    printf("Welcome to the Happy Temperature Monitoring System!\n");
    printf("Please enter the temperature:\n");

    while(scanf("%f", &temperature) == 1) {
        if(temperature > 100.0) {
            printf("Temperature is too high! Please enter a temperature lower than 100 degrees Celsius.\n");
            continue;
        } else if(temperature < 0) {
            printf("Temperature is too low! Please enter a temperature higher than 0 degrees Celsius.\n");
            continue;
        }

        totalTemp += temperature;
        count++;

        if(temperature > highTemp) {
            highTemp = temperature;
        }

        if(temperature < lowTemp) {
            lowTemp = temperature;
        }
        
        printf("Temperature recorded! Please enter another temperature or type 'q' to quit:\n");
    }

    printf("\nTemperature Monitoring System Exiting...\n");

    if (count > 0) {
        float average = totalTemp / count;
        printf("\nTotal Temperature Recorded: %.2f Celsius\n", totalTemp);
        printf("Highest Temperature Recorded: %.2f Celsius\n", highTemp);
        printf("Lowest Temperature Recorded: %.2f Celsius\n", lowTemp);
        printf("Average Temperature Recorded: %.2f Celsius\n", average);
    } else {
        printf("\nNo Temperature Readings Were Recorded.\n");
    }

    return 0;
}