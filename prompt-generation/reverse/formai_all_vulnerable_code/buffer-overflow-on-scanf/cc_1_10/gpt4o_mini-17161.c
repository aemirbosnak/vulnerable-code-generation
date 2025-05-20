//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

void twilight(float celsius) {
    printf("In this alternate universe, %.2f°C breathes life into the moonlight.\n", celsius);
    float kelvin = celsius + 273.15;
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

    printf("As the stars twinkle above, %.2f K transcends into the ether.\n", kelvin);
    printf("And the swirling galaxies, %.2f°F, dance in unison.\n", fahrenheit);
}

void whisperingGusts(int choice) {
    if (choice == 1) {
        printf("Oh wise traveler, welcome to the land of Celsius! What sweetness do you seek to convert?\n");
    } else if (choice == 2) {
        printf("Ah, the enchanting realm of Fahrenheit beckons. Share your number, let the transformation unfold!\n");
    } else {
        printf("In a world where choices blossom and wither, you have wandered into the labyrinth of indecision.\n");
    }
}

float celestialFahrenheit(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float cosmicCelsius(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

void danceOfTheSeasons(float value, int choice) {
    if (choice == 1) {
        twilight(value);
    } else if (choice == 2) {
        float convertedCelsius = celestialFahrenheit(value);
        printf("In the fabric of the universe, %0.2f°F gently unfolds into %0.2f°C.\n", value, convertedCelsius);
        twilight(convertedCelsius);
    }
}

int main() {
    int choice;
    
    printf("Welcome to the Celestial Temperature Converter!\n");
    printf("Choose the realm you wish to explore:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 2) {
        printf("You have wandered too far! The temperature trails have faded away.\n");
        exit(1);
    }

    float value;
    if (choice == 1) {
        printf("Emerge from the fog, declare your Celsius value: ");
        scanf("%f", &value);
        whisperingGusts(choice);
    } else {
        printf("Whispers in the wind, speak your Fahrenheit value: ");
        scanf("%f", &value);
        whisperingGusts(choice);
    }
    
    danceOfTheSeasons(value, choice);

    printf("As the sun sets behind the hills, remember, each number translates a feeling from one realm to another.\n");
    printf("May your understanding of temperature expand like the universe around us!\n");

    return 0;
}