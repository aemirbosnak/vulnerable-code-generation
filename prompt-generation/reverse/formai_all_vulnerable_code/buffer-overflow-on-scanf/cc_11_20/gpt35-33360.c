//FormAI DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL)); //initialize random number generator
    
    printf("Welcome to the Weather Simulator!\n");
    printf("Please enter the number of days you would like to simulate: ");
    
    int numDays;
    scanf("%d", &numDays);
    
    if(numDays < 1) {
        printf("Invalid input! Number of days must be a positive integer.\n");
        return 0;
    }
    
    printf("Simulating weather for %d days...\n", numDays);
    
    int day;
    for(day = 1; day <= numDays; day++) {
        
        int temperature = rand() % 51 - 20; //generate random temperature from -20 to 30
        
        printf("\n"); //add spacing
        
        switch(day % 7) { //determine day of week
            
            case 1:
                printf("Monday, ");
                break;
            case 2:
                printf("Tuesday, ");
                break;
            case 3:
                printf("Wednesday, ");
                break;
            case 4:
                printf("Thursday, ");
                break;
            case 5:
                printf("Friday, ");
                break;
            case 6:
                printf("Saturday, ");
                break;
            case 0:
                printf("Sunday, ");
        }
        
        printf("Day %d:\n", day);
        printf("Temperature: %d degrees Celsius\n", temperature);
        
        if(temperature < 0) {
            printf("Brrr, it's freezing outside!\n");
        }
        else if(temperature >= 0 && temperature <= 15) {
            printf("It's a bit chilly, you might want a jacket.\n");
        }
        else if(temperature > 15 && temperature <= 25) {
            printf("This is perfect weather for a picnic!\n");
        }
        else if(temperature > 25 && temperature <= 30) {
            printf("It's getting hot, time for some ice cream.\n");
        }
        else {
            printf("Wow, it's scorching outside! Stay hydrated.\n");
        }
        
    }
    
    printf("\nSimulation complete. Thank you for using the Weather Simulator!\n");
    
    return 0;
}