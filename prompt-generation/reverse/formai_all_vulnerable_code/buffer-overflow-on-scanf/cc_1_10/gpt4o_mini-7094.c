//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Device states
int lights_on = 0;
int thermostat_set = 20; // default temperature
int door_locked = 1; // 1 for locked, 0 for unlocked

void show_menu() {
    printf("\n💡 Welcome to Your Smart Home Control Center! 💡\n");
    printf("1. Control Lights\n");
    printf("2. Set Thermostat\n");
    printf("3. Lock/Unlock Door\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void control_lights() {
    if (lights_on) {
        printf("🌙 Turning off the lights!\n");
        lights_on = 0;
    } else {
        printf("🌞 Turning on the lights!\n");
        lights_on = 1;
    }
}

void set_thermostat() {
    int temp;
    printf("Enter desired temperature (15-30): ");
    scanf("%d", &temp);
    if (temp >= 15 && temp <= 30) {
        thermostat_set = temp;
        printf("❄️ Thermostat set to %d°C!\n", thermostat_set);
    } else {
        printf("🚫 Invalid temperature! Please set a temperature between 15 and 30 degrees.\n");
    }
}

void lock_unlock_door() {
    if (door_locked) {
        printf("🔒 Unlocking the door!\n");
        door_locked = 0;
    } else {
        printf("🔐 Locking the door!\n");
        door_locked = 1;
    }
}

int main() {
    int choice;
    
    while (1) {
        show_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                control_lights();
                break;
            case 2:
                set_thermostat();
                break;
            case 3:
                lock_unlock_door();
                break;
            case 4:
                printf("🏡 Exiting Smart Home Control Center. See you next time!\n");
                exit(0);
                break;
            default:
                printf("❗ Invalid choice! Please select a valid option (1-4).\n");
        }
    }
    
    return 0;
}