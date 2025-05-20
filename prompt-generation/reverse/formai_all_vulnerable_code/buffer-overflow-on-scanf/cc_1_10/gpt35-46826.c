//FormAI DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Declare global variables
int temperature = 20;
int light_intensity = 50;
bool fireplace_on = false;
bool candle_on = false;

// Declare function prototypes
void set_temperature(int value);
void set_light_intensity(int value);
void turn_on_fireplace();
void turn_off_fireplace();
void light_candle();
void blow_out_candle();
void display_status();

// Main function
int main() {
    int choice;
    printf("Welcome to your medieval smart home!\n");

    // Loop to continually display menu and get user input
    while (true) {
        printf("What would you like to do?\n");
        printf("1. Set temperature\n");
        printf("2. Set light intensity\n");
        printf("3. Turn on fireplace\n");
        printf("4. Turn off fireplace\n");
        printf("5. Light candle\n");
        printf("6. Blow out candle\n");
        printf("7. Display current status\n");
        printf("8. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch statement to perform desired action based on user choice
        switch (choice) {
            case 1:
                printf("Enter desired temperature (in Celsius): ");
                int temp;
                scanf("%d", &temp);
                set_temperature(temp);
                break;
            case 2:
                printf("Enter desired light intensity (out of 100): ");
                int intensity;
                scanf("%d", &intensity);
                set_light_intensity(intensity);
                break;
            case 3:
                turn_on_fireplace();
                break;
            case 4:
                turn_off_fireplace();
                break;
            case 5:
                light_candle();
                break;
            case 6:
                blow_out_candle();
                break;
            case 7:
                display_status();
                break;
            case 8:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

// Function to set temperature
void set_temperature(int value) {
    printf("Setting temperature to %d degrees Celsius...\n", value);
    temperature = value;
}

// Function to set light intensity
void set_light_intensity(int value) {
    printf("Setting light intensity to %d out of 100...\n", value);
    light_intensity = value;
}

// Function to turn on fireplace
void turn_on_fireplace() {
    printf("Turning on fireplace...\n");
    fireplace_on = true;
}

// Function to turn off fireplace
void turn_off_fireplace() {
    printf("Turning off fireplace...\n");
    fireplace_on = false;
}

// Function to light candle
void light_candle() {
    printf("Lighting candle...\n");
    candle_on = true;
}

// Function to blow out candle
void blow_out_candle() {
    printf("Blowing out candle...\n");
    candle_on = false;
}

// Function to display current status
void display_status() {
    printf("Current temperature: %d degrees Celsius\n", temperature);
    printf("Current light intensity: %d out of 100\n", light_intensity);
    printf("Fireplace is %s\n", fireplace_on ? "on" : "off");
    printf("Candle is %s\n", candle_on ? "lit" : "not lit");

    // Get current time and print appropriate message
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    if (tm->tm_hour < 6 || tm->tm_hour > 21) {
        printf("It is currently night time.\n");
    } else {
        printf("It is currently day time.\n");
    }
}