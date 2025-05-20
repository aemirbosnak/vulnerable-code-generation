//FormAI DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int temperatureRange[5][2] = {{-20, 5}, {5, 15}, {15, 25}, {25, 35}, {35, 45}}; // Different ranges of temperature
    char* weatherTypes[] = {"Sunny", "Cloudy", "Rainy", "Stormy", "Snowy"}; // Different weather types to select from
    
    srand(time(NULL)); // Set seed for randomization

    int month;
    int temperature;
    int weatherTypeIndex;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    // Check if month is within the range
    if(month < 1 || month > 12){
        printf("Invalid month entered");
        return 0;
    }

    // Get appropriate temperature range based on month
    if(month >= 3 && month <= 5){ // Spring months
        temperatureRange[1][0] = 10;
        temperatureRange[1][1] = 20;
        temperatureRange[2][0] = 20;
        temperatureRange[2][1] = 30;
    }
    else if(month >= 6 && month <= 8){ // Summer months
        temperatureRange[2][0] = 25;
        temperatureRange[2][1] = 35;
        temperatureRange[3][0] = 30;
        temperatureRange[3][1] = 40;
    }
    else if(month >= 9 && month <= 11){ // Autumn months
        temperatureRange[1][0] = 5;
        temperatureRange[1][1] = 15;
        temperatureRange[2][0] = 15;
        temperatureRange[2][1] = 25;
    }
    else{ // Winter months
        temperatureRange[0][0] = -10;
        temperatureRange[0][1] = 0;
        temperatureRange[4][0] = -10;
        temperatureRange[4][1] = 0;
    }

    // Generate random temperature within range
    temperature = rand() % (temperatureRange[month % 3][1] - temperatureRange[month % 3][0] + 1) + temperatureRange[month % 3][0];

    // Generate random weather type
    weatherTypeIndex = rand() % 5;

    // Output results
    printf("%s weather with a temperature of %d degrees Celsius\n", weatherTypes[weatherTypeIndex], temperature);

    return 0;
}