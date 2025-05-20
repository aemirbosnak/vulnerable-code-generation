//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_READINGS 10

void announce_temperature(float temp) {
    if (temp < 0) {
        printf("Hark! The air be as frigid as an ice dragon's breath! Measured temperature: %.2f degrees Fahrenheit.\n", temp * 9.0/5.0 + 32);
    } else if (temp > 100) {
        printf("Alas! The realm is scorched, akin to the fires of a thousand infernos! Measured temperature: %.2f degrees Fahrenheit.\n", temp * 9.0/5.0 + 32);
    } else {
        printf("Rejoice! The temperature dost rest safely within the realm of comfort! Measured temperature: %.2f degrees Fahrenheit.\n", temp * 9.0/5.0 + 32);
    }
}

float gather_temperature_reading() {
    // Randomly generating temperature between -30 and 130 degrees Fahrenheit
    return ((rand() % 161) - 30) * (5.0 / 9.0);
}

void display_all_readings(float readings[], int count) {
    printf("\n\\n=== Historical Temperature Readings ===\\n");
    for (int i = 0; i < count; i++) {
        printf("   Reading %d: %.2f degrees Celsius\n", i + 1, readings[i]);
    }
    printf("=========================================\n");
}

int main() {
    srand(time(0)); // Seed for randomness based on the time of day

    float temp_readings[MAX_READINGS];
    int reading_count = 0;
    char continue_monitoring;

    printf("In the realm of temperature monitoring, our noble quest begins...\n");

    do {
        if (reading_count >= MAX_READINGS) {
            printf("We have reached the maximum of %d readings!\n", MAX_READINGS);
            break;
        }

        float current_temp = gather_temperature_reading();
        temp_readings[reading_count] = current_temp;
        announce_temperature(current_temp);

        reading_count++;

        printf("Wouldst thou like to gather another reading? (y/n): ");
        scanf(" %c", &continue_monitoring);

    } while (continue_monitoring == 'y' || continue_monitoring == 'Y');

    printf("\nThe quest for knowledge hast concluded.\n");
    display_all_readings(temp_readings, reading_count);

    printf("Farewell, brave noble, until the next gathering of temperatures!\n");
    return 0;
}