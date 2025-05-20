//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LIGHTS 5
#define MAX_TEMP 30
#define MIN_TEMP 15

typedef struct {
    char name[20];
    int is_on;
} Light;

typedef struct {
    int current_temp;
} Thermostat;

typedef struct {
    int alarm_set;
} SecuritySystem;

Light lights[MAX_LIGHTS];
Thermostat thermostat;
SecuritySystem security;

void initialize_system() {
    // Initialize Lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].is_on = 0; // Lights are off by default
    }
    thermostat.current_temp = 20; // Default temperature
    security.alarm_set = 0; // Alarm is off
}

void toggle_light(int index) {
    if (index >= 0 && index < MAX_LIGHTS) {
        lights[index].is_on = !lights[index].is_on;
        printf("%s is now %s.\n", lights[index].name, lights[index].is_on ? "ON" : "OFF");
    } else {
        printf("Invalid Light Selection!\n");
    }
}

void set_temperature(int temp) {
    if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
        thermostat.current_temp = temp;
        printf("Thermostat temperature set to %d degrees Celsius.\n", thermostat.current_temp);
    } else {
        printf("Temperature must be between %d and %d degrees Celsius.\n", MIN_TEMP, MAX_TEMP);
    }
}

void toggle_security() {
    security.alarm_set = !security.alarm_set;
    printf("Security alarm is now %s.\n", security.alarm_set ? "SET" : "DISARMED");
}

void display_status() {
    printf("\n=== Current Home Status ===\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s: %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
    }
    printf("Thermostat: %d degrees Celsius\n", thermostat.current_temp);
    printf("Security Alarm: %s\n", security.alarm_set ? "SET" : "DISARMED");
    printf("===========================\n");
}

void menu() {
    int choice, light_num, temp;

    do {
        printf("\n=== Smart Home Automation ===\n");
        printf("1. Toggle a Light\n");
        printf("2. Set Thermostat Temperature\n");
        printf("3. Toggle Security Alarm\n");
        printf("4. Display Home Status\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Select light number (1-%d): ", MAX_LIGHTS);
                scanf("%d", &light_num);
                toggle_light(light_num - 1);
                break;
            case 2:
                printf("Enter desired temperature (%d to %d): ", MIN_TEMP, MAX_TEMP);
                scanf("%d", &temp);
                set_temperature(temp);
                break;
            case 3:
                toggle_security();
                break;
            case 4:
                display_status();
                break;
            case 5:
                printf("Exiting Smart Home System. Stay cozy!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Smart Home Automation System!\n");
    
    initialize_system();
    
    menu();
    
    return 0;
}