//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WEATHER_TYPES 5

const char *weather_types[NUM_WEATHER_TYPES] = {
    "Sunny",
    "Rainy",
    "Cloudy",
    "Stormy",
    "Snowy"
};

// Function to generate a random temperature based on weather type
int generate_temperature(const char* weather) {
    if (strcmp(weather, "Sunny") == 0) {
        return rand() % 25 + 20; // 20 to 44 degrees
    } else if (strcmp(weather, "Rainy") == 0) {
        return rand() % 10 + 10; // 10 to 19 degrees
    } else if (strcmp(weather, "Cloudy") == 0) {
        return rand() % 10 + 15; // 15 to 24 degrees
    } else if (strcmp(weather, "Stormy") == 0) {
        return rand() % 10 + 5;  // 5 to 14 degrees
    } else if (strcmp(weather, "Snowy") == 0) {
        return rand() % 10 - 5;   // -5 to 4 degrees
    }
    return 0; // Default value
}

void display_weather() {
    printf("Welcome to the Weather Simulation Program!\n");
    printf("============================================\n");
    for (int i = 0; i < NUM_WEATHER_TYPES; ++i) {
        printf("%d. %s\n", i + 1, weather_types[i]);
    }
    printf("============================================\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    while (1) {
        display_weather();
        
        printf("Select a weather type (1-5) or 0 to exit: ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Thank you for using the Weather Simulation Program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        const char* selected_weather = weather_types[choice - 1];
        int temperature = generate_temperature(selected_weather);
        
        printf("Today's weather is: %s\n", selected_weather);
        printf("Current temperature: %d°C\n", temperature);

        // Adapting a fun weather-related quote
        if (strcmp(selected_weather, "Sunny") == 0) {
            printf("Sunshine is the best medicine!\n");
        } else if (strcmp(selected_weather, "Rainy") == 0) {
            printf("Life isn't about waiting for the storm to pass, it's about learning to dance in the rain!\n");
        } else if (strcmp(selected_weather, "Cloudy") == 0) {
            printf("Even the cloudiest day has the potential for a sunny future!\n");
        } else if (strcmp(selected_weather, "Stormy") == 0) {
            printf("After every storm comes a rainbow!\n");
        } else if (strcmp(selected_weather, "Snowy") == 0) {
            printf("There’s no such thing as bad weather, only inappropriate clothing!\n");
        }

        printf("============================================\n");
        printf("Press Enter to continue...");
        while (getchar() != '\n'); // Clearing buffer to wait for Enter
        getchar(); // For the Enter key press
    }
    
    return 0;
}