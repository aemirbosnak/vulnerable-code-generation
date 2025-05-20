//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SENSORS 5

// Fun fact: Temperature is a measure of the average kinetic energy of particles!
const char* get_temperature_status(float temp) {
    if (temp < 0) {
        return "Brrr! It's freezing!";
    } else if (temp <= 15) {
        return "Chilly! Grab a sweater!";
    } else if (temp <= 25) {
        return "Just right! Perfect weather!";
    } else if (temp <= 35) {
        return "Getting warm! Stay hydrated!";
    } else {
        return "Whoa! It's scorching!";
    }
}

float read_sensor(int sensor_id) {
    srand(time(NULL) + sensor_id);  // seed randomization based on sensor ID
    return (float)(rand() % 5000) / 100.0; // Generate a temperature between 0°C and 50°C
}

void display_temperature(float temp, int sensor_id) {
    printf("Sensor %d: %.2f°C - %s\n", sensor_id, temp, get_temperature_status(temp));
}

int main() {
    int update_interval = 2; // Update every 2 seconds
    int total_sensors = MAX_SENSORS;

    printf("🔥 Welcome to the C Temperature Monitor! 🔥\n");
    printf("Monitoring %d sensors in real-time!\n\n", total_sensors);

    // Continuous monitoring loop
    while (1) {
        for (int i = 0; i < total_sensors; i++) {
            float temperature = read_sensor(i);
            display_temperature(temperature, i);
        }

        printf("\n✨ Updating temperatures! Please wait...\n\n");
        sleep(update_interval); // Data refresh interval
    }

    return 0;
}