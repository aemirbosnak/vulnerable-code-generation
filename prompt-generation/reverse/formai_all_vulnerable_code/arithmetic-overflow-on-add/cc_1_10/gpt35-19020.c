//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//Function to get weather condition
char* getCondition(int num){
    switch(num){
        case 0: 
            return "Sunny";
        case 1: 
            return "Rainy";
        case 2: 
            return "Cloudy";
        case 3: 
            return "Snowy";
        default: 
            return "Unknown";
    }
}

int main(){
    int i=0, weatherCondition, temperature, humidity;
    printf("Welcome to Weather Simulation\n\n");
    printf("Please enter the temperature (in Celsius): ");
    scanf("%d", &temperature);
    printf("\nPlease enter the humidity (in percentage): ");
    scanf("%d", &humidity);
    srand(time(0)); //Setting seed for random number generator
    while(i<24){ //Loop for 24 hours
        weatherCondition = rand() % 4; //Generating a random number between 0-3
        printf("\nHour %d: Temperature is %d Celsius and Humidity is %d%%. Weather condition is %s\n", i+1, temperature, humidity, getCondition(weatherCondition));
        //Simulating change in temperature and humidity based on weather condition
        switch(weatherCondition){
            case 0: //Sunny condition
                temperature += rand() % 3; //Temperature can increase by 0-2 Celsius degrees
                humidity -= rand() % 5; //Humidity can decrease by 0-4%
                break;
            case 1: //Rainy condition
                temperature -= rand() % 3; //Temperature can decrease by 0-2 Celsius degrees
                humidity += rand() % 10; //Humidity can increase by 0-9%
                break;
            case 2: //Cloudy condition
                temperature += rand() % 2; //Temperature can increase by 0-1 Celsius degrees
                humidity += rand() % 3; //Humidity can increase by 0-2%
                break;
            case 3: //Snowy condition
                temperature -= rand() % 4; //Temperature can decrease by 0-3 Celsius degrees
                humidity += rand() % 5; //Humidity can increase by 0-4%
                break;
        }
        i++;
    }
    printf("\nThank you for using Weather Simulation!\n");
    return 0;
}