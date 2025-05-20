//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define DEVICE "/dev/ttyUSB0" // Change this to the appropriate device
#define BUFFER_SIZE 256

// Function to configure serial port settings
int configureSerialPort(int fd) {
    struct termios options;
    tcgetattr(fd, &options);
    options.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;
    tcflush(fd, TCIFLUSH);
    return tcsetattr(fd, TCSANOW, &options);
}

// Function to send command to the drone
void sendCommand(int fd, const char* command) {
    write(fd, command, strlen(command));
}

// Function to receive response from the drone
void receiveResponse(int fd) {
    char buffer[BUFFER_SIZE];
    int n = read(fd, buffer, sizeof(buffer)-1);
    if (n < 0) {
        perror("Error reading from serial port");
    } else {
        buffer[n] = '\0'; // Null-terminate the string
        printf("Drone Response: %s\n", buffer);
    }
}

// Function to print the menu
void printMenu() {
    printf("Drone Remote Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Up\n");
    printf("4. Move Down\n");
    printf("5. Move Forward\n");
    printf("6. Move Backward\n");
    printf("7. Turn Left\n");
    printf("8. Turn Right\n");
    printf("9. Exit\n");
    printf("Choose an option: ");
}

// Function to map user input to drone commands
void handleUserInput(int fd, int choice) {
    switch (choice) {
        case 1:
            sendCommand(fd, "TAKEOFF\n");
            printf("Command sent: TAKEOFF\n");
            break;
        case 2:
            sendCommand(fd, "LAND\n");
            printf("Command sent: LAND\n");
            break;
        case 3:
            sendCommand(fd, "UP\n");
            printf("Command sent: UP\n");
            break;
        case 4:
            sendCommand(fd, "DOWN\n");
            printf("Command sent: DOWN\n");
            break;
        case 5:
            sendCommand(fd, "FORWARD\n");
            printf("Command sent: FORWARD\n");
            break;
        case 6:
            sendCommand(fd, "BACKWARD\n");
            printf("Command sent: BACKWARD\n");
            break;
        case 7:
            sendCommand(fd, "LEFT\n");
            printf("Command sent: LEFT\n");
            break;
        case 8:
            sendCommand(fd, "RIGHT\n");
            printf("Command sent: RIGHT\n");
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
            break;
    }
    receiveResponse(fd);
}

int main() {
    int serialPort = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serialPort == -1) {
        perror("Unable to open serial port");
        return EXIT_FAILURE;
    }

    if (configureSerialPort(serialPort) != 0) {
        perror("Unable to configure serial port");
        close(serialPort);
        return EXIT_FAILURE;
    }

    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        handleUserInput(serialPort, choice);
    }

    close(serialPort);
    return 0;
}