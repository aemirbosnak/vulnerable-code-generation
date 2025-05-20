//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Define the Smart Home Devices */  
typedef struct {
    bool light;
    bool fan;
    bool door; 
} Device;

/* Define the Smart Home Controller */
typedef struct {
    Device device;
    bool connected;
} Controller;

/* Function to turn on the light */
void turn_on_light(Controller* ctrl) {
    ctrl->device.light = true;
    printf("Light turned on.\n");
}

/* Function to turn on the fan */ 
void turn_on_fan(Controller* ctrl) {
    ctrl->device.fan = true;
    printf("Fan turned on.\n");
}

/* Function to open the door */ 
void open_door(Controller* ctrl) {
    ctrl->device.door = true;
    printf("Door opened.\n");
}

/* Function to close the door */ 
void close_door(Controller* ctrl) {
    ctrl->device.door = false;
    printf("Door closed.\n");
}

/* Function to check the status of the devices */ 
void check_status(Controller* ctrl) {
    printf("Light: %s\n", ctrl->device.light ? "On" : "Off");
    printf("Fan: %s\n", ctrl->device.fan ? "On" : "Off");
    printf("Door: %s\n", ctrl->device.door ? "Open" : "Closed");
}

/* Asynchronous function to simulate network delays */
void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

/* Asynchronous function to control the Smart Home */
void smart_home_controller(Controller* ctrl) {
    while(ctrl->connected) {
        delay(2);
        
        if(rand() % 2 == 0) {
            turn_on_light(ctrl);
        }
        if(rand() % 2 == 0) {
            turn_on_fan(ctrl);
        }
        if(rand() % 2 == 0) {
            open_door(ctrl);
        }
        if(rand() % 2 == 0) {
            close_door(ctrl);
        }
        check_status(ctrl);
        
        delay(1);
    }
}

/* Main function to initialize the Smart Home */
int main() {
    srand(time(NULL));
    
    /* Initialize the Smart Home Controller */
    Controller ctrl1 = {{
        .light = false,
        .fan = false,
        .door = false
    }, true};
    
    /* Start the Smart Home Controller */
    smart_home_controller(&ctrl1);
    
    return 0;
}