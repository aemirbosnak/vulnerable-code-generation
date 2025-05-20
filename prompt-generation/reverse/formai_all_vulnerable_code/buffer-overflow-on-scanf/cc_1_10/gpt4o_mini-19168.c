//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0
#define HEATING_ON 1
#define HEATING_OFF 0
#define DOOR_OPEN 1
#define DOOR_CLOSED 0

typedef struct {
    int light;
    int heating;
    int door;
} SmartHome;

void displayStatus(SmartHome *home) {
    printf("---- Smart Home Status ----\n");
    printf("Lights: %s\n", home->light == LIGHT_ON ? "On" : "Off");
    printf("Heating: %s\n", home->heating == HEATING_ON ? "On" : "Off");
    printf("Door: %s\n", home->door == DOOR_OPEN ? "Open" : "Closed");
    printf("--------------------------\n");
}

void toggleLight(SmartHome *home) {
    home->light = (home->light == LIGHT_ON) ? LIGHT_OFF : LIGHT_ON;
    printf("Lights turned %s.\n", home->light == LIGHT_ON ? "On" : "Off");
}

void toggleHeating(SmartHome *home) {
    home->heating = (home->heating == HEATING_ON) ? HEATING_OFF : HEATING_ON;
    printf("Heating turned %s.\n", home->heating == HEATING_ON ? "On" : "Off");
}

void toggleDoor(SmartHome *home) {
    home->door = (home->door == DOOR_OPEN) ? DOOR_CLOSED : DOOR_OPEN;
    printf("Door is now %s.\n", home->door == DOOR_OPEN ? "Open" : "Closed");
}

void morningRoutine(SmartHome *home) {
    printf("Executing morning routine...\n");
    home->light = LIGHT_ON;
    home->heating = HEATING_ON;
    displayStatus(home);
}

void eveningRoutine(SmartHome *home) {
    printf("Executing evening routine...\n");
    home->light = LIGHT_OFF;
    home->heating = HEATING_OFF;
    displayStatus(home);
}

void ambientLightControl(SmartHome *home) {
    printf("Adjusting ambient light...\n");
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);
    
    if (tm_info->tm_hour < 6 || tm_info->tm_hour > 20) {
        home->light = LIGHT_ON;
        printf("It’s dark outside, turning lights On.\n");
    } else {
        home->light = LIGHT_OFF;
        printf("Daylight detected, turning lights Off.\n");
    }
}

void securityCheck(SmartHome *home) {
    printf("Performing security check...\n");
    if (home->door == DOOR_OPEN) {
        printf("Warning: The door is open! Locking it now...\n");
        home->door = DOOR_CLOSED;
    }
}

int main() {
    SmartHome myHome = {LIGHT_OFF, HEATING_OFF, DOOR_CLOSED};

    displayStatus(&myHome);

    char command[50];
    while (1) {
        printf("\nEnter a command (toggle_light, toggle_heating, toggle_door, morning_routine, evening_routine, ambient_light, security_check, quit): ");
        scanf("%s", command);
        
        if (strcmp(command, "toggle_light") == 0) {
            toggleLight(&myHome);
        } else if (strcmp(command, "toggle_heating") == 0) {
            toggleHeating(&myHome);
        } else if (strcmp(command, "toggle_door") == 0) {
            toggleDoor(&myHome);
        } else if (strcmp(command, "morning_routine") == 0) {
            morningRoutine(&myHome);
        } else if (strcmp(command, "evening_routine") == 0) {
            eveningRoutine(&myHome);
        } else if (strcmp(command, "ambient_light") == 0) {
            ambientLightControl(&myHome);
        } else if (strcmp(command, "security_check") == 0) {
            securityCheck(&myHome);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting Smart Home Automation Program. Goodbye!\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
        
        displayStatus(&myHome);
        sleep(1);
    }

    return 0;
}