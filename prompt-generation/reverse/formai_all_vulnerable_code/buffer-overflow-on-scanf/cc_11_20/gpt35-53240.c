//FormAI DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

printf("Welcome to Weather Simulation Program!\n\n");

//creating variables
int temperature;
int humidity;
int rain_chance;
int temperature_choice;
int humidity_choice;
char again_choice;

do {
    //setting seed for random numbers
    srand(time(NULL)); 

    //setting temperature randomly
    temperature = rand() % (101 + 1 - (-100)) + (-100);
    printf("Today's temperature is: %d degrees Celsius.\n", temperature);

    //setting humidity randomly
    humidity = rand() % (101 + 1 - 0) + 0;
    printf("Today's humidity is: %d%%.\n", humidity);

    //setting rain chance randomly
    rain_chance = rand() % (101 + 1 - 0) + 0;
    printf("Today's chance of rain is: %d%%.\n", rain_chance);

    //determining temperature feedback based on range
    if (temperature <= -30) {
        printf("It's freezing outside! Wear at least 4 layers of warm clothing!\n");
    } else if (temperature <= -10) {
        printf("It's very cold outside! Wear 3 layers of clothing!\n");
    } else if (temperature <= 0) {
        printf("It's chilly outside! Wear 2 layers of clothing!\n");
    } else if (temperature <= 10) {
        printf("It's mild outside! Wear a coat or jacket!\n");
    } else if (temperature <= 20) {
        printf("It's warm outside! Wear a light jacket!\n");
    } else if (temperature <= 30) {
        printf("It's hot outside! Wear light clothing!\n");
    } else {
        printf("It's scorching outside! Stay hydrated and seek shade!\n");
    }

    //determining humidity feedback based on range
    if (humidity <= 30) {
        printf("It's very dry outside! Moisturize your skin!\n");
    } else if (humidity <= 60) {
        printf("It's comfortable outside! Good weather for outdoor activities!\n");
    } else {
        printf("It's very humid outside! Stay hydrated and wear loose, breathable clothing!\n");
    }

    //determining rain chance feedback based on range
    if (rain_chance <= 30) {
        printf("There's a low chance of rain. Enjoy the day!\n");
    } else if (rain_chance <= 60) {
        printf("There's a moderate chance of rain. Bring an umbrella just in case!\n");
    } else {
        printf("There's a high chance of rain. Stay dry and indoors if possible!\n");
    }

    printf("\nWould you like to simulate the weather again? (Y/N)\n");
    scanf(" %c", &again_choice);

} while (again_choice == 'Y' || again_choice == 'y');

printf("\nThank you for using Weather Simulation Program!\n");

return 0;
}