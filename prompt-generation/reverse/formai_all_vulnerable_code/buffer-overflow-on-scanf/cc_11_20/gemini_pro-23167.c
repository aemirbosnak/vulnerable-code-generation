//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Define the smart home devices
typedef enum {
    LIGHT,
    FAN,
    AC,
    TV
} device_t;

// Define the smart home device states
typedef enum {
    OFF,
    ON
} device_state_t;

// Define the smart home device commands
typedef enum {
    POWER_ON,
    POWER_OFF,
    SET_TEMPERATURE,
    SET_CHANNEL
} device_command_t;

// Define the smart home device data structure
typedef struct {
    device_t type;
    device_state_t state;
    int value;
} device_data_t;

// Define the smart home network data structure
typedef struct {
    int sockfd;
    struct sockaddr_in servaddr;
} network_data_t;

// Define the smart home control data structure
typedef struct {
    network_data_t network;
    device_data_t devices[4];
} control_data_t;

// Define the smart home control functions
void *control_thread(void *arg);
int send_command(control_data_t *control, device_t device, device_command_t command, int value);

// Main function
int main() {
    // Initialize the smart home control data
    control_data_t control;

    // Initialize the smart home network data
    control.network.sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    control.network.servaddr.sin_family = AF_INET;
    control.network.servaddr.sin_port = htons(5555);
    control.network.servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Initialize the smart home device data
    control.devices[LIGHT] = (device_data_t) { .type = LIGHT, .state = OFF, .value = 0 };
    control.devices[FAN] = (device_data_t) { .type = FAN, .state = OFF, .value = 0 };
    control.devices[AC] = (device_data_t) { .type = AC, .state = OFF, .value = 25 };
    control.devices[TV] = (device_data_t) { .type = TV, .state = OFF, .value = 1 };

    // Create the smart home control thread
    pthread_t thread;
    pthread_create(&thread, NULL, control_thread, &control);

    // Main loop
    while (1) {
        // Get the user input
        char command[100];
        scanf("%s", command);

        // Parse the user input
        char *device = strtok(command, " ");
        char *action = strtok(NULL, " ");
        char *value = strtok(NULL, " ");

        // Convert the device name to an enum
        device_t device_enum;
        if (strcmp(device, "light") == 0) {
            device_enum = LIGHT;
        } else if (strcmp(device, "fan") == 0) {
            device_enum = FAN;
        } else if (strcmp(device, "ac") == 0) {
            device_enum = AC;
        } else if (strcmp(device, "tv") == 0) {
            device_enum = TV;
        } else {
            printf("Invalid device name\n");
            continue;
        }

        // Convert the action name to an enum
        device_command_t action_enum;
        if (strcmp(action, "on") == 0) {
            action_enum = POWER_ON;
        } else if (strcmp(action, "off") == 0) {
            action_enum = POWER_OFF;
        } else if (strcmp(action, "set_temperature") == 0) {
            action_enum = SET_TEMPERATURE;
        } else if (strcmp(action, "set_channel") == 0) {
            action_enum = SET_CHANNEL;
        } else {
            printf("Invalid action name\n");
            continue;
        }

        // Convert the value to an integer
        int value_int;
        if (value != NULL) {
            value_int = atoi(value);
        } else {
            value_int = 0;
        }

        // Send the command to the smart home control thread
        send_command(&control, device_enum, action_enum, value_int);
    }

    // Join the smart home control thread
    pthread_join(thread, NULL);

    // Close the smart home network socket
    close(control.network.sockfd);

    return 0;
}

// Smart home control thread
void *control_thread(void *arg) {
    // Get the smart home control data
    control_data_t *control = (control_data_t *)arg;

    // Main loop
    while (1) {
        // Receive the command from the network
        char command[100];
        recvfrom(control->network.sockfd, command, sizeof(command), 0, (struct sockaddr *)&control->network.servaddr, sizeof(control->network.servaddr));

        // Parse the command
        char *device = strtok(command, " ");
        char *action = strtok(NULL, " ");
        char *value = strtok(NULL, " ");

        // Convert the device name to an enum
        device_t device_enum;
        if (strcmp(device, "light") == 0) {
            device_enum = LIGHT;
        } else if (strcmp(device, "fan") == 0) {
            device_enum = FAN;
        } else if (strcmp(device, "ac") == 0) {
            device_enum = AC;
        } else if (strcmp(device, "tv") == 0) {
            device_enum = TV;
        } else {
            printf("Invalid device name\n");
            continue;
        }

        // Convert the action name to an enum
        device_command_t action_enum;
        if (strcmp(action, "on") == 0) {
            action_enum = POWER_ON;
        } else if (strcmp(action, "off") == 0) {
            action_enum = POWER_OFF;
        } else if (strcmp(action, "set_temperature") == 0) {
            action_enum = SET_TEMPERATURE;
        } else if (strcmp(action, "set_channel") == 0) {
            action_enum = SET_CHANNEL;
        } else {
            printf("Invalid action name\n");
            continue;
        }

        // Convert the value to an integer
        int value_int;
        if (value != NULL) {
            value_int = atoi(value);
        } else {
            value_int = 0;
        }

        // Execute the command
        send_command(control, device_enum, action_enum, value_int);
    }

    return NULL;
}

// Send a command to the smart home control
int send_command(control_data_t *control, device_t device, device_command_t command, int value) {
    // Get the device data
    device_data_t *device_data = &control->devices[device];

    // Execute the command
    switch (command) {
        case POWER_ON:
            device_data->state = ON;
            break;
        case POWER_OFF:
            device_data->state = OFF;
            break;
        case SET_TEMPERATURE:
            device_data->value = value;
            break;
        case SET_CHANNEL:
            device_data->value = value;
            break;
    }

    // Send the command to the network
    char command_string[100];
    sprintf(command_string, "%s %s %d", device_data->type == LIGHT ? "light" : device_data->type == FAN ? "fan" : device_data->type == AC ? "ac" : "tv", command == POWER_ON ? "on" : command == POWER_OFF ? "off" : command == SET_TEMPERATURE ? "set_temperature" : "set_channel", value);
    sendto(control->network.sockfd, command_string, strlen(command_string), 0, (struct sockaddr *)&control->network.servaddr, sizeof(control->network.servaddr));

    return 0;
}