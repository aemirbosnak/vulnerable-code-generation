//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the temperature scale
#define FREEZING 32
#define BOILING 212

// Define the time interval for temperature checks (in seconds)
#define TEMP_INTERVAL 5

// Function prototypes
void initialize();
void check_temperature();
void display_temperature();
void main_menu();

int main() {
    initialize();

    // Main program loop
    while (1) {
        main_menu();
        check_temperature();
        sleep(TEMP_INTERVAL);
    }

    return 0;
}

void initialize() {
    printf("Welcome to the Medieval Temperature Monitor!\n");
    printf("Initializing...\n");
    sleep(2);
}

void check_temperature() {
    int temperature = rand() % (BOILING - FREEZING) + FREEZING; // Generate a random temperature between freezing and boiling
    printf("Current temperature: %d degrees\n", temperature);
}

void display_temperature() {
    printf("Temperature: ");
}

void main_menu() {
    printf("\nMain Menu:\n");
    printf("1. Display current temperature\n");
    printf("2. Exit program\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            display_temperature();
            break;
        case 2:
            printf("Exiting program...\n");
            sleep(2);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}