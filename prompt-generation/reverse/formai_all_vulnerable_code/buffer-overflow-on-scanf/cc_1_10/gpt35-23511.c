//FormAI DATASET v1.0 Category: Temperature monitor ; Style: excited
#include <stdio.h>
#define MAX 5 // define the size of our array

// function prototypes
void getTemps(float temps[MAX]);
float calcAverage(float temps[MAX]);
void printAlert(float avgTemp);

int main(){
    float temperatures[MAX];
    float averageTemp;
    
    printf("Welcome to the Temperature Monitor Program!\n");
    
    // get temperature readings
    getTemps(temperatures);
    
    // calculate average temperature
    averageTemp = calcAverage(temperatures);
    
    // print alert if temperature is too high
    printAlert(averageTemp);
    
    return 0;
}

// function to get temperature readings
void getTemps(float temps[MAX]){
    int i;
    
    printf("\nEnter %d temperature readings:\n", MAX);
    
    for(i=0; i<MAX; i++){
        printf("Temperature %d: ", i+1);
        scanf("%f", &temps[i]);
    }
}

// function to calculate average temperature
float calcAverage(float temps[MAX]){
    int i;
    float sum = 0;
    float average;
    
    for(i=0; i<MAX; i++){
        sum += temps[i];
    }
    
    average = sum / MAX;
    
    printf("\nAverage Temperature: %.2f\n", average);
    
    return average;
}

// function to print alert if temperature is too high
void printAlert(float avgTemp){
    if(avgTemp > 25){
        printf("\nALERT! Average temperature is too high.\n");
    }
    else{
        printf("\nTemperature is within normal range.\n");
    }
}