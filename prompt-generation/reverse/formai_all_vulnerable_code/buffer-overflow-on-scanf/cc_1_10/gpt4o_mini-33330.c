//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WEATHER_TYPES 7

// Weather types
const char *weatherTypes[NUM_WEATHER_TYPES] = {
    "Sunny", 
    "Rainy", 
    "Cloudy", 
    "Windy", 
    "Snowy", 
    "Stormy", 
    "Foggy"
};

// Function to generate random weather
const char* getRandomWeather() {
    return weatherTypes[rand() % NUM_WEATHER_TYPES];
}

// Funny function to explain the weather
void explainWeather(const char* weather) {
    if (strcmp(weather, "Sunny") == 0) {
        printf("Ah, the sun is out! Time to forget sunscreen and look like a lobster!\n");
    } else if (strcmp(weather, "Rainy") == 0) {
        printf("Grab your umbrellas and your paddles! It's not just rain; it's the ocean!\n");
    } else if (strcmp(weather, "Cloudy") == 0) {
        printf("Feeling gray? Just like my hair! At least it’s not snowing...\n");
    } else if (strcmp(weather, "Windy") == 0) {
        printf("Hold onto your hats or regret the hat you just bought!\n");
    } else if (strcmp(weather, "Snowy") == 0) {
        printf("Snowflakes are just nature's way of saying, 'Here, have a cold surprise!'\n");
    } else if (strcmp(weather, "Stormy") == 0) {
        printf("It's like living in a horror movie. Check your flashlight batteries!\n");
    } else if (strcmp(weather, "Foggy") == 0) {
        printf("It's so foggy, I can't see my own shadow! Maybe I should move!\n");
    }
}

// Main weather simulation function
void simulateWeather(int days) {
    int i;
    printf("Welcome to the Totally Accurate and Not at All Made Up Weather Simulator!\n");
    printf("You will get a forecast for the next %d days. Buckle up!\n\n", days);

    for (i = 0; i < days; i++) {
        const char* weather = getRandomWeather();
        printf("Day %d: The weather is %s. ", i + 1, weather);
        explainWeather(weather);
        printf("\n---\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int days;

    printf("How many days of weather would you like to simulate? (Please pick a number between 1 and 365)\n");
    scanf("%d", &days);

    if (days < 1 || days > 365) {
        printf("That number seems a bit fishy. Let's stick with 1 to 365, okay?\n");
        return 1;
    }

    simulateWeather(days);

    printf("Thanks for using the Totally Accurate and Not at All Made Up Weather Simulator!\n");
    printf("Remember: The weather is just like life — unpredictable, so grab a cat! (because they know!)\n");

    return 0;
}