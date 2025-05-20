//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>

void greetUser() {
    printf("Welcome to the Wacky World of Temperature Conversion!\n");
    printf("Where Celsius is a chilly chap, and Fahrenheit is a hot tamale!\n");
    printf("Let's not make things too heated, shall we?\n");
}

float celsiusToFahrenheit(float celsius) {
    printf("Converting %.2f°C to Fahrenheit… hold on tight!\n", celsius);
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("Bam! %.2f°C is now a sizzling %.2f°F!\n", celsius, fahrenheit);
    return fahrenheit;
}

float fahrenheitToCelsius(float fahrenheit) {
    printf("Converting %.2f°F to Celsius… preparing for a chilly reception!\n", fahrenheit);
    float celsius = (fahrenheit - 32) * 5 / 9;
    printf("Oh snap! %.2f°F has transformed into a frosty %.2f°C!\n", fahrenheit, celsius);
    return celsius;
}

void printConversionOptions() {
    printf("\nChoose your hot or cold adventure:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Get help from the temperature trolls\n");
    printf("4. Exit the temperature realm (but you’ll regret it!)\n");
}

void helpFromTrolls() {
    printf("\nAttention, brave adventurer! The Temperature Trolls are here to assist you!\n");
    printf("Legend says that:\n");
    printf("1°C = 33.8°F. But what does that even mean?!\n");
    printf("Just remember, if it's freezing, we're talking Celsius! If it feels like you're in a sauna, it's Fahrenheit!\n");
    printf("Now, let's get back to converting!\n");
}

int main() {
    int choice;
    float temperature, convertedTemperature;

    greetUser();

    do {
        printConversionOptions();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);
                convertedTemperature = celsiusToFahrenheit(temperature);
                printf("You converted %.2f°C to %.2f°F. No thermometers were harmed in the process!\n", temperature, convertedTemperature);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                convertedTemperature = fahrenheitToCelsius(temperature);
                printf("You turned %.2f°F into %.2f°C. Magic! (Mostly math, but magic sounds better.)\n", temperature, convertedTemperature);
                break;
            case 3:
                helpFromTrolls();
                break;
            case 4:
                printf("You have chosen to exit the realm of temperature! But remember, it's a cold world out there!\n");
                break;
            default:
                printf("Whoa there! You picked an option that doesn’t exist in this universe!\n");
                break;
        }
        
        printf("\n");
    } while (choice != 4);

    printf("Thank you for visiting the Wacky World of Temperature Conversion!\n");
    printf("Stay warm, stay cool, and may the temperatures be ever in your favor!\n");
    
    return 0;
}