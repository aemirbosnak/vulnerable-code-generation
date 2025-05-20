//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the temperature threshold in degrees Celsius
#define TEMP_THRESHOLD 25

// Define the GPIO pin used for the temperature sensor
#define TEMP_SENSOR_PIN 17

// Define the GPIO pin used for the LED indicator
#define LED_PIN 22

// Initialize the GPIO pins
void init_gpio() {
    // Export the GPIO pins
    system("echo 17 > /sys/class/gpio/export");
    system("echo 22 > /sys/class/gpio/export");

    // Set the GPIO pins to output mode
    system("echo out > /sys/class/gpio/gpio17/direction");
    system("echo out > /sys/class/gpio/gpio22/direction");
}

// Read the temperature from the temperature sensor
float read_temperature() {
    // Read the temperature from the sysfs file
    float temperature;
    FILE *fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    fscanf(fp, "%f", &temperature);
    fclose(fp);

    // Convert the temperature to degrees Celsius
    temperature /= 1000;

    return temperature;
}

// Set the LED indicator based on the temperature
void set_led(float temperature) {
    // Turn on the LED if the temperature is above the threshold
    if (temperature > TEMP_THRESHOLD) {
        system("echo 1 > /sys/class/gpio/gpio22/value");
    } else {
        system("echo 0 > /sys/class/gpio/gpio22/value");
    }
}

// Main program loop
int main() {
    // Initialize the GPIO pins
    init_gpio();

    // Main program loop
    while (1) {
        // Read the temperature from the temperature sensor
        float temperature = read_temperature();

        // Set the LED indicator based on the temperature
        set_led(temperature);

        // Print the temperature to the console
        printf("Temperature: %.2f °C\n", temperature);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}