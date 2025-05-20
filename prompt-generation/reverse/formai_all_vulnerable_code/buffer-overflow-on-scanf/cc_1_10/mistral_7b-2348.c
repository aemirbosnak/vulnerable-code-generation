//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef enum Planet {
    MERCURY = 0,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
    NUM_PLANETS
} Planet;

typedef struct Temperature {
    float celsius;
    float fahrenheit;
} Temperature;

void print_planet_info(Planet planet) {
    switch (planet) {
        case MERCURY:
            printf("Planet: Mercury\n");
            printf("Average Temperature: %0.1f°C\n", 16.6);
            break;
        case VENUS:
            printf("Planet: Venus\n");
            printf("Average Temperature: %0.1f°C\n", 46.4);
            break;
        case EARTH:
            printf("Planet: Earth\n");
            printf("Average Temperature: %0.1f°C\n", 15.0);
            break;
        case MARS:
            printf("Planet: Mars\n");
            printf("Average Temperature: %0.1f°C\n", 20.7);
            break;
        case JUPITER:
            printf("Planet: Jupiter\n");
            printf("Average Temperature: %0.1f°C\n", -110.0);
            break;
        case SATURN:
            printf("Planet: Saturn\n");
            printf("Average Temperature: %0.1f°C\n", -138.0);
            break;
        case URANUS:
            printf("Planet: Uranus\n");
            printf("Average Temperature: %0.1f°C\n", -195.0);
            break;
        case NEPTUNE:
            printf("Planet: Neptune\n");
            printf("Average Temperature: %0.1f°C\n", -200.0);
            break;
        default:
            printf("Invalid planet.\n");
            break;
    }
}

void convert_fahrenheit_to_celsius(float fahrenheit, Temperature *temp) {
    temp->celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    Temperature temperature;
    float fahrenheit;

    print_planet_info(EARTH);

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    convert_fahrenheit_to_celsius(fahrenheit, &temperature);

    printf("Equivalent temperature in Celsius: %0.1f°C\n", temperature.celsius);

    return 0;
}