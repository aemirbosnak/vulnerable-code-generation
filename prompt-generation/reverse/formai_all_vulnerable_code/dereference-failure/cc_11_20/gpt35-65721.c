//FormAI DATASET v1.0 Category: Smart home automation ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to validate the input for device type selection
int validate_type_selection(char *selection) {
    if(strlen(selection) == 1) {
        if(isdigit(selection[0])) {
            int type = atoi(selection);
            if(type >= 1 && type <= 3) {
                return type;
            }
            else {
                printf("Invalid input! Select a valid device type.\n");
                return 0;
            }
        }
        else {
            printf("Invalid input! Select a valid device type.\n");
            return 0;
        }
    }
    else {
        printf("Invalid input! Select a valid device type.\n");
        return 0;
    }
}

// Function to validate the input for device status selection
int validate_status_selection(char *selection) {
    if(strlen(selection) == 1) {
        if(isdigit(selection[0])) {
            int status = atoi(selection);
            if(status >= 1 && status <= 2) {
                return status;
            }
            else {
                printf("Invalid input! Select a valid device status.\n");
                return 0;
            }
        }
        else {
            printf("Invalid input! Select a valid device status.\n");
            return 0;
        }
    }
    else {
        printf("Invalid input! Select a valid device status.\n");
        return 0;
    }
}

int main() {
    int no_of_lights = 3, no_of_fans = 2, no_of_doors = 1;  // Total number of devices in the house
    int device_type, device_id, device_status;

    // Arrays to hold device status information
    int light_status[3] = {0, 0, 0}; // 0 -> OFF, 1 -> ON
    int fan_status[2] = {0, 0};
    int door_status[1] = {0};

    char user_input[20];
    char *token;

    while(1) {
        printf("Please enter your command: ");
        fgets(user_input, 20, stdin);
        token = strtok(user_input, " ");

        if(strcmp(token, "exit\n") == 0) {
            printf("Exiting the program...\n");
            break;
        }
        else if(strcmp(token, "show") == 0) {
            token = strtok(NULL, " ");
            if(token != NULL) {
                device_type = validate_type_selection(token);
                if(device_type == 1) { // Display light status
                    for(int i=0; i<no_of_lights; i++) {
                        printf("Light %d: %s\n", i+1, light_status[i] ? "ON" : "OFF");
                    }
                }
                else if(device_type == 2) { // Display fan status
                    for(int i=0; i<no_of_fans; i++) {
                        printf("Fan %d: %s\n", i+1, fan_status[i] ? "ON" : "OFF");
                    }
                }
                else if(device_type == 3) { // Display door status
                    printf("Door: %s\n", door_status[0] ? "OPEN" : "CLOSED");
                }
            }
            else { // Show all device status
                for(int i=0; i<no_of_lights; i++) {
                    printf("Light %d: %s\n", i+1, light_status[i] ? "ON" : "OFF");
                }
                for(int i=0; i<no_of_fans; i++) {
                    printf("Fan %d: %s\n", i+1, fan_status[i] ? "ON" : "OFF");
                }
                printf("Door: %s\n", door_status[0] ? "OPEN" : "CLOSED");
            }
        }
        else if(strcmp(token, "turn") == 0) {
            token = strtok(NULL, " ");
            if(token != NULL) {
                device_type = validate_type_selection(token);
                token = strtok(NULL, " ");
                if(token != NULL) {
                    device_id = atoi(token); // device_id will always be a single digit
                    token = strtok(NULL, " ");
                    if(token != NULL) {
                        device_status = validate_status_selection(token);
                        if(device_status != 0) {
                            // Valid command, update device status
                            if(device_type == 1) { // Light
                                light_status[device_id-1] = device_status-1;
                                printf("Light %d is now turned %s.\n", device_id, device_status == 1 ? "ON" : "OFF");
                            }
                            else if(device_type == 2) { // Fan
                                fan_status[device_id-1] = device_status-1;
                                printf("Fan %d is now turned %s.\n", device_id, device_status == 1 ? "ON" : "OFF");
                            }
                            else if(device_type == 3) { // Door
                                door_status[0] = device_status-1;
                                printf("Door is now turned %s.\n", device_status == 1 ? "OPEN" : "CLOSED");
                            }
                        }
                    }
                }
            }
        }
        else {
            printf("Invalid command! Try again.\n");
        }
    }

    return 0;
}