//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 10

typedef struct {
    char name[30];
    int status; // 0 for OFF, 1 for ON
} Device;

Device lights[MAX_DEVICES];
Device thermostat;
Device coffeeMaker;

void initializeDevices();
void displayMenu();
void toggleLight();
void setTemperature();
void brewCoffee();

int main() {
    srand(time(0)); 
    initializeDevices();

    int choice;
    do {
        displayMenu();
        printf("Please enter your choice (1-4, or 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: toggleLight(); break;
            case 2: setTemperature(); break;
            case 3: brewCoffee(); break;
            case 4: printf("You are on a roll! Let's keep the home cozy!\n"); break;
            case 0: printf("Exiting the smart home. Stay cozy and keep smiling!\n"); break;
            default: printf("Oops! That’s not a valid choice. Try again!\n"); break;
        }
    } while (choice != 0);

    return 0;
}

void initializeDevices() {
    strcpy(lights[0].name, "Living Room Light");
    strcpy(lights[1].name, "Kitchen Light");
    strcpy(lights[2].name, "Bedroom Light");
    
    for (int i = 0; i < 3; i++) {
        lights[i].status = 0; // All lights are OFF initially
    }

    strcpy(thermostat.name, "Thermostat");
    thermostat.status = 0; // OFF

    strcpy(coffeeMaker.name, "Coffee Maker");
    coffeeMaker.status = 0; // OFF

    printf("Welcome to your cheerfully automated home!\n");
}

void displayMenu() {
    printf("\n***** Smart Home Automation Menu *****\n");
    printf("1. Toggle Lights\n");
    printf("2. Set Temperature\n");
    printf("3. Brew Coffee\n");
    printf("4. Just checking the mood!\n");
    printf("0. Exit\n");
}

void toggleLight() {
    for (int i = 0; i < 3; i++) {
        lights[i].status = !lights[i].status;  // Toggle light status
        printf("%s is now %s! Shine bright like a diamond!\n",
               lights[i].name, lights[i].status ? "ON" : "OFF");
    }
}

void setTemperature() {
    int newTemp;
    printf("Enter desired temperature (in degrees Celsius): ");
    scanf("%d", &newTemp);
    thermostat.status = newTemp; // Set new temperature
    printf("Temperature has been set to %d°C! Your cozy castle awaits!\n", thermostat.status);
}

void brewCoffee() {
    if (coffeeMaker.status == 1) {
        printf("The coffee maker is already brewing!\n");
    } else {
        coffeeMaker.status = 1; // Turn ON coffee maker
        printf("Brewing a hot cup of coffee! ☕ Enjoy the aroma of happiness!\n");
        // Simulate brewing time
        printf("Brewing...\n");
        sleep(3);
        coffeeMaker.status = 0; // Turn OFF after brewing
        printf("Your coffee is ready! Drink up and seize the day!\n");
    }
}