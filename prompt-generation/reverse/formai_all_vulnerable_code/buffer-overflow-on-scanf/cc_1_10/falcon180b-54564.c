//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUD_RATE B9600
#define MAX_COMMAND_LENGTH 20

// Function to initialize serial communication
void init_serial_communication(int fd) {
    struct termios options;
    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUD_RATE | CS8 | CREAD | CLOCAL;
    tcsetattr(fd, TCSANOW, &options);
}

// Function to send command to smart home device
void send_command(int fd, char* command) {
    write(fd, command, strlen(command));
    write(fd, "\r", 1);
}

// Function to receive response from smart home device
char* receive_response(int fd) {
    char response[MAX_COMMAND_LENGTH];
    memset(response, 0, sizeof(response));
    int bytes_received = read(fd, response, sizeof(response));
    response[bytes_received - 1] = '\0';
    return response;
}

// Function to turn on/off light
void control_light(int fd, bool on) {
    char command[MAX_COMMAND_LENGTH];
    if (on) {
        strcpy(command, "LIGHT ON\r");
    } else {
        strcpy(command, "LIGHT OFF\r");
    }
    send_command(fd, command);
    char* response = receive_response(fd);
    printf("Light status: %s\n", response);
}

// Function to adjust thermostat temperature
void control_thermostat(int fd, int temperature) {
    char command[MAX_COMMAND_LENGTH];
    sprintf(command, "THERMOSTAT %d\r", temperature);
    send_command(fd, command);
    char* response = receive_response(fd);
    printf("Thermostat temperature: %s\n", response);
}

int main() {
    int fd;
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        exit(1);
    }
    init_serial_communication(fd);
    while (1) {
        printf("Enter command (LIGHT ON/OFF, THERMOSTAT temperature): ");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);
        if (strcmp(command, "LIGHT ON") == 0) {
            control_light(fd, true);
        } else if (strcmp(command, "LIGHT OFF") == 0) {
            control_light(fd, false);
        } else if (strcmp(command, "THERMOSTAT") == 0) {
            printf("Enter thermostat temperature: ");
            int temperature;
            scanf("%d", &temperature);
            control_thermostat(fd, temperature);
        } else {
            printf("Invalid command\n");
        }
    }
    close(fd);
    return 0;
}