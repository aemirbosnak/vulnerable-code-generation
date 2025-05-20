//FormAI DATASET v1.0 Category: Weather simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Declaration of Variables
    int temperature, humidity; 
    int random_temp, random_humd;
    int i, j, choice;

    //Initializing Random Seed
    srand(time(NULL));

    //Title for the Program
    printf("\t\tWeather Simulation\n\n");

    //User Prompt for User Input
    printf("Enter the Choice for Location:\n");
    printf("1. London\n2. Paris\n3. Tokyo\n4. New York\n5. Sydney\n");
    scanf("%d", &choice);

    //Switch Statement for Random Temperature & Humidity Generation
    switch(choice){
        case 1:
            //London Temperature Range: 10°C - 20°C, Humidity Range: 60% - 80%
            random_temp = rand() % 11 + 10;
            random_humd = rand() % 21 + 60;
            break;
        case 2:
            //Paris Temperature Range: 15°C - 25°C, Humidity Range: 40% - 70%
            random_temp = rand() % 11 + 15;
            random_humd = rand() % 31 + 40;
            break;
        case 3:
            //Tokyo Temperature Range: 22°C - 30°C, Humidity Range: 70% - 90%
            random_temp = rand() % 9 + 22;
            random_humd = rand() % 21 + 70;
            break;
        case 4:
            //New York Temperature Range: 16°C - 25°C, Humidity Range: 50% - 70%
            random_temp = rand() % 10 + 16;
            random_humd = rand() % 21 + 50;
            break;
        case 5:
            //Sydney Temperature Range: 20°C - 32°C, Humidity Range: 50%  - 70%
            random_temp = rand() % 13 + 20;
            random_humd = rand() % 21 + 50;
            break;
        default:
            printf("Invalid Input!\n");
            exit(0);
    }

    //Simulation Loop with Conditions
    for(i=1; i<=10; i++){
        temperature = random_temp + rand() % 3 - 1;
        humidity = random_humd + rand() % 5 - 2;

        printf("Day %d\t ||\t Temperature: %d°C\t ||\t Humidity: %d%%\t", i, temperature, humidity);
        if(temperature >= 28){
            printf("Heat Wave!\n");
        }
        else if(temperature <= 5){
            printf("Freezing Temperature!\n");
        }
        else if(humidity >= 80){
            printf("Thunderstorm Warning!\n");
        }
        else if(humidity<= 30){
            printf("Dry Weather Warning!\n");
        }
        else{
            printf("\n");
        }
    }

    //End of Program
    printf("\nThank You for Using Weather Simulation Program.\n");
    return 0;
}