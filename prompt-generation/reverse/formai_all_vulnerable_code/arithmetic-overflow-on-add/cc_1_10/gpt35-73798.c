//FormAI DATASET v1.0 Category: Weather simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //Initialize variables
    int minTemp, maxTemp, currentTemp, humidity, i;
    char weatherCondition[10];
    time_t t;

    //Seeding RNG
    srand((unsigned) time(&t));

    //User Input for Temperature Range
    printf("Enter Minimum Temperature: ");
    scanf("%d", &minTemp);
    printf("Enter Maximum Temperature: ");
    scanf("%d", &maxTemp);

    //Simulating Hourly Weather for 24 hours
    for(i=1; i<=24; i++){

        //Generating Temperature between range
        currentTemp = rand()%(maxTemp-minTemp+1) + minTemp;

        //Assigning Weather Condition based on Temperature
        if(currentTemp>=0 && currentTemp<=9){
            strcpy(weatherCondition, "Snowy");
        } else if(currentTemp>=10 && currentTemp<=19){
            strcpy(weatherCondition, "Cold");
        } else if(currentTemp>=20 && currentTemp<=29){
            strcpy(weatherCondition, "Mild");
        } else if(currentTemp>=30 && currentTemp<=39){
            strcpy(weatherCondition, "Warm");
        } else {
            strcpy(weatherCondition, "Hot");
        }

        //Generating Humidity
        humidity = rand()%101;

        //Printing Hourly Weather Report
        printf("\nHour %d:\n", i);
        printf("Temperature: %dC\n", currentTemp);
        printf("Humidity: %d%%\n", humidity);
        printf("Weather Condition: %s\n", weatherCondition);
    }

    return 0;
}