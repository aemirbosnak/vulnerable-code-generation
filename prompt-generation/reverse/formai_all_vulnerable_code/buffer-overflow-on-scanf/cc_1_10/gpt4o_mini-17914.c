//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

#define PORT "/dev/ttyUSB0"
#define BAUD_RATE B9600

volatile sig_atomic_t stop_signal = 0;

void handle_sigint(int sig) {
    stop_signal = 1;
}

void init_serial(int *serial_port) {
    *serial_port = open(PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (*serial_port == -1) {
        perror("Unable to open serial port");
        exit(EXIT_FAILURE);
    }

    struct termios options;
    tcgetattr(*serial_port, &options);
    cfsetispeed(&options, BAUD_RATE);
    cfsetospeed(&options, BAUD_RATE);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    tcsetattr(*serial_port, TCSANOW, &options);
}

void send_command(int serial_port, const char *command) {
    write(serial_port, command, strlen(command));
}

void receive_response(int serial_port) {
    char buffer[256];
    int nbytes = read(serial_port, buffer, sizeof(buffer) - 1);
    if (nbytes > 0) {
        buffer[nbytes] = '\0';  // Null terminate the string
        printf("Response from drone: %s\n", buffer);
    } else {
        perror("Read failed");
    }
}

void display_menu() {
    printf("\nDrone Remote Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Turn Left\n");
    printf("6. Turn Right\n");
    printf("7. Hover\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int serial_port;
    char command[256];

    signal(SIGINT, handle_sigint);
    
    init_serial(&serial_port);
    
    while (!stop_signal) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sprintf(command, "TAKEOFF\n");
                break;
            case 2:
                sprintf(command, "LAND\n");
                break;
            case 3:
                sprintf(command, "FORWARD\n");
                break;
            case 4:
                sprintf(command, "BACKWARD\n");
                break;
            case 5:
                sprintf(command, "LEFT\n");
                break;
            case 6:
                sprintf(command, "RIGHT\n");
                break;
            case 7:
                sprintf(command, "HOVER\n");
                break;
            case 8:
                printf("Exiting...\n");
                close(serial_port);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option, please try again.\n");
                continue;
        }

        send_command(serial_port, command);
        receive_response(serial_port);
    }

    close(serial_port);
    return 0;
}