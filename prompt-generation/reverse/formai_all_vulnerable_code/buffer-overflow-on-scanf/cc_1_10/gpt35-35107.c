//FormAI DATASET v1.0 Category: Smart home automation ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define LIGHT_OFF '0'
#define LIGHT_ON '1'
#define FAN_OFF '2'
#define FAN_LOW '3'
#define FAN_MEDIUM '4'
#define FAN_HIGH '5'

/* Function prototypes */
void displayMenu();
bool isValidOption(char option);
void processOption(char option);
void turnLightOn();
void turnLightOff();
void turnFanOn();
void turnFanOff();
void setFanSpeed(char speed);

/* Global variable */
char fanSpeed = FAN_OFF;

int main() {
    char option;
    displayMenu();
    scanf("%c", &option);
    
    while (option != 'q') {
        if (isValidOption(option)) {
            processOption(option);
        } else {
            printf("Invalid option! Please try again.\n");
        }
        displayMenu();
        scanf(" %c", &option);
    }
    
    printf("Exiting program...");
    exit(EXIT_SUCCESS);
}

void displayMenu() {
    system("clear");
    printf("Smart Home Automation System\n");
    printf("----------------------------\n\n");
    printf("Options:\n");
    printf("1. Turn light on\n");
    printf("2. Turn light off\n");
    printf("3. Turn fan on\n");
    printf("4. Turn fan off\n");
    printf("5. Set fan speed\n");
    printf("q. Quit program\n\n");
    printf("Enter an option: ");
}

bool isValidOption(char option) {
    return (option == '1' || option == '2' || option == '3' || option == '4' || option == '5' || option == 'q');
}

void processOption(char option) {
    switch (option) {
        case '1':
            turnLightOn();
            break;
        case '2':
            turnLightOff();
            break;
        case '3':
            turnFanOn();
            break;
        case '4':
            turnFanOff();
            break;
        case '5':
            printf("Enter fan speed (1-5): ");
            scanf(" %c", &fanSpeed);
            setFanSpeed(fanSpeed);
            break;
        default:
            printf("Invalid option!");
    }
    sleep(2); // Wait for 2 seconds to display the output
}

void turnLightOn() {
    printf("Turning light on...\n");
    sleep(2); // Simulate device response time
    printf("Light is now on.\n");
}

void turnLightOff() {
    printf("Turning light off...\n");
    sleep(2); // Simulate device response time
    printf("Light is now off.\n");
}

void turnFanOn() {
    printf("Turning fan on...\n");
    sleep(2); // Simulate device response time
    printf("Fan is now on.\n");
}

void turnFanOff() {
    printf("Turning fan off...\n");
    sleep(2); // Simulate device response time
    printf("Fan is now off.\n");
}

void setFanSpeed(char speed) {
    switch (speed) {
        case FAN_OFF:
            turnFanOff();
            break;
        case FAN_LOW:
            printf("Setting fan speed to low...\n");
            sleep(2); // Simulate device response time
            printf("Fan speed is now low.\n");
            break;
        case FAN_MEDIUM:
            printf("Setting fan speed to medium...\n");
            sleep(2); // Simulate device response time
            printf("Fan speed is now medium.\n");
            break;
        case FAN_HIGH:
            printf("Setting fan speed to high...\n");
            sleep(2); // Simulate device response time
            printf("Fan speed is now high.\n");
            break;
        default:
            printf("Invalid option!");
    }
}