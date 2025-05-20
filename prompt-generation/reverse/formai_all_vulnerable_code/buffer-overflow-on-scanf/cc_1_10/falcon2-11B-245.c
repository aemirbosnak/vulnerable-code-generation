//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>

// Sherlock's Investigation:

int main() {
    // A cold night in London
    // Sherlock Holmes was walking along Baker Street
    // The moon was shining brightly
    // Suddenly, he saw a young man shivering in the cold
    // The young man was holding a thermometer in his hand

    // Sherlock approached the young man
    // He asked, "What is the temperature?"
    // The young man replied, "It is -10 degrees Celsius"

    // Sherlock's mind was already working
    // He knew that the young man needed to know the temperature in Fahrenheit

    // He took out his notebook and started writing
    // "Celsius to Fahrenheit conversion formula: (Celsius * 9/5) + 32"

    // He explained the formula to the young man
    // The young man thanked Sherlock and left

    // Sherlock's mind was working again
    // He knew that the young man might have made a mistake in the input temperature

    // He decided to write a program to handle such cases

    // The program would take an input temperature
    // It would check if the input is valid
    // If the input is valid, it would convert it to Fahrenheit
    // If the input is invalid, it would display an error message

    // Sherlock's program:

    int celsius;
    int fahrenheit;

    printf("Enter the temperature in Celsius: ");
    scanf("%d", &celsius);

    if (celsius >= -273.15 && celsius <= 1000) {
        fahrenheit = (celsius * 9/5) + 32;
        printf("The temperature in Fahrenheit is: %d\n", fahrenheit);
    } else {
        printf("Invalid temperature input!\n");
    }

    return 0;
}