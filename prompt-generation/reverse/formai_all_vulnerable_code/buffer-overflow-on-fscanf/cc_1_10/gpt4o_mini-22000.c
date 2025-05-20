//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void displayWelcomeMessage() {
    printf("🌞 Welcome to the Cheerful Temperature Monitor! 🌡️\n");
    printf("Let's keep an eye on the temperature and have some fun! 🌈\n\n");
}

void displayGoodbyeMessage() {
    printf("\nThank you for using the Cheerful Temperature Monitor! 🎉\n");
    printf("Stay warm and happy! See you next time! 👋\n");
}

void displayTemperature(float temperature) {
    printf("Current Temperature: %.2f °C\n", temperature);
    
    if (temperature < 0.0) {
        printf("❄️ Brrr! It's freezing out there! Bundle up! 🧣\n");
    } else if (temperature >= 0.0 && temperature <= 20.0) {
        printf("🌬️ Chilly weather! A cozy sweater is a great idea! 🧥\n");
    } else if (temperature > 20.0 && temperature <= 30.0) {
        printf("🌷 Perfect temperature! How about a nice walk in the park? 🚶‍♂️🌳\n");
    } else {
        printf("🔥 Whoa! It's hot! Time for some ice cream! 🍦\n");
    }
}

float readTemperatureFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("😟 Uh-oh! We couldn't open the file '%s'. Please make sure it exists! 📂\n", filename);
        exit(EXIT_FAILURE);
    }

    float temperature;
    if (fscanf(file, "%f", &temperature) != 1) {
        printf("🚫 Oops! We couldn't read the temperature. Please check the file format! 📜\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return temperature;
}

int main() {
    displayWelcomeMessage();

    const char *filename = "temperature.txt";
    float currentTemperature = readTemperatureFromFile(filename);

    displayTemperature(currentTemperature);

    displayGoodbyeMessage();
    return 0;
}