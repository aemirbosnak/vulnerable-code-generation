//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void greeting() {
    printf("Howdy there, partner! Welcome to the Unit Converter Extravaganza!\n");
    printf("We're gonna have a rootin'-tootin' time convertin' all sorts of units!\n\n");
}

void menu() {
    printf("Here's the lowdown on what we can do:\n");
    printf("1. Convert lengths (meters, feet, inches)\n");
    printf("2. Convert weights (grams, kilograms, pounds)\n");
    printf("3. Convert volumes (liters, gallons, cups)\n");
    printf("4. Convert temperatures (Celsius, Fahrenheit, Kelvin)\n");
    printf("5. Say howdy to the creator\n");
    printf("6. Saddle up and ride out of here\n");
}

void convert_lengths() {
    float value, result;
    int choice;

    printf("Howdy, length converter! Whatcha want to do?\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert feet to meters\n");
    printf("3. Convert inches to meters\n");
    printf("4. Convert meters to inches\n");
    scanf("%d", &choice);

    printf("Gimme the value you want to convert, partner:\n");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = value * 3.28084;
            printf("That's %.2f feet, pardner!\n", result);
            break;
        case 2:
            result = value / 3.28084;
            printf("That's %.2f meters, hombre!\n", result);
            break;
        case 3:
            result = value * 0.0254;
            printf("That's %.2f meters, amigo!\n", result);
            break;
        case 4:
            result = value / 0.0254;
            printf("That's %.2f inches, buckaroo!\n", result);
            break;
        default:
            printf("Hold yer horses, partner! That's not a valid choice.\n");
    }
}

void convert_weights() {
    float value, result;
    int choice;

    printf("Howdy, weight wrangler! What's the scoop?\n");
    printf("1. Convert grams to kilograms\n");
    printf("2. Convert kilograms to grams\n");
    printf("3. Convert pounds to kilograms\n");
    printf("4. Convert kilograms to pounds\n");
    scanf("%d", &choice);

    printf("Gimme the weight you want to convert, partner:\n");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = value / 1000;
            printf("That's %.2f kilograms, partner!\n", result);
            break;
        case 2:
            result = value * 1000;
            printf("That's %.2f grams, hombre!\n", result);
            break;
        case 3:
            result = value * 0.453592;
            printf("That's %.2f kilograms, amigo!\n", result);
            break;
        case 4:
            result = value / 0.453592;
            printf("That's %.2f pounds, buckaroo!\n", result);
            break;
        default:
            printf("Whoa there, partner! That's not a valid choice.\n");
    }
}

void convert_volumes() {
    float value, result;
    int choice;

    printf("Howdy, volume virtuoso! What's on your mind?\n");
    printf("1. Convert liters to gallons\n");
    printf("2. Convert gallons to liters\n");
    printf("3. Convert cups to liters\n");
    printf("4. Convert liters to cups\n");
    scanf("%d", &choice);

    printf("Gimme the volume you want to convert, partner:\n");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = value * 0.264172;
            printf("That's %.2f gallons, partner!\n", result);
            break;
        case 2:
            result = value / 0.264172;
            printf("That's %.2f liters, hombre!\n", result);
            break;
        case 3:
            result = value * 0.236588;
            printf("That's %.2f liters, amigo!\n", result);
            break;
        case 4:
            result = value / 0.236588;
            printf("That's %.2f cups, buckaroo!\n", result);
            break;
        default:
            printf("Hold your horses, partner! That's not a valid choice.\n");
    }
}

void convert_temperatures() {
    float value, result;
    int choice;

    printf("Howdy, temperature tamer! What's the sitch?\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert Kelvin to Celsius\n");
    printf("4. Convert Celsius to Kelvin\n");
    scanf("%d", &choice);

    printf("Gimme the temperature you want to convert, partner:\n");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            result = (value * 9 / 5) + 32;
            printf("That's %.2f Fahrenheit, partner!\n", result);
            break;
        case 2:
            result = (value - 32) * 5 / 9;
            printf("That's %.2f Celsius, hombre!\n", result);
            break;
        case 3:
            result = value - 273.15;
            printf("That's %.2f Celsius, amigo!\n", result);
            break;
        case 4:
            result = value + 273.15;
            printf("That's %.2f Kelvin, buckaroo!\n", result);
            break;
        default:
            printf("Whoa there, partner! That's not a valid choice.\n");
    }
}

void say_howdy() {
    printf("Howdy, there, I'm your friendly neighborhood unit converter!\n");
    printf("My name is Codey, and I'm here to make your life a little bit easier.\n");
    printf("I can convert all sorts of units, from lengths to weights to temperatures.\n");
    printf("So saddle up, partner, and let's ride!\n");
}

int main() {
    int choice;

    greeting();
    menu();

    while (1) {
        printf("What can I do for ya, partner?\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_lengths();
                break;
            case 2:
                convert_weights();
                break;
            case 3:
                convert_volumes();
                break;
            case 4:
                convert_temperatures();
                break;
            case 5:
                say_howdy();
                break;
            case 6:
                printf("Well, shucks, partner. It's been a pleasure ridin' with ya!\n");
                printf("Come back anytime if you need another conversion!\n");
                return 0;
            default:
                printf("Whoa there, partner! That's not a valid choice.\n");
        }
    }

    return 0;
}