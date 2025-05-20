//FormAI DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>

// list of available devices
struct devices {
    int light_bulb;
    int thermostat;
    int security_system;
} home;

void turn_on_light_bulb() {
    home.light_bulb = 1;
    printf("Light bulb turned on.\n");
}

void turn_off_light_bulb() {
    home.light_bulb = 0;
    printf("Light bulb turned off.\n");
}

void set_thermostat_temperature(int temperature) {
    home.thermostat = temperature;
    printf("Thermostat temperature set to %d degrees.\n", temperature);
}

void arm_security_system() {
    home.security_system = 1;
    printf("Security system armed.\n");

}

void disarm_security_system() {
    home.security_system = 0;
    printf("Security system disarmed.\n");
}

int main() {
    home.light_bulb = 0;
    home.thermostat = 72;
    home.security_system = 0;

    printf("Welcome to your smart home!\n");

    int choice, temperature;

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Turn on the light bulb\n");
        printf("2. Turn off the light bulb\n");
        printf("3. Set the thermostat temperature\n");
        printf("4. Arm the security system\n");
        printf("5. Disarm the security system\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turn_on_light_bulb();
                break;
            case 2:
                turn_off_light_bulb();
                break;
            case 3:
                printf("Enter the desired temperature: ");
                scanf("%d", &temperature);
                set_thermostat_temperature(temperature);
                break;
            case 4:
                arm_security_system();
                break;
            case 5:
                disarm_security_system();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}