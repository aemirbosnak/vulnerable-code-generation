//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

int main() {
    // Let's start by giving our program some pep!
    printf("Hip hip hooray! Welcome to the temperature conversion extravaganza!\n");

    // Time to gather the temperature we're converting.
    float temperature;
    printf("Tell me, what's the temperature you want to convert, my friend?\n");
    scanf("%f", &temperature);

    // Now let's ask what units they're starting with.
    char unit;
    printf("And are we starting with Fahrenheit (F) or Celsius (C)?\n");
    scanf(" %c", &unit); // Extra space to avoid issues with whitespace

    // We'll convert to both Fahrenheit and Celsius for fun!
    float fahrenheit, celsius;

    switch (unit) {
        case 'F':
        case 'f':
            // Fahrenheit to Celsius conversion magic!
            celsius = (temperature - 32) * 5 / 9;
            printf("Ta-da! That's %0.2f degrees Celsius!\n", celsius);

            // Now let's do the reverse, just for kicks.
            fahrenheit = (temperature * 9 / 5) + 32;
            printf("And here you go, %0.2f degrees Fahrenheit!\n", fahrenheit);
            break;

        case 'C':
        case 'c':
            // Celsius to Fahrenheit hocus pocus!
            fahrenheit = (temperature * 9 / 5) + 32;
            printf("Abracadabra! That's %0.2f degrees Fahrenheit!\n", fahrenheit);

            // And back to Celsius, for good measure.
            celsius = (temperature - 32) * 5 / 9;
            printf("Voilà! %0.2f degrees Celsius!\n", celsius);
            break;

        default:
            // Oops, they didn't enter a valid unit.
            printf("Oops, looks like you didn't choose Fahrenheit or Celsius. Let's try again!\n");
    }

    // And we're done! Time to bid farewell.
    printf("Well, that's all for today, my temperature-converting chum! Stay cool or warm, whichever floats your boat!\n");
    return 0;
}