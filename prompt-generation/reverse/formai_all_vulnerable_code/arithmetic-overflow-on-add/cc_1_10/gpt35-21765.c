//FormAI DATASET v1.0 Category: Weather simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random float value within given range
float generate_random(float min, float max) {
    return (rand() / (float) RAND_MAX) * (max - min) + min;
}

// Function to generate random integer within given range
int generate_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Default values for weather simulation parameters
    int num_days = 7;
    float min_temp = 10.0;
    float max_temp = 30.0;
    float min_humidity = 50.0;
    float max_humidity = 70.0;
    int num_cloudy_days = 3;
    int num_rainy_days = 2;

    // Read weather simulation parameters from user
    printf("Enter number of days to simulate weather for: ");
    scanf("%d", &num_days);
    printf("Enter minimum temperature: ");
    scanf("%f", &min_temp);
    printf("Enter maximum temperature: ");
    scanf("%f", &max_temp);
    printf("Enter minimum humidity: ");
    scanf("%f", &min_humidity);
    printf("Enter maximum humidity: ");
    scanf("%f", &max_humidity);
    printf("Enter number of cloudy days: ");
    scanf("%d", &num_cloudy_days);
    printf("Enter number of rainy days: ");
    scanf("%d", &num_rainy_days);

    // Loop for each day and simulate weather
    printf("Day\tTemperature\tHumidity\tCloudiness\tRainfall\n");
    for (int i = 1; i <= num_days; i++) {
        float temperature = generate_random(min_temp, max_temp);
        float humidity = generate_random(min_humidity, max_humidity);
        int is_cloudy = (i <= num_cloudy_days);
        int is_rainy = (i > num_cloudy_days && i <= (num_cloudy_days + num_rainy_days));
        float rainfall = (is_rainy) ? generate_random(0.1, 5.0) : 0.0;
        printf("%d\t%.1f C\t\t%.1f%%\t\t%s\t\t%.2f mm\n", i, temperature, humidity, (is_cloudy) ? "Yes" : "No", rainfall);
    }

    return 0;
}